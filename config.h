#pragma once

#define MASTER_LEFT
#define SPLIT_USB_DETECT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
// 165 still resulted in fi rolls instead of I, so reduce further to trigger shift more easily
#define TAPPING_TERM 145
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 1

#define COMBO_COUNT 1

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    //#define ENABLE_RGB_MATRIX_SPLASH

		// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#rgb-matrix-effect-solid-reactive-idrgb-matrix-effect-solid-reactive
    // https://github.com/search?q=repo%3Aqmk%2Fqmk_firmware%20RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE&type=code
		#define ENABLE_RGB_MATRIX_SOLID_SPLASH
//		#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//		#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
		#define RGBLIGHT_DEFAULT_SPD 255
#endif

#ifdef OLED_ENABLE
		#define SPLIT_OLED_ENABLE
		#define SPLIT_WPM_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif
