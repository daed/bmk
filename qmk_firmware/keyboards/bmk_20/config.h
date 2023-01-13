#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x424D
#define PRODUCT_ID      0x4B00
#define DEVICE_VER      0x0000
#define MANUFACTURER    "Brad Arnett"
#define PRODUCT         "BMK-20 Macropad"


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, B3, B2, B6, F4 }
#define MATRIX_COL_PINS { D4, C6, D7, E6 }
#define UNUSED_PINS

#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define OLED_FONT_H "keyboards/bmk_20/lib/glcdfont_bmk.c"

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#endif
