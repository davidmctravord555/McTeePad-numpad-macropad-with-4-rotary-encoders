// Copyright 2022 David McTravord (@David_McTravord555)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MANUFACTURER David_McTravord
#define PRODUCT mcteepad_v1

#define MATRIX_ROWS 6
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { D7, E6, B4, B5 }
#define ENCODERS_PAD_B { B1, B3, B2, B6 }

#define ENCODER_RESOLUTIONS { 4, 4, 4, 4 }

#define USB_POLLING_INTERVAL_MS 1 

#define DEBOUNCE_TYPE = sym_defer_pk

#define STM32_ONBOARD_EEPROM_SIZE 1024
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
