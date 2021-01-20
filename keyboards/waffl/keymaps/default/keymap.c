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
    main,
    qwer,
    alt1,
    alt2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
	[main] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  MO(alt1),KC_BSPC, KC_SPC,  MO(alt2),KC_LBRC, KC_RBRC, KC_MINS, KC_EQL  B
    ),
	[qwer] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
        KC_LCTL, KC_LGUI, KC_LALT, TG(main),MO(alt1),KC_SPC,  KC_SPC,  MO(alt2),KC_LBRC, KC_RBRC, KC_MINS, KC_EQL  
    ),
    [alt1] = LAYOUT(
        _______, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, _______, 
        _______, KC_4,    KC_5,    KC_6,    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_QUOT, _______, 
        _______, KC_1,    KC_2,    KC_3,    KC_0,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, _______, 
        _______, _______, _______, _______, MO(alt1),XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______
    ),
    [alt2] = LAYOUT(
        _______, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
        _______, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  
        _______, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
        _______, _______, _______, TG(qwer),RESET,   XXXXXX, XXXXXXX, MO(alt2),_______, _______, _______, _______
    )
};
