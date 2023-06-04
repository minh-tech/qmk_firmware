/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
            KC_ESC,    KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
     LT(3, KC_TAB),    KC_Q,    KC_W,  KC_E,    KC_R,    KC_T,                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
          KC_BSLS ,    KC_A,    KC_S,  KC_D,    KC_F,    KC_G,                                   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
           KC_LSFT,    KC_Z,    KC_X,  KC_C,    KC_V,    KC_B, KC_BSPC,                   TG(2), KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
             MO(1),  KC_EQL, KC_LALT, KC_LCTL, KC_BTN1, KC_BTN3, KC_BTN2,                 MO(2), KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, KC_ENT
  ),

  [1] = LAYOUT_universal(
    _______, _______,      _______, _______,      _______, _______,                          _______, _______, _______, _______, _______, KC_INS,
     KC_GRV, XXXXXXX, LSA(KC_LEFT), XXXXXXX, LSA(KC_RGHT), XXXXXXX,                          KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, KC_RBRC,
    KC_CAPS, XXXXXXX,      KC_MUTE, KC_VOLD,      KC_VOLU, XXXXXXX,                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, S(KC_RBRC),
    KC_LSFT, XXXXXXX,      XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,S(KC_F6),        XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX,      _______, _______,      _______, _______, _______,        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),

  [2] = LAYOUT_universal(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,                                 KC_VOLU, C(KC_C), C(KC_V), KC_WBAK, KC_WFWD,  KC_F12,
    XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                                 KC_VOLD, KC_BTN1, KC_BTN3, KC_BTN2, SCRL_MO, XXXXXXX,
    KC_LSFT, _______, _______, _______, _______, XXXXXXX, XXXXXXX,               _______, KC_BSPC,  KC_DEL, KC_LEFT, KC_MPLY, KC_RGHT, KC_RSFT,
    XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,               _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI, RGB_VAI, XXXXXXX,                              RGB_M_P,  RGB_M_B,  RGB_M_R, RGB_M_SW, RGB_M_SN, XXXXXXX,
    _______, RGB_RMOD,  RGB_HUD,  RGB_SAD, RGB_VAD, XXXXXXX,                              RGB_M_X,  RGB_M_G,  RGB_M_T, RGB_M_TW,  RGB_M_K, XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX, SCRL_DVD, SCRL_DVI, SCRL_MO, SCRL_TO, EEP_RST,            EEP_RST, CPI_D1K, CPI_D100, CPI_I100,  CPI_I1K, KBC_SAVE, KBC_RST,
    XXXXXXX,  XXXXXXX,  _______,  _______, _______, _______, QK_BOOT,            QK_BOOT, _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 1
    keyball_set_scroll_mode(get_highest_layer(state) == 1);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
