/* Copyright 2020 %YOUR_NAME%
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    DSKLEFT = SAFE_RANGE,
    DSKRGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MO(_FN2),KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    MO(_FN1),KC_SPC,  KC_B,    KC_N,    KC_M,    KC_DOT,  KC_DEL
    ),
    [_FN1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  _______, 
        _______, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_QUOT, KC_SCLN, _______, 
        _______, KC_1,    KC_2,    KC_3,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_SLSH, KC_COMM, _______
    ),
    [_FN2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_GRV,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   XXXXXXX, _______, 
        KC_TAB,  KC_PSCR, KC_LGUI, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F11,  KC_F12,  _______
    )
    //[_FN1] = LAYOUT(
    //    _______, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, 
    //    _______, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, 
    //    _______, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, 
    //    _______, _______, _______, KC_0,    MO(_FN1),XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_VOLD, KC_VOLU, _______
    //),
    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DSKLEFT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LCTL() SS_LGUI("X_LEFT"));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case DSKRGHT:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL()SS_LGUI("X_RIGHT"));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
