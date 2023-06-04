/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_RBG,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE TG(LAYER_RAISE)
#define RBG_TAB LT(LAYER_RBG, KC_TAB)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
    // ╭────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
    // ├────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        RBG_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
    // ├────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
 SFT_T(KC_BSLS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  RSFT_T(KC_QUOT),
    // ├────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
          LOWER, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_EQL),
    // ╰────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 KC_BTN1, KC_BTN3, KC_BTN2,     TG(LAYER_RAISE),  KC_SPC,
                                         KC_LCTL,  KC_LALT,     KC_ENT
    //                          ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_4x6(
  // ╭────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______,      _______, _______,      _______, _______,    _______, _______, _______, _______, _______,  KC_INS,
  // ├────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, LSA(KC_LEFT), XXXXXXX, LSA(KC_RGHT), XXXXXXX,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, KC_RBRC,
  // ├─────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_CAPS,      KC_MUTE, KC_VOLD,      KC_VOLU, XXXXXXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_RSFT,
  // ├─────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX,      XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,    KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                             _______, _______, _______,    _______, _______,
                                                      _______, _______,    _______
  //                                       ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,    KC_VOLU, C(KC_C), C(KC_V), KC_WBAK, KC_WFWD,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,    KC_VOLD, KC_BTN1, KC_BTN3, KC_BTN2, DRGSCRL, KC_RSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, XXXXXXX,    KC_BSPC,  KC_DEL, KC_LEFT, KC_MPLY, KC_RGHT, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RBG] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,    RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW,  RGB_M_K, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, LAYER_LOWER));
    return state;
}
