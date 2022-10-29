// Copyright 2022 Danis Rakasiwi (@David_McTravord555)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define ENCODERS_PAD_A { D7, E6, B4, B5 }
#define ENCODERS_PAD_B { B1, B3, B2, B6 }

#define ENCODERS_PAD_A { encoder0a, encoder1a, encoder2a, encoder3a }
#define ENCODERS_PAD_B { encoder0b, encoder1b, encoder2b, encoder3b }

#define ENCODER_RESOLUTIONS { 4, 4, 4, 4 }

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
