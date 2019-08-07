#include QMK_KEYBOARD_H
#include "bootloader.h"
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYMB 1
#define _NUMB 2
#define _ARRW 3
#define _MDIA 4
#define _NUM 5
#define _ADJUST 6

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NUMB,
  ARRW,
  MDIA,
  NUM,
  ADJUST,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_SYMB SYMB
#define KC_ARRW ARRW
#define KC_MDIA MDIA
#define KC_NUM NUM
#define KC_NUMB NUMB
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
    TT(MDIA),    Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
GUI_T(KC_TAB),   A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  GUI_T(KC_QUOT),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 KC_LSPO,CTL_T(KC_Z),ALT_T(KC_X),  C,  V,  B,                        N,     M,  COMM, ALT_T(KC_DOT),CTL_T(KC_SLSH),KC_RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
       MO(NUM),  LT(SYMB, KC_BSPC),  SFT_T(KC_DEL),       SFT_T(KC_ENT), LT(SYMB, KC_SPC), KC_ESC \
                              //`--------------------'  `--------------------'
  ),

  [_SYMB] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
______, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,         KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT, KC_EXLM, ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,      KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR, KC_COLN, KC_DQUO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, KC_QUOT, KC_COMMA, KC_DOT, KC_GRAVE, KC_PLUS,                KC_TILD, KC_PIPE, KC_LABK, KC_RABK, KC_SLASH, ______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                             ______, SPC, ______,      ______, SPC, ______ \
                              //`--------------------'  `--------------------'
  ),

  [_NUMB] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
______, ______, ______, ______, ______, ______,                ______, ______, ______, ______, ______, ______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, ______, ______,            ______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, ______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, ______, ______, ______, ______, ______,                   ______, ______, ______, ______, ______, ______, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              ______, ______, ______,     ______, ______, ______ \
                              //`--------------------'  `--------------------'
  ),

  [_ARRW] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
______, ______, ______, ______, ______, ______,                 ______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, ______, ______, ______, ______, ______,                  ______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, ______, ______, ______, ______, ______,                 ______, ______, ______, ______, ______, ______, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               ______, ______, ______,     ______, ______, ______\
                              //`--------------------'  `--------------------'
  ),

    [_MDIA] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
______, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, ______, ______, ______, ______, KC_F11,               KC_F12, KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, ______, ______, ______, ______, ______,                 ______, ______, ______, ______, ______, KC_AUDIO_MUTE, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                       ______, ______, KC_MEDIA_STOP,     KC_MEDIA_PLAY_PAUSE, _KC_VOLD, KC_VOLU \
                              //`--------------------'  `--------------------'
  ),

    [_NUM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
______, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,             KC_EQUAL, KC_7, KC_8, KC_9, KC_EXLM, ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,  KC_UNDS, KC_4, KC_5, KC_6, _______, ______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
______, KC_QUOT, KC_COMMA, KC_DOT, KC_GRAVE, KC_PLUS,            KC_DOT, KC_1, KC_2, KC_3, _______, ______, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               ______, ______, ______,     ______, ______, KC_0 \
                              //`--------------------'  `--------------------'
  ),

    [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  XXXXX, LOWER,   SPC,      ENT, RAISE, XXXXX 
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

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
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMB:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
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
