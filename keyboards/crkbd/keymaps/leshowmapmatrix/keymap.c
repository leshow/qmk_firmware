#include QMK_KEYBOARD_H
#include "split_util.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// layer keys
#define NUM MO(_NUM)
#define ARROW LT(_ARROW, KC_F)
#define MOUSE LT(_MOUSE, KC_V)
#define S_SPC LT(_SYMB, KC_SPC)
#define S_BSPC LT(_SYMB, KC_BSPC)
#define MEDIA LT(_MEDIA, KC_DEL)
#define ADJUST LT(_ADJUST, KC_ESC)
// i3
#define GQUOT GUI_T(KC_QUOT)
#define GTAB GUI_T(KC_TAB)
#define SGENT SGUI_T(KC_ENT)
// mods
#define LCTLZ LCTL_T(KC_Z)
#define RCTLS LCTL_T(KC_SLSH)
#define RALTD RALT_T(KC_DOT)
#define LALTX LALT_T(KC_X)
#define ESC_CTL LCTL_T(KC_ESC)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
  _DEFAULT,
  _SYMB,
  _ARROW,
  _MOUSE,
  _MEDIA,
  _NUM,
  _ADJUST
};
 // -- CONSIDER KC_SFTENT in place of RSPC??
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( \
 //,-----------------------------------------.                ,-----------------------------------------.
     MEDIA, KC_Q, KC_W, KC_E, KC_R, KC_T,                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      GTAB, KC_A, KC_S, KC_D, ARROW, KC_G,                        KC_H, KC_J, KC_K, KC_L, KC_SCLN, GQUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSPO, LCTLZ, LALTX, KC_C, MOUSE, KC_B,                 KC_N, KC_M, KC_COMM, RALTD, RCTLS, KC_RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                ESC_CTL, NUM, S_BSPC,    S_SPC,  SGENT, ADJUST \
                             //`-----------------------'  `----------------------'
  ),


  [_SYMB] = LAYOUT( \
 //,-----------------------------------------.                ,-----------------------------------------.
      _______, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,                  KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT, KC_EXLM, _______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,           KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR, KC_COLN, KC_DQUO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _______, KC_QUOT,  KC_COMMA,  KC_DOT,  KC_GRAVE,  KC_PLUS,                KC_TILD, KC_PIPE, KC_LABK, KC_RABK, KC_SLASH, _______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                          _______,  _______, KC_SPC,      KC_SPC, _______, _______ \
                              //`--------------------'  `--------------------'
  ),

  [_ARROW] = LAYOUT( \
 //,-----------------------------------------.                ,-----------------------------------------.
    _______, _______, _______, _______, _______, _______,                 _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  _______, \
    //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, _______, _______, _______, _______, _______,                  _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, \
    //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, _______, _______, _______, _______, _______,                 KC_INS, KC_CAPSLOCK, _______, _______, _______, _______, \
    //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______, _______, _______,     _______, _______, _______\
                             //`-----------------------'  `----------------------'
  ),

  [_MOUSE] = LAYOUT( \
 //,-----------------------------------------.                ,-----------------------------------------.
    _______, _______, _______, _______, _______, _______,            _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______,    _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                             _______,  _______, KC_BTN2,             KC_BTN1, KC_BTN3, _______  \
                             //`-----------------------'  `----------------------'
  ),
  


  [_MEDIA] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    _______,KC_F1,KC_F2, KC_F3, KC_F4, KC_F5,                  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  _______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_______, _______, _______, _______, _______, KC_F11,      KC_F12, KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_AUDIO_MUTE, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                       _______, _______, _______,                    _______, KC_VOLD, KC_VOLU \
                             //`-----------------------'  `----------------------'
  ),



  [_NUM] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
  _______, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,        KC_EQUAL,KC_7, KC_8,  KC_9, KC_EXLM, _______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_______, KC_BSLASH, KC_AMPR, KC_LBRACKET, KC_RBRACKET, KC_MINUS,  KC_UNDS, KC_4, KC_5, KC_6, KC_COLN, _______, \
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
_______, KC_QUOT, KC_COMMA, KC_DOT, KC_GRAVE, KC_PLUS,     KC_0, KC_1, KC_2, KC_3, _______, _______, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               _______, _______, _______,     _______, KC_0, _______ \
                             //`-----------------------'  `----------------------'
  ),



  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,                 EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_T,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                             KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO \
  )
};

// uint32_t layer_state_set_user(uint32_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

#ifdef OLED_DRIVER_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!isLeftHand)
    // return OLED_ROTATION_180;  // flips the display 180 to see it from my side
//   return rotation;
// }

const char *read_logo(void);
void oled_task_user(void){
    switch (biton32(layer_state)){
        case _DEFAULT:
            oled_write_ln_P(PSTR("DEFAULT"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("SYMBOL"), false);
            break;
        case _ARROW:
            oled_write_ln_P(PSTR("ARROW"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("MOUSE"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("MEDIA"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
  //now print logo
  oled_write(read_logo(), false);
}
#endif
