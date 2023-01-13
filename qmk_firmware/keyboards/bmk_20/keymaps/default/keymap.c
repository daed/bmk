#include "bmk_20.h"

enum encoder_names {
  DIAL,
};

enum custom_keys {
    LAYERCHANGE = SAFE_RANGE
};

enum layers {
    _NUM,
    _ALT,
    _NA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NUM] = KEYMAP(
        KC_NUM,    LAYERCHANGE,     KC_PAST,  KC_PMNS,
        KC_P7,     KC_P8,           KC_P9,    KC_PPLS,
        KC_P4,     KC_P5,           KC_P6,    KC_NO,
        KC_P1,     KC_P2,           KC_P3,    KC_PENT,
        KC_P0,     KC_NO,           KC_PDOT,  KC_NO
    ),

	[_ALT] = KEYMAP(
		KC_NUM,     LAYERCHANGE,    KC_ASTR,    KC_MINS,
		KC_HOME,    KC_NO,          KC_PGUP,    KC_NO,
		KC_NO,      KC_5,           KC_NO,      KC_PLUS,
		KC_END,     KC_NO,          KC_PGDN,    KC_NO,
		KC_INS,     KC_DEL,         KC_ENT,     KC_NO
        ),

	[_NA] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool layerSwitch = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYERCHANGE: {
            if (record->event.pressed) {
                layerSwitch = true;
            }
            else {
                layerSwitch = false;
            }
        }
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!layerSwitch) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else {
        if (clockwise) {
            layer_move(1);
        } else {
            layer_move(0);
        }
    }
    return false;
}


#ifdef OLED_ENABLE

static const char PROGMEM logo[3][5] = {
    {0x80, 0x81, 0x82, 0x83, 0x00},
    {0xA0, 0xA1, 0xA2, 0xA3, 0x00},
    {0xC0, 0xC1, 0xC2, 0xC3, 0x00}
};



void pad_str_offset(const char *text, int line, int offset) {
    int len = 17 - offset;
    char *buf = malloc(len);
    strcpy(buf, "                \0");
    if (strlen(text) < len) {
        len = strlen(text);
    }
    strncpy(buf, text, len);
    uprintf("output buffer: %s\n", buf);

    oled_write(buf, false);
    oled_write_P(logo[line], false);
    oled_write_P(PSTR("\n"), false);

    free(buf);
}

void pad_str(const char *text, int line) {
    pad_str_offset(text, line, 0);
}


bool oled_task_user(void) {
    oled_clear();
    //uprintf("max_chars: %u, max_lines: %u\n", oled_max_chars(), oled_max_lines());
    oled_write_P(PSTR("Layer: "), false);
    uprintf("layer state: %u\n", get_highest_layer(layer_state));
    switch (get_highest_layer(layer_state)) {
        case _NUM:
            pad_str_offset("Default", 0, 0);
            break;
        case _ALT:
            pad_str_offset("Alt", 0, 7);
            break;
        case _NA:
            pad_str_offset("NA", 0, 7);
            break;
        default:
            pad_str_offset("Undefined", 0, 7);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), 1);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), 1);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), 1);

    // just for the rest of the logo
    pad_str(" ", 2);

    return false;
}
#endif
