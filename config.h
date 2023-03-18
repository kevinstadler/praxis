#pragma once

#define MASTER_LEFT
#define SPLIT_USB_DETECT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 165
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 1

#define COMBO_COUNT 1

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define ENABLE_RGB_MATRIX_SPLASH
#endif

#ifdef OLED_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif
