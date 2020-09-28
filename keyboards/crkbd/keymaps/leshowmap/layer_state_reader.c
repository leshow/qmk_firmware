
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_SYMB 2
#define L_ARROW 4
#define L_MOUSE 8
#define L_MEDIA 16
#define L_NUM 32
#define L_ADJUST 64
#define L_QWERTY 128

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Default");
            break;
        case L_SYMB:
            snprintf(layer_state_str, sizeof(layer_state_str), "Symbol");
            break;
        case L_ARROW:
            snprintf(layer_state_str, sizeof(layer_state_str), "Arrow");
            break;
        case L_MOUSE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Mouse");
            break;
        case L_MEDIA:
            snprintf(layer_state_str, sizeof(layer_state_str), "Media");
            break;
        case L_NUM:
            snprintf(layer_state_str, sizeof(layer_state_str), "Num");
            break;
        case L_ADJUST:
            snprintf(layer_state_str, sizeof(layer_state_str), "Adjust");
            break;
        case L_QWERTY:
            snprintf(layer_state_str, sizeof(layer_state_str), "QWERTY");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Undef-%ld", layer_state);
    }

    return layer_state_str;
}
