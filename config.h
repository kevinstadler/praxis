#pragma once

#define MASTER_LEFT
#define SPLIT_USB_DETECT

/* #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD */
#define TAPPING_FORCE_HOLD
// 150 still resulted in fi rolls instead of I, so reduce further to trigger shift more easily
// 145 still had sk -> *
// oh the QWERTY days...
/* #define TAPPING_TERM 140 */
// still slo on colemak
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 1

#define COMBO_COUNT 1

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define ENABLE_RGB_MATRIX_SPLASH

        /* #define ENABLE_RGB_MATRIX_SOLID_SPLASH */

        // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#rgb-matrix-effect-solid-reactive-idrgb-matrix-effect-solid-reactive
    // https://github.com/search?q=repo%3Aqmk%2Fqmk_firmware%20RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE&type=code
//        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//        #define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
        #define RGBLIGHT_DEFAULT_SPD 255
#endif

#ifdef OLED_ENABLE
        #define SPLIT_OLED_ENABLE
        #define SPLIT_WPM_ENABLE
    /* #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c" */
    #define OLED_FONT_H "keyboards/crkbd/rev1/keymaps/praxis/glcdfont.c"
        #define OLED_FADE_OUT
        #define OLED_FADE_OUT_INTERVAL 15

    // we're on mac
    #define MAIN_T LGUI_T
    #define KC_MAIN KC_LGUI
    #define MOD_TAB MOD_LGUI
#else
    // we're on Windoze
    #define MAIN_T LCTL_T // ends up mapped to Ctrl
    #define KC_MAIN KC_LCTL
    #define MOD_TAB MOD_LALT
    #define MOD_SYM KC_LGUI // ends up mapped to alt
#endif


// squeeze firmware size
#define NO_ACTION_ONESHOT

// no effect from these?
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

