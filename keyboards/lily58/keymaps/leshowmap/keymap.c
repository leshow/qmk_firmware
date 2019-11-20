#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define ARROW 2 // mouse keys
#define MOUSE 3  // directional + nav
#define MEDIA 4  // volume + playback
#define NUM 5   // NUM LAYER
#define ADJUST 6 // adjustment layer 

enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Del/4 |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Tb/GUI|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | '/GUI|
 * |------+------+------+------+------+------| Enc   |    | Rofi  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Term | LCTL |  NUM | / Bk/1  /       \ Sp/1 \  |Ent/SG| Esc/6| TAB  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [BASE] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  LT(MEDIA, KC_DEL), KC_Q, KC_W, KC_E, KC_R, KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  GUI_T(KC_TAB), KC_A, KC_S, KC_D, LT(ARROW,KC_F), KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, GUI_T(KC_QUOT), \
  KC_LSPO, LCTL_T(KC_Z), LALT_T(KC_X), KC_C, LT(MOUSE, KC_V), KC_B, KC_AUDIO_MUTE,    LGUI(KC_X),    KC_N, KC_M, KC_COMM, RALT_T(KC_DOT), RCTL_T(KC_SLSH), KC_RSPC, \
        LGUI(KC_ENT), LCTL_T(KC_ESC), MO(NUM), LT(SYMB, KC_BSPC),       LT(SYMB, KC_SPC), SGUI_T(KC_ENT),   LT(ADJUST, KC_ESC), KC_TAB \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ?  |   ^  |   %  |   #  |   *  |                    |   =  |   {  |   }  |   @  |   !  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   \  |   &  |   [  |   ]  |   -  |-------.    ,-------|   _  |   (  |   )  |   $  |   :  |   "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   '  |   ,  |   .  |   `  |  +   |-------|    |-------|   ~  |   |  |   <  |   >  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[SYMB] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
   _______, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,                      KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT, KC_EXLM, _______, \
 _______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,               KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR, KC_COLN, KC_DQUO, \
  _______, KC_QUOT,  KC_COMMA,  KC_DOT,  KC_GRAVE,  KC_PLUS,  _______, _______, KC_TILD, KC_PIPE, KC_LABK, KC_RABK, KC_SLASH, _______, \
                             _______, _______, _______, KC_SPC, KC_SPC,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |   F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[ARROW] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,                                _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  _______, \
   _______, _______, _______, _______, _______, _______,                                _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, \
   _______, _______, _______, _______, _______, _______, _______,           _______, KC_INS, KC_CAPSLOCK, _______, _______, _______, _______,  \
                             _______, _______, _______,  _______,                       _______,  _______, _______, _______ \
),

[MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,                               _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, \
  _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______,                                _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, \
   _______, _______, _______, _______, _______, _______,        _______, _______,        _______, _______, _______, _______, _______, _______, \
                             _______, _______,  _______, KC_BTN2,                           KC_BTN1, KC_BTN3, _______, _______ \
),

[MEDIA] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
   _______,  KC_F1,    KC_F2,    KC_F3,   KC_F4,     KC_F5,                                   KC_F6,     KC_F7,     KC_F8,    KC_F9,  KC_F10,  _______, \
     _______, _______, _______, _______, _______, KC_F11,                                KC_F12, KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, \
   _______, _______, _______, _______, _______, _______,        _______, _______,      _______, _______, _______, _______, _______, KC_AUDIO_MUTE,  \
                             _______, _______, _______,  _______,                        _______, KC_VOLD, KC_VOLU, _______ \
),

[NUM] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
   _______, KC_QUES, KC_CIRC, KC_PERC,   KC_HASH,  KC_ASTR,                              KC_EQUAL,   KC_7,    KC_8,    KC_9,    KC_EXLM, _______, \
   _______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,                      KC_UNDS,   KC_4,    KC_5,     KC_6,  _______, _______,  \
    _______, KC_QUOT, KC_COMMA, KC_DOT, KC_GRAVE, KC_PLUS,      _______, _______,       KC_0,     KC_1,    KC_2,     KC_3,  _______, _______,\
                             _______, _______, _______,  _______,                       _______, KC_0, _______, _______ \
),

[ADJUST] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, \
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,                                  KC_NO, KC_NO, KC_NO, RGB_M_G, RGB_M_SN, RGB_M_B, \
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO,        _______, _______,         KC_NO, KC_NO, KC_NO, RGB_M_X, RGB_M_SW, RGB_M_R, \
                             _______, _______, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_NO, _______ \
)
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) { 
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
   }
}
