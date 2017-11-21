#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define NUMSE 2 // mouse keys
#define ARRW 3  // directional + nav
#define MDIA 4  // volume + playback
#define MOUSE 5 // Mouse layer 2

enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

// macros
#define LAUNCH_TERM 2
#define LAUNCH_ROFI 3
// enum custom_macros
// {
//   LAUNC_TERM,
//   LAUNC_ROFI,
//   // LCTL_LSFT_L3
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TT4   |   1  |   2  |   3  |   4  |   5  |  ESC |           | ESC  |   6  |   7  |   8  |   9  |   0  |  TT4   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | TERM |           |  RFI |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab/Cmd|   A  |   S  |   D  | F/L3 |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   | '/ Cmd | // TODO: think about using ; as the L1 toggle
 * |--------+------+------+------+------+------| SCMD |           | SCMD |------+------+------+------+------+--------|
 * | (/LShf |Z/Ctrl|   X  |   C  |   V  | B/L2 | /cap |           | /cap |   N  |   M  |   ,  | ./Alt| //Ctl| RShft/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CSL3 |  Alt | Down |  Up  | Ctrl |                                       |  <-  | Down |  up  |  ->  | CSL3 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  | Caps |       | AltGr| RCtrl|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VolM |       | Vol+ |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 | /L1  | /Shft| Pl/Ps|       | Vol- | /Shift | /L1  |
 *                                 `--------------------'       `----------------------'
 */

    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = LAYOUT_ergodox( // layer 0 : default
        TT(4), KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,
        KC_DELETE, KC_Q, KC_W, KC_E, KC_R, KC_T, M(LAUNCH_TERM),
        GUI_T(KC_TAB), KC_A, KC_S, KC_D, LT(3, KC_F), KC_G,
        KC_LSPO, CTL_T(KC_Z), KC_X, KC_C, KC_V, LT(2, KC_B), SCMD_T(KC_CAPSLOCK),
        MEH_T(KC_NO), KC_LALT, KC_DOWN, KC_UP, KC_LCTL,
        // thumb
        KC_INSERT, KC_CAPSLOCK, KC_AUDIO_MUTE, LT(1, KC_BSPC), SFT_T(KC_DEL), KC_MEDIA_PLAY_PAUSE,
        // right hand
        KC_ESC, KC_6, KC_7, KC_8, KC_9, KC_0, TT(4),
        M(LAUNCH_ROFI), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, GUI_T(KC_QUOTE),
        SCMD_T(KC_CAPSLOCK), KC_N, KC_M, KC_COMMA, ALT_T(KC_DOT), CTL_T(KC_SLASH), KC_RSPC,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, MEH_T(KC_NO),
        // thumb
        KC_LALT, KC_RCTRL, KC_VOLU, KC_VOLD, SFT_T(KC_ENTER), LT(1, KC_SPACE)),
    /* MINE Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   ?  |   ^  |   #  |   %  |   *  |      |           |      |   =  |   {  |   }  |   @  |   !  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   \  |   &  |   ]  |   [  |   -  |------|           |------|   _  |   (  |   )  |   $  |   :  |    "   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  '   |   ,  |   .  |   `  |   +  |      |           |      |   ~  |   |  |   <  |   >  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | *L1* |      |------|       |------|      | *L1* |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

    // SYMBOLS
    [SYMB] = LAYOUT_ergodox(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11,
        KC_TRNS, KC_QUES, KC_CIRC, KC_HASH, KC_PERC, KC_ASTR, KC_TRNS,
        KC_TRNS, KC_BSLASH, KC_AMPR, KC_RBRACKET, KC_LBRACKET, KC_MINUS,
        KC_TRNS, KC_QUOT, KC_COMMA, KC_DOT, KC_GRAVE, KC_PLUS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // thumb
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, // added here
        // right hand
        KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
        KC_TRNS, KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT, KC_EXLM, KC_TRNS,
        KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR, KC_COLN, KC_DQUO,
        KC_TRNS, KC_TILD, KC_PIPE, KC_LABK, KC_RABK, KC_SLASH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //thumb
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* MINE Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Reset  |      |      |      |      |      | NumLk|           |      |      |      |      |      |      | Reset  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | WLft | WDwn | WUp  | WRght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |Accel0|Accel1|Accel2|      |------|           |------|      | MLft | MDwn | MUp  | MRght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |     |       |                                       |MidClk|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| RClk | LClk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

    // MEDIA AND MOUSE
    [NUMSE] = LAYOUT_ergodox(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUMLOCK,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // thumb
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, // added here
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS,
        KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //thumb
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN2, KC_MS_BTN1),
    /* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Home  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | home | pgup | pgdwn| end  |  PgUp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | *L3* |      |------|           |------|      |  <-  | Dwn  | Up   | ->   | PgDwn  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  End   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [ARRW] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            //thumb
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            // right hand
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDOWN, KC_END, KC_PGUP,
                            KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDOWN,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            //thumb
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Keymap 4: Media and mouse keys
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* | *TT4*  |      |      |      |      |      |      |           |      |      |      |      |      |      | *TT4*  |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | Mute | Rev  | Stop | Play | FF   |                                       | Prev | VDwn | VUp  | Nxt  | Mute  |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 | Prev | Next |------|       |------| Stop | PL/P |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
    [MDIA] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_AUDIO_MUTE, KC_MEDIA_REWIND, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD,
                            // thumb
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS,
                            //right
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_MEDIA_PREV_TRACK, KC_VOLD, KC_VOLU, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE,
                            //thumb
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE),

    /* Keymap 5: Mouse 2
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |  WL  |  WD  |  WU  |  WR  |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        | MLeft| MDwn |  Mup | MRht |      |------|           |------|      |      |      |      | *L5* |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      | MCLK |                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 | LCLK | RCLK |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
    [MOUSE] = LAYOUT_ergodox(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN3,
                             // thumb
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_TRNS,
                             //right
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             //thumb
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),  // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(NUMSE), // FN1 - Momentary Layer 1 (Symbols)
    [3] = ACTION_LAYER_TAP_TOGGLE(ARRW),  // FN1 - Momentary Layer 1 (Symbols)
    [4] = ACTION_LAYER_TAP_TOGGLE(MDIA),  // FN1 - Momentary Layer 1 (Symbols)
    [5] = ACTION_LAYER_TAP_TOGGLE(MOUSE)};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
  case 0:
    if (record->event.pressed)
    {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  case 1:
    if (record->event.pressed)
    { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  case LAUNCH_TERM:
    if (record->event.pressed)
    {
      return MACRO(D(LGUI), T(ENTER), U(LGUI), END);
    }
    break;
  case LAUNCH_ROFI:
    if (record->event.pressed)
    {
      return MACRO(D(LGUI), T(X), U(LGUI), END);
    }
    // case LCTL_LSFT_L3:
    //   if (record->event.pressed)
    //   {
    //     return MACRO(D(LCTL), D(LSFT), D(MO(3)), END);
    //   }
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  // dynamically generate these.
  case EPRM:
    if (record->event.pressed)
    {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed)
    {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed)
    {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer)
  {
  // TODO: Make this relevant to the ErgoDox EZ.
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  default:
    // none
    break;
  }
};
