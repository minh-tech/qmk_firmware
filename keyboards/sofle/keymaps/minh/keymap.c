 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "encoder.c"

// Base layer is the number of layers CYCLE selects from.
#define BASE_LAYERS 2
#define KC_SALE LSA(KC_LEFT)
#define KC_SARG LSA(KC_RGHT)

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
    // CYCLE                      // cycle through first BASE_LAYERS (62 bytes)
};

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE
};

// Extra keys are added for rotary encoder support in VIA
#define LAYOUT_via( \
    LA1, LA2, LA3, LA4, LA5, LA6,           RA6, RA5, RA4, RA3, RA2, RA1, \
    LB1, LB2, LB3, LB4, LB5, LB6, LB7, RB7, RB6, RB5, RB4, RB3, RB2, RB1, \
    LC1, LC2, LC3, LC4, LC5, LC6, LE1, RE6, RC6, RC5, RC4, RC3, RC2, RC1, \
    LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD7, RD6, RD5, RD4, RD3, RD2, RD1, \
              LE2, LE3, LE4, LE5, LE6, RE5, RE4, RE3, RE2, RE1 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6, KC_NO }, \
        { LB1, LB2, LB3, LB4, LB5, LB6, LB7   }, \
        { LC1, LC2, LC3, LC4, LC5, LC6, KC_NO }, \
        { LD1, LD2, LD3, LD4, LD5, LD6, LD7   }, \
        { LE1, LE2, LE3, LE4, LE5, LE6, KC_NO }, \
        { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO }, \
        { RB1, RB2, RB3, RB4, RB5, RB6, RB7   }, \
        { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO }, \
        { RD1, RD2, RD3, RD4, RD5, RD6, RD7   }, \
        { RE1, RE2, RE3, RE4, RE5, RE6, KC_NO } \
    }

//Default keymap. This can be changed in Via. Use oled.c to change beavior that Via cannot change.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_via(
   KC_ESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6    , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
   KC_TAB, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_VOLU,          KC_LEFT, KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
  KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_MUTE,       TG(_RAISE), KC_H    , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_VOLD,          KC_RGHT, KC_N    , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                 MO(_LOWER), KC_LCTL,KC_BSPC , KC_LALT, KC_BSLS,       MO(_RAISE), KC_SPC  , KC_EQL , KC_RCTL, KC_ENT
),

[_LOWER] = LAYOUT_via(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
   KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,S(KC_F6), XXXXXXX, KC_PGUP,       KC_SALE, XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PSCR, KC_RBRC ,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, S(KC_RBRC),
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, KC_PGDN,       KC_SARG, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    XXXXXXX, _______, KC_LGUI, _______, _______,       XXXXXXX, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_via(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6 , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  _______, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, KC_PGUP,     _______,  XXXXXXX, KC_WBAK, KC_MS_U, XXXXXXX, KC_WH_U, KC_F12 ,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     _______,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, KC_PGDN,     _______,  KC_BSPC,  KC_DEL, KC_MPLY, XXXXXXX, XXXXXXX, _______,
                    XXXXXXX, _______, KC_BTN1, KC_BTN3, KC_BTN2,     _______, _______ , _______, _______, _______
)
};

// Custom keycode handling.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     // handling this once instead of in each keycode uses less program memory.
//     if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
//         return false;
//     }

//     switch (keycode) {
//         case CYCLE:
//             set_single_persistent_default_layer((1+get_highest_layer(default_layer_state)) % BASE_LAYERS);
//             break;
//     }

//     // this uses less memory than returning in each case.
//     return keycode < SAFE_RANGE;
// };
