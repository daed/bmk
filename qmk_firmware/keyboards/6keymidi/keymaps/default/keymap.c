// Copyright 2025 Brad Arnett <brad.arnett@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BASE 0

void keyboard_pre_init_user(void) {
  // init MIDI here
  tap_code16(MI_CH1);  // set midi channel to 1
  tap_code16(MI_OC3);  // set octave to 3
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_2x3(
    MI_C3,  MI_Cs3,  MI_D3,
    MI_Ds3,  MI_E3,  MI_F3
  )

};
