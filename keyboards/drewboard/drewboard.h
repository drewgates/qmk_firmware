/* Copyright 2021 drewgates
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k03, \
    k10, k11, k12, k13, \
    k20, k21, k22, k23 \
) { \
    { k00, k01, k02, k03 }, \
    { k10, k11, k12, k13 }, \
    { k20, k21, k22, k23 } \
}

    //set LED pins as outputs
#define ledOne E6
#define ledTwo D4
#define ledThree D5
#define ledFour B0

    //set pedal pins as inputs
#define pedalOne D2
#define pedalTwo D3
#define rotaryOne F0
#define rotaryTwo F1

/* drewboard LEDs
 *   GPIO pads
 *   0 E6 LED1, D13
 *   1 D4 LED2, D14
 *   2 D5 TXLED, D15
 *   3 B0 RXLED, D16
 */

/* drewboard GPIO direct buttons
Encoder 1 momentary: F0 (RIGHT)
Encoder 2 momentary: F1 (LEFT)
Pedal 1: D2 (J1)
Pedal 2: D3 (J2)
*/

bool process_record_pedalJ1(void);


