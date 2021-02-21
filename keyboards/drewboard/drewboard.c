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

#include "drewboard.h"

void keyboard_pre_init_user(void) {
    //set LED pins as outputs
    setPinOutput(ledOne);
    setPinOutput(ledTwo);
    setPinOutput(ledThree);
    setPinOutput(ledFour);

    //set pedal pins as inputs
    setPinInputHigh(pedalOne);
    setPinInputHigh(pedalTwo);

    //set rotary momentary buttons as inputs
    setPinInputHigh(rotaryOne);
    setPinInputHigh(rotaryTwo);
}

void keyboard_post_init_user(void) {
    /*rgblight_setrgb_at(RGB_PURPLE, 0); // [..., 0] = top LED
    rgblight_setrgb_at(RGB_TEAL, 1); // [..., 1] = middle LED
    rgblight_setrgb_at(RGB_AZURE, 2); // [..., 2] = bottom LED*/
}


//LAYER LED indicators
uint32_t layer_state_set_kb(uint32_t state)
{
    // if we are on layer 1
    if (state & (1<<1)){
        writePinHigh(ledOne);
    } else{
        writePinLow(ledOne);
    }

    // if we are on layer 2
    if (state & (1<<2)){
        writePinHigh(ledTwo);
    } else{
        writePinLow(ledTwo);
    }

    return state;
}

//not sure this gets used
/*bool process_record_pedalJ1(void) {
    setPinInput(D2);
    if (readPin(D2) == 1) {
        tap_code(KC_A);
        writePinHigh(D4);
         _delay_ms(100);
        writePinLow(D4);
    }
    return true;
}*/
