// Copyright 2025 Brad Arnett <brad.arnett@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_2x3(
    KC_PGUP,  KC_HOME,  KC_UP,
    KC_PGDN,  KC_LEFT,  KC_DOWN
  )

};
