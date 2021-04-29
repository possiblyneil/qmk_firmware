/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum {
    PASTE,
    FFSC,
    WINSC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LSFT(KC_INS)),
    [FFSC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, RCS(KC_S)),
    [WINSC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, SGUI(KC_S)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,TD(PASTE),   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TD(WINSC),TD(FFSC),    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSPO,LCTL_T(KC_Z),SGUI_T(KC_X),LALT_T(KC_C),KC_V,KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT,RCTL_T(KC_SLSH),KC_RSPC,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_SPC,   MO(1),      MO(2),  KC_ENT, KC_NO\
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_SPC, _______,      MO(3),  KC_ENT, KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_SPC,   MO(3),    _______,  KC_ENT, KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_SPC, _______,    _______,  KC_ENT, KC_NO\
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

static void oled_render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0, 62, 91, 79, 91, 62,  0, 62,107, 79,107, 62,  0, 28, 62,124, 62, 28,  0, 24, 60,126, 60, 24,  0, 28, 87,125, 87, 28,  0, 28, 94,127, 94, 28,  0,  0, 24, 60, 24,  0,  0,255,231,195,231,255,  0,  0, 24, 36, 24,  0,  0,255,231,219,231,255,  0, 48, 72, 58,  6, 14,  0, 38, 41,121, 41, 38,  0, 64,127,  5,  5,  7,  0, 64,127,  5, 37, 63,  0, 90, 60,231, 60, 90,  0,127, 62, 28, 28,  8,  0,  8, 28, 28, 62,127,  0, 20, 34,127, 34, 20,  0, 95, 95,  0, 95, 95,  0,  6,  9,127,  1,127,  0, 
        0,102,137,149,106,  0, 96, 96, 96, 96, 96,  0,148,162,255,162,148,  0,  8,  4,126,  4,  8,  0, 16, 32,126, 32, 16,  0,  8,  8, 42, 28,  8,  0,  8, 28, 42,  8,  8,  0, 30, 16, 16, 16, 16,  0, 12, 30, 12, 30, 12,  0, 48, 56, 62, 56, 48,  0,  6, 14, 62, 14,  6,  0,  0,  0,  0,  0,  0,  0,  0, 95,  0,  0,  0,  0,  7,  0,  7,  0,  0, 20,127, 20,127, 20,  0, 36, 42,127, 42, 18,  0, 35, 19,  8,100, 98,  0, 54, 73, 86, 32, 80,  0,  0,  8,  7,  3,  0,  0,  0, 28, 34, 65,  0,  0,  0, 65, 34, 28,  0,  0, 42, 28,127,
        28, 42,  0,  8,  8, 62,  8,  8,  0,  0,128,112, 48,  0,  0,  8,  8,  8,  8,  8,  0,  0,  0, 96, 96,  0,  0, 32, 16,  8,  4,  2,  0, 62, 81, 73, 69, 62,  0,  0, 66,127, 64,  0,  0,114, 73, 73, 73, 70,  0, 33, 65, 73, 77, 51,  0, 24, 20, 18,127, 16,  0, 39, 69, 69, 69, 57,  0, 60, 74, 73, 73, 49,  0, 65, 33, 17,  9,  7,  0, 54, 73, 73, 73, 54,  0, 70, 73, 73, 41, 30,  0,  0,  0, 20,  0,  0,  0,  0, 64, 52,  0,  0,  0,  0,  8, 20, 34, 65,  0, 20, 20, 20, 20, 20,  0,  0, 65, 34, 20,  8,  0,  2,  1, 89,  9,  6,
        62, 65, 93, 89, 78,  0,124, 18, 17, 18,124,  0,127, 73, 73, 73, 54,  0, 62, 65, 65, 65, 34,  0,127, 65, 65, 65, 62,  0,127, 73, 73, 73, 65,  0,127,  9,  9,  9,  1,  0, 62, 65, 65, 81,115,  0,127,  8,  8,  8,127,  0,  0, 65,127, 65,  0,  0, 32, 64, 65, 63,  1,  0,127,  8, 20, 34, 65,  0,127, 64, 64, 64, 64,  0,127,  2, 28,  2,127,  0,127,  4,  8, 16,127,  0, 62, 65, 65, 65, 62,  0,127,  9,  9,  9,  6,  0, 62, 65, 81, 33, 94,  0,127,  9, 25, 41, 70,  0, 38, 73, 73, 73, 50,  0,  3,  1,127,  1,  3,  0, 63, 64,
        64, 64, 63,  0, 31, 32, 64, 32, 31,  0, 63, 64, 56, 64, 63,  0, 99, 20,  8, 20, 99,  0,  3,  4,120,  4,  3,  0, 97, 89, 73, 77, 67,  0,  0,127, 65, 65, 65,  0,  2,  4,  8, 16, 32,  0,  0, 65, 65, 65,127,  0,  4,  2,  1,  2,  4,  0, 64, 64, 64, 64, 64,  0,  3,  7,  8,  0,  0, 32, 84, 84,120, 64,  0,127, 40, 68, 68, 56,  0, 56, 68, 68, 68, 40,  0, 56, 68, 68, 40,127,  0, 56, 84, 84, 84, 24,  0,  0,  8,126,  9,  2,  0, 88, 20, 20,120, 12,  0,127,  8,  4,  4,120,  0,  0, 68,125, 64,  0,  0, 32, 64, 64, 61,  0, 
        0,127, 16, 40, 68,  0,  0,  0, 65,127, 64,  0,  0,124,  4,120,  4,120,  0,124,  8,  4,  4,120,  0, 56, 68, 68, 68, 56,  0,252, 24, 36, 36, 24,  0, 24, 36, 36, 24,252,  0,124,  8,  4,  4,  8,  0, 72, 84, 84, 84, 36,  0,  4,  4, 63, 68, 36,  0, 60, 64, 64, 32,124,  0, 28, 32, 64, 32, 28,  0, 60, 64, 48, 64, 60,  0, 68, 40, 16, 40, 68,  0, 76,144,144,144,124,  0, 68,100, 84, 76, 68,  0,  0,  8, 54, 65,  0,  0,  0,  0,127,  0,  0,  0,  0, 65, 54,  8,  0,  0,  2,  1,  2,  4,  2,  0, 60, 38, 35, 38, 60,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,192, 96, 96, 48, 16, 24,  8, 28, 28, 12,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224, 48, 24, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64, 64, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,224,240,240,240,224,236,238,247,243,112, 32,  0,124,124,124,126,  0,126,126,126,127,127,127,  0,  0,128,192,224,126, 91, 79, 91,254,192,  0,  0,192,  0,220,215,222,222,222,215,220,  0,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  8, 16, 16, 24, 24, 28, 28, 30, 30, 27, 27, 25, 25, 24, 24, 24, 24, 24, 24, 28, 28, 24,200,231,124, 60, 30,  6, 51,121,124,103, 51, 25, 11, 15, 99,126, 63, 63, 55, 53, 53, 21,133,225, 61, 31, 25, 25, 57,
        61,125,103,103,199, 67, 35,226,240, 56, 62, 31, 25, 25,  9,  9, 13,  5,255,127, 99, 99,243,120, 28,103,121, 28, 14,120,112, 56, 14,227, 56, 14, 15, 29, 28, 54, 50, 97,193,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 31, 63,127,127,127,127,127, 63, 30, 12,  0, 31, 31, 31, 63,  0, 63, 63, 63,127,127,127,  0, 48,123,127,120, 48, 32, 32, 48,120,127, 59,  0,  3,  0, 15,127, 15, 15, 15,127, 15,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 32, 24, 12, 14,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32, 24, 14,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  4,  4,  8,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
