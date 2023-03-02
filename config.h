#pragma once

#define MASTER_LEFT
#define SPLIT_USB_DETECT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 180 // was 200
#define TAPPING_TOGGLE 1

#define COMBO_COUNT 1

#ifdef RGBLIGHT_ENABLE
    /* #define SPLIT_LAYER_STATE_ENABLE */
    /* /1* #define RGBLIGHT_EFFECT_BREATHING *1/ */
    /* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
    /* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
    /* #define RGBLIGHT_EFFECT_KNIGHT */
    #undef RGBLIGHT_DEFAULT_MODE
    /* #define RGBLIGHT_EFFECT_CHRISTMAS */
    /* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
    /* #define RGBLIGHT_EFFECT_RGB_TEST */
    /* #define RGBLIGHT_EFFECT_ALTERNATING */
    /* #define RGBLIGHT_EFFECT_TWINKLE */
    #define RGBLIGHT_LIMIT_VAL 220
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 20
#endif

#ifdef OLED_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif
