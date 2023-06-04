#pragma once

#include "config_common.h"

// USB Device descriptor parameters
#define VENDOR_ID           0x484D     // "HK" = Hamskey
#define PRODUCT_ID          0x484B
#define DEVICE_VER          0x0001
#define MANUFACTURER        HoangMinh
#define PRODUCT             Hamskeyv1

#define MATRIX_ROWS         10  // split keyboard
#define MATRIX_COLS         7
#define MATRIX_ROW_PINS     { B5, B4, D7, D6, D4 }
#define MATRIX_COL_PINS     { F0, F1, F4, F5, F6, F7, C7 }

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE            5

// Split parameters
#define SOFT_SERIAL_PIN         D2
#define SPLIT_HAND_PIN          D5
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT       2000

/* encoder support */
#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { B6 }
#define ENCODER_RESOLUTION 2

// #define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO, KEYBALL_GET_MOTION, KEYBALL_SET_CPI

#ifndef OLED_FONT_H
#    define OLED_FONT_H "keyboards/keyball/lib/glcdfont.c"
#endif

#define LAYER_STATE_8BIT

// To squeeze firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Enable use of pointing device on slave split.
#define SPLIT_POINTING_ENABLE

// Pointing device is on the right split.
#define POINTING_DEVICE_RIGHT

#define POINTING_DEVICE_ROTATION_90

#define POINTING_DEVICE_INVERT_X

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define PMW33XX_CS_PIN SPI_SS_PIN
