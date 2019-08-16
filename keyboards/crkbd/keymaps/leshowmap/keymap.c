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
#define KC_GUITQ GUI_T(KC_QUOT)
#define KC_GUITB GUI_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_CTLZ CTL_T(KC_Z)
#define KC_CTLSLSH CTL_T(KC_SLSH)
#define KC_TTMDA TT(MDIA)
#define KC_ALTX ALT_T(KC_X)
#define KC_ALTDOT ALT_T(KC_DOT)
#define KC_MONUM MO(NUM)
#define KC_SYMBSP LT(SYMB, KC_SPC)
#define KC_SYMBBSP LT(SYMB, KC_BSPC)
#define KC_SFTE LT(ADJUST, KC_ENT)
#define KC_SFTD SFT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TTMDA,    Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       GUITB,   A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  GUITQ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        LSPO,   CTLZ, ALTX,  C,    V,      B,                      N,     M,    COMM,   ALTDOT,  CTLSLSH, RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                         MONUM,  SYMBBSP,  SFTD,                     SFTE, SYMBSP, ESC \
                              //`--------------------'  `--------------------'
  ),

  [_SYMB] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, QUES, CIRC, PERC, HASH, ASTR,                  EQUAL, LCBR, RCBR, AT, EXLM, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, BSLASH, AMPR, LBRACKET, RBRACKET, MINUS,           UNDS, LPRN, RPRN, DLR, COLN, DQUO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, QUOT,  COMMA,  DOT,  GRAVE,  PLUS,                TILD, PIPE, LABK, RABK, SLASH, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 _____, SPC, _____,      _____, SPC, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_NUMB] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
    _____, _____, _____, _____, _____, _____,            _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _____, MS_ACCEL0, MS_ACCEL1, MS_ACCEL2, _____, _____,    _____, MS_LEFT, MS_DOWN, MS_UP, MS_RIGHT, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _____, _____, _____, _____, _____, _____,             _____, _____, _____, _____, _____, _____, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              _____, _____, _____,     _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_ARRW] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
_____, _____, _____, _____, _____, _____,                 _____, HOME, PGDOWN, PGUP, END,  _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_____, _____, _____, _____, _____, _____,                  _____, LEFT, DOWN, UP, RIGHT, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_____, _____, _____, _____, _____, _____,                 _____, _____, _____, _____, _____, _____, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               _____, _____, _____,     _____, _____, _____\
                              //`--------------------'  `--------------------'
  ),

    [_MDIA] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
     _____,  F1,    F2,    F3,   F4,     F5,                    F6,     F7,     F8,    F9,  F10,  _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _____, _____, _____, _____, _____, F11,                F12, MEDIA_PREV_TRACK, MEDIA_STOP, MEDIA_PLAY_PAUSE, MEDIA_NEXT_TRACK, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _____, _____, _____, _____, _____, _____,            _____, _____, _____, _____, _____, AUDIO_MUTE, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                       _____, _____, MEDIA_STOP,     MEDIA_PLAY_PAUSE, VOLD, VOLU \
                              //`--------------------'  `--------------------'
  ),

    [_NUM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, QUES, CIRC, PERC,   HASH,  ASTR,                   EQUAL,   7,    8,    9,    EXLM, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, BSLASH, AMPR, LBRACKET, RBRACKET, MINUS,            UNDS,   4,    5,     6,    _____, _____, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, QUOT, COMMA, DOT, GRAVE, PLUS,                      DOT,     1,    2,     3,    _____, _____, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               _____, _____, _____,     _____, _____, 0 \
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
                           _____, _____, _____,      _____, _____, _____ \
    )
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
    // case SYMB:
    //   if (record->event.pressed) {
    //     layer_on(_SYMB);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_SYMB);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case NUMB:
    //   if (record->event.pressed) {
    //     layer_on(_NUMB);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_NUMB);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case ADJUST:
    //     if (record->event.pressed) {
    //       layer_on(_ADJUST);
    //     } else {
    //       layer_off(_ADJUST);
    //     }
    //     return false;
    //     break;
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
