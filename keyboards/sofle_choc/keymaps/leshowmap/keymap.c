/* Copyright 2023 Brian Low
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
#include QMK_KEYBOARD_H
#include "oled.c"

// layer keys
#define NUM LT(_NUM, KC_DEL)
#define ARROW LT(_ARROW, KC_F)
#define MOUSE LT(_MOUSE, KC_V)
#define S_SPC LT(_SYMB, KC_SPC)
#define S_BSPC LT(_SYMB, KC_BSPC)
#define MEDIA LT(_MEDIA, KC_DEL)
#define ADJUST LT(_ADJUST, KC_ESC)
#define QWERTY TO(_QWERTY)
#define DEFAULT TO(_DEFAULT)
// i3
#define GQUOT GUI_T(KC_QUOT)
#define GTAB GUI_T(KC_TAB)
#define SGENT SGUI_T(KC_ENT)
// mods
#define LCTLZ LCTL_T(KC_Z)
#define RCTLS LCTL_T(KC_SLSH)
#define RALTD RALT_T(KC_DOT)
#define LALTX LALT_T(KC_X)
#define ESC_SFT LSFT_T(KC_ESC)
#define ESC_CTRL LCTL_T(KC_ESC)
#define CTL_NUM LT(_MEDIA, KC_LCTL)
// homerow mods
#define S_L LSFT_T(KC_L)
#define S_A LSFT_T(KC_A)
#define S_D RSFT_T(KC_D)
#define S_SCLN RSFT_T(KC_SCLN)

// Each layer gets a name for readability
enum layers {
  _DEFAULT,
  _SYMB,
  _ARROW,
  _MOUSE,
  _MEDIA,
  _NUM,
  _ADJUST,
  _QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * DEFAULT (ported from crkbd leshowmapmatrix)
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | ___  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | ___  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |MEDIA |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | GTAB |  S_A |   S  |   D  |ARROW |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |S_SCLN| GQUOT|
   * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
   * |SC_LSP|LCTLZ |LALTX |   C  |MOUSE |   B  |-------|    |-------|   N  |   M  |   ,  |RALTD |RCTLS |SC_RSP|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | ____ | ____ |ESCCTL| NUM  | / S_SPC /       \S_BSPC\ |SGENT | ADJ  | ____ | ____ |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_DEFAULT] = LAYOUT(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    MEDIA,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    GTAB,    S_A,     KC_S,    KC_D,    ARROW,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    S_SCLN,  GQUOT,
    SC_LSPO, LCTLZ,   LALTX,   KC_C,    MOUSE,   KC_B,    KC_MPLY,   KC_MUTE, KC_N,    KC_M,    KC_COMM, RALTD,   RCTLS,   SC_RSPC,
                      KC_TRNS, KC_TRNS, ESC_CTRL,NUM,     S_SPC,     S_BSPC,  SGENT,   ADJUST,  KC_TRNS, KC_TRNS
  ),

  /*
   * SYMB
   */
  [_SYMB] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,                      KC_EQUAL,KC_LCBR, KC_RCBR, KC_AT,   KC_EXLM, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_AMPR, KC_LBRC, KC_RBRC, KC_MINUS,                     KC_UNDS, KC_LPRN, KC_RPRN, KC_DLR,  KC_COLN, KC_DQUO,
    KC_TRNS, KC_QUOT, KC_COMMA,KC_DOT,  KC_GRAVE,KC_PLUS, KC_MPLY,   KC_MUTE, KC_TILD, KC_PIPE, KC_LABK, KC_RABK, KC_SLASH,KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,    KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

#ifdef REPEAT_KEY_ENABLE
  /*
   * ARROW
   */
  [_ARROW] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      QK_REPEAT_KEY, KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT,CW_TOGG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,   KC_MUTE, KC_INS,  KC_CAPS_LOCK,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
#endif
#ifndef REPEAT_KEY_ENABLE
  [_ARROW] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,CW_TOGG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,   KC_MUTE, KC_INS, KC_CAPS_LOCK,KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
#endif

  /*
   * MOUSE
   */
  [_MOUSE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS,
    KC_TRNS, MS_ACL0, MS_ACL1, MS_ACL2, KC_TRNS, KC_TRNS,                      KC_TRNS, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,   KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN2,   MS_BTN1, MS_BTN3, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /*
   * MEDIA
   */
  [_MEDIA] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F11,                       KC_F12,  KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY,   KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_AUDIO_MUTE,
                      KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS
  ),

  /*
   * NUM
   */
  [_NUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_QUES, KC_CIRC, KC_PERC, KC_HASH, KC_ASTR,                      KC_EQUAL,KC_7,    KC_8,    KC_9,    KC_EXLM, KC_TRNS,
    KC_TRNS, KC_SLASH,KC_AMPR, KC_LBRC, KC_RBRC, KC_MINUS,                     KC_UNDS, KC_4,    KC_5,    KC_6,    KC_COLN, KC_DQUO,
    KC_TRNS, KC_QUOT, KC_COMMA,KC_DOT,  KC_GRAVE,KC_PLUS, KC_MPLY,   KC_MUTE, KC_0,    KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_SPC,  KC_0,    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /*
   * ADJUST
   */
  [_ADJUST] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_TOGG, KC_MPLY,   KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, QWERTY,  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS
  ),

  /*
   * QWERTY
   */
  [_QWERTY] = LAYOUT(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DEFAULT,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, GQUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_TRNS, KC_TRNS, KC_LCTL, KC_SPC,  KC_ENT,    KC_BSPC, KC_ENT,  KC_ESC,  KC_TRNS, KC_TRNS
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYMB]    = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ARROW]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MOUSE]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MEDIA]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUM]     = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ADJUST]  = {ENCODER_CCW_CW(RM_SPDD, RM_SPDU), ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [_QWERTY]  = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
