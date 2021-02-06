/* Copyright 2021 teakettle.tk
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
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;  

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASED,
    FN1,
    FN2,
    MACRO
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    DESKLEFT = SAFE_RANGE,
    DESKRGHT,
    ALTTAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASED] = LAYOUT(
        KC_Q,         KC_W,   KC_F,   KC_P,           KC_B,            KC_J,           KC_L,           KC_U,            KC_Y,   ALTTAB,   
        KC_A,         KC_R,   KC_S,   LT(FN1, KC_T),  KC_G,            KC_M,           LT(FN2, KC_N),  LT(MACRO, KC_E), KC_I,   KC_O,
        LGUI_T(KC_Z), KC_X,   KC_C,   KC_D,           LSFT_T(KC_BSPC), LCTL_T(KC_SPC), KC_V,           KC_K,            KC_H,   KC_ENTER
    ),
    [FN1] = LAYOUT(
        KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LBRC,   KC_RBRC,  
        KC_TAB,    DESKLEFT,  DESKRGHT,  XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LALT,   _______,   KC_BSLS,   KC_COMM,   KC_DOT,    KC_SLSH
    ),
    [FN2] = LAYOUT(
        KC_7,      KC_8,      KC_9,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
        KC_4,      KC_5,      KC_6,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_ENTER,
        KC_1,      KC_2,      KC_3,      KC_0,      _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   RESET
    ),
    [MACRO] = LAYOUT(
        RESET,     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   DESKLEFT,  DESKRGHT,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DESKLEFT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_DOWN(X_LEFT));
            } else {
                // when keycode QMKBEST is released
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_UP(X_LEFT));
            }
            break;
        case DESKRGHT:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_DOWN(X_LCTL));
                SEND_STRING(SS_DOWN(X_LGUI));
                SEND_STRING(SS_DOWN(X_RIGHT));
            } else {
                // when keycode QMKURL is released
                SEND_STRING(SS_UP(X_LCTL));
                SEND_STRING(SS_UP(X_LGUI));
                SEND_STRING(SS_UP(X_RIGHT));
            }
            break;
        case ALTTAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
              } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 300) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
