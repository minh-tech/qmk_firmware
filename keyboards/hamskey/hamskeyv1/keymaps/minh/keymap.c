#include QMK_KEYBOARD_H

#include "quantum.h"

#define HAMSKEY_DEFAULT_DPI 700
#define HAMSKEY_DRAGSCROLL_DPI 100
#define HAMSKEY_SNIPING_DPI 200

enum custom_keycodes {
    DRG_SCL = SAFE_RANGE,
    HOR_SCL,
    SNIPING,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
           KC_ESC,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  KC_GRV,  KC_TAB,    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
  KC_DEL, KC_CAPS,    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_EQL,
 KC_BSPC, KC_LSFT,    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B, S(KC_F6),         TG(2),   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS,
            MO(1), KC_LALT,  SNIPING, KC_LCTL, KC_BTN1, KC_BTN3,  KC_BTN2,         MO(2), KC_SPC,                            KC_RCTL, KC_ENT
  ),
  [1] = LAYOUT(
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
 XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_PSCR, XXXXXXX, XXXXXXX,
 XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
 HOR_SCL, _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,       XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
          XXXXXXX, _______, KC_LGUI, _______, _______, _______, _______,       XXXXXXX, _______,                            _______, _______
  ),
  [2] = LAYOUT(
          _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_MPLY, C(KC_C), C(KC_V), KC_WBAK, KC_WFWD,  KC_F12, XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, DRG_SCL, XXXXXXX, XXXXXXX,
 HOR_SCL, _______, _______, _______, _______, _______, XXXXXXX, KC_MUTE,       _______, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
          XXXXXXX, _______, _______, _______, _______, _______, _______,       XXXXXXX, _______,                            _______, _______
  ),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),                ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
    [1] =   { ENCODER_CCW_CW(C(KC_PGUP), C(KC_PGDN)),          ENCODER_CCW_CW(LSA(KC_LEFT), LSA(KC_RGHT))  },
    [2] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),                ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
};
#endif

#ifdef POINTING_DEVICE_ENABLE
static bool scrolling_mode = false;
static bool is_scroll_horizontal = false;

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(HAMSKEY_DEFAULT_DPI);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        if (is_scroll_horizontal) {
            mouse_report.h = mouse_report.x;
        } else {
            mouse_report.v = -mouse_report.y;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DRG_SCL:
        if (record->event.pressed) {
            scrolling_mode = true;
            pointing_device_set_cpi(HAMSKEY_DRAGSCROLL_DPI);
        } else {
            scrolling_mode = false;
            pointing_device_set_cpi(HAMSKEY_DEFAULT_DPI);
        }
        break;
    case HOR_SCL:
        if (record->event. pressed) {
            is_scroll_horizontal = true;
        } else {
            is_scroll_horizontal = false;
        }
        break;
    case SNIPING:
        if (record->event.pressed) {
            pointing_device_set_cpi(HAMSKEY_SNIPING_DPI);
        } else {
            pointing_device_set_cpi(HAMSKEY_DEFAULT_DPI);
        }
        break;
  }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1:
            scrolling_mode = true;
            pointing_device_set_cpi(HAMSKEY_DRAGSCROLL_DPI);
            break;
        default:
            scrolling_mode = false;
            pointing_device_set_cpi(HAMSKEY_DEFAULT_DPI);
            break;
    }
    return state;
}
#endif
