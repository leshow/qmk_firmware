/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "preonic.h"
#include "action_layer.h"

#define ALT_X ALT_T(KC_X)
#define CTL_Z CTL_T(KC_Z)
#define ALT_DOT ALT_T(KC_DOT)
#define CLT_SLSH CTL_T(KC_SLSH)
#define ARRW_F LT(_ARRW, KC_F)
#define MOUS_V LT(_MOUS, KC_V)
#define GUI_TAB GUI_T(KC_TAB)
#define GUI_QUOT GUI_T(KC_QUOT)
#define LSYMB LT(_LOWER, KC_BSPACE)
#define RSYMB LT(_RAISE, KC_SPC)
#define SFDEL SFT_T(KC_DEL)
#define SFENT SFT_T(KC_ENT)

#define LAUNCH_ROFI 6
#define LAUNCH_TERM 7

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  // _SYMB,
  _ARRW,
  _MOUS,
  _UCODE
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ROFI |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | ESC  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |scmd/c|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TB/G |   A  |   S  |   D  | F/ARW|   G  |   H  |   J  |   K  |   L  |   ;  | '/GUI|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Z/CTL| X/ALT|   C  | V/MS |   B  |   N  |   M  |   ,  | ./ALT| //CTL| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TERM | CODE | _ADJ |Gui+Sf|LSYMB |DEL/St|ENT/St| RSYMB| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {M(LAUNCH_ROFI),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_ESC},
  {SCMD_T(KC_CAPSLOCK),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPACE},
  {GUI_TAB,   KC_A,    KC_S,    KC_D,    ARRW_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  GUI_QUOT},
  {KC_LSFT,   CTL_Z,   ALT_X,   KC_C,    MOUS_V,  KC_B,    KC_N,    KC_M,    KC_COMM, ALT_DOT, CLT_SLSH, KC_RSFT},
  {M(LAUNCH_TERM), MO(_UCODE), TT(_ADJUST), LGUI(KC_LSFT), LSYMB, SFDEL,   SFENT,   RSYMB,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT} },

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC},
  {KC_DEL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

// /* Lower
//  * ,-----------------------------------------------------------------------------------.
//  * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
//  * |------+------+------+------+------+------|------+------+------+------+------+------|
//  * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_LOWER] = {
//   {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
//   {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
//   {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
//   {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
//   {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
// },

// /* Raise
//  * ,-----------------------------------------------------------------------------------.
//  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
//  * |------+------+------+------+------+------|------+------+------+------+------+------|
//  * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_RAISE] = {
//   {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
//   {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
//   {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
//   {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
//   {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
// },

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ?  |   ^  |   %  |   #  |   *  |   =  |   {  |   }  |   @  |   !  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   \  |   &  |   ]  |   [  |   -  |   _  |   (  |   )  |   $  |   :  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  '   |   ,  |   .  |   `  |   +  |   ~  |   |  |   <  |   >  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | mute |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_F12,  KC_F1,     KC_F2,    KC_F3,       KC_F4,       KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11},
  {_______, KC_QUES,   KC_CIRC,  KC_PERC,     KC_HASH,     KC_ASTR,  KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT,    KC_EXLM, _______},
  {_______, KC_BSLASH, KC_AMPR,  KC_RBRACKET, KC_LBRACKET, KC_MINUS, KC_UNDS,  KC_LPRN, KC_RPRN, KC_DLR,   KC_COLN,  KC_DQUO},
  {_______, KC_QUOT,   KC_COMMA, KC_DOT, KC_GRAVE,    KC_PLUS,     KC_TILD,  KC_PIPE,  KC_LABK, KC_RABK, KC_SLASH,  _______},
  {KC_MUTE, _______, _______, _______, _______, _______, _______,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ?  |   ^  |   %  |   #  |   *  |   =  |   {  |   }  |   @  |   !  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   \  |   &  |   ]  |   [  |   -  |   _  |   (  |   )  |   $  |   :  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  '   |   ,  |   .  |   `  |   +  |   ~  |   |  |   <  |   >  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | mute |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F12,  KC_F1,     KC_F2,    KC_F3,       KC_F4,       KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11},
  {_______, KC_QUES,   KC_CIRC,  KC_PERC,     KC_HASH,     KC_ASTR,  KC_EQUAL, KC_LCBR, KC_RCBR, KC_AT,    KC_EXLM, _______},
  {_______, KC_BSLASH, KC_AMPR,  KC_RBRACKET, KC_LBRACKET, KC_MINUS, KC_UNDS,  KC_LPRN, KC_RPRN, KC_DLR,   KC_COLN,  KC_DQUO},
  {_______, KC_QUOT,   KC_COMMA, KC_DOT, KC_GRAVE,    KC_PLUS,     KC_TILD,  KC_PIPE,  KC_LABK, KC_RABK, KC_SLASH,  _______},
  {KC_MUTE, _______, _______, _______, _______, _______, _______,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* ARRW
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARRW] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_HOME},
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_PGUP},
  {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDN},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_END},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______}
},
/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | WLft | WDwn | WUp  | WRght|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |ACCEL0|ACCEL1|ACCEL2|      |      |      | MLft | MDwn | MUp  | MRght|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | RCLK | MCLK | MCLK | LCLK |   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUS] = {
  {_______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______},
  {_______, _______,   _______,   _______, _______, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN,KC_MS_WH_UP, KC_MS_WH_RIGHT, _______},
  {_______, _______, _______,  _______,   _______,  _______, _______, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_UP,  KC_MS_RIGHT, _______},
  {_______, _______,  _______,  _______,   _______,  _______,  _______,  _______, _______, _______, _______, KC_END},
  {_______, _______, _______, _______, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN3, KC_MS_BTN1, _______, _______, _______, _______}
},
/* UCODE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ☠   |   ⊸  |  ∪   |  ∩   |  ×   |  λ   |  ℕ   |  ⇐   |  ⇒   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ρ   |  ε   |  β   |  α   |  ¬   |  ∀   |  ←   |   ↓  |  ↑   |  →   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |  ★   |  ✓   |  ω   |   ∃  |   ∧  |  ∨   |  ∷   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UCODE] = {
  {_______,  _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
  {_______, UC(0x2620), UC(0x22B8), UC(0x222A), UC(0x2229), UC(0x00D7), UC(0x03BB), UC(0x2115), UC(0x21D0), UC(0x21D2), _______,    _______},
  {_______, UC(0x03C1), UC(0x03B5), UC(0x03B2), UC(0x03B1), UC(0x00AC), UC(0x2200), UC(0x2190), UC(0x2193), UC(0x2191), UC(0x2192), _______},
  {_______, _______,    _______,    UC(0x2605), UC(0x2713), UC(0x03C9), UC(0x2203), UC(0x2227), UC(0x2228), UC(0x2237), _______,    _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
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
  }
  return MACRO_NONE;
};
