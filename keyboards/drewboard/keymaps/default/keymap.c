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
#include QMK_KEYBOARD_H
//#include "quantum.h"
#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    DREWSIG,
    LEDTESTON,
    LEDTESTOFF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        RGB_TOG,   KC_F1,    KC_F2,    DEBUG,\
        KC_F4,     KC_F5,    KC_F6,    KC_F7,\
        TO(_FN),   RGB_MOD,  RGB_HUI,  RGB_VAI
    ),
    [_FN] = LAYOUT(
        KC_L,      DREWSIG,   KC_J,    KC_K,\
        KC_F,      KC_G,      KC_H,    KC_I,\
        TO(_BASE), LEDTESTON,      LEDTESTOFF,    KC_F13
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DREWSIG:
            if (record->event.pressed) {
                // when keycode DREWSIG is pressed
                SEND_STRING("Drew Gates\ndrew@drewgates.com\n");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case LEDTESTON:
            writePinHigh(ledOne);
            writePinHigh(ledTwo);
            writePinHigh(ledThree);
            writePinHigh(ledFour);
            break;
        case LEDTESTOFF:
            writePinLow(ledOne);
            writePinLow(ledTwo);
            writePinLow(ledThree);
            writePinLow(ledFour);
            break;

    }
    // If console is enabled, it will print the matrix position and status of each key pressed
    if readPin(F0 == 1){
        uprintf("encoder pressed");
    }
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active){
			tap_code(KC_W);
            }
            else{}
            break;
        case 1:
            if(active){
			tap_code(KC_X);
		    }
            else{}
            break;
        case 2:
            if(active){
			tap_code(KC_Y);
		    }
            else{}
            break;
        case 3:
            if(active){
			tap_code(KC_Z);
		    }
            else{}
            break;
    }
}

//Rotary Encoder spinning!aaabbbbaaabbbbaaaaaabbbb
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { //second encoder
        if (clockwise) {
            tap_code(KC_A);
        } else {
            tap_code(KC_B);
        }
    } else if (index == 1) { //first encoder
        if (clockwise) {
            tap_code(KC_C);
        } else {
            tap_code(KC_D);
        }
    }
}

//Button Pins
//Encoder:F0, F1
//Pedals: D2, D3
//setPinInput()


//this block may not be needed
/*void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            tap_code(KC_W);
        case 1:
            if(active) { tap_code(KC_X); } else {  }
            break;
        case 2:
            if(active) { tap_code(KC_Y); } else {  }
            break;
        case 3:
            if (active) {

            } else {
                tap_code(KC_Z);
            }
            break;
    }
}*/
