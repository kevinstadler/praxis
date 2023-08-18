/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _SYM,
  /* _NUM, */
  _RNAV,
  _LNAV,
  _CMDTAB,
  _GAMING
};

/* const key_override_t coln_key_override = */
/*     ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_ASTR); // Shift - is * */

/* const key_override_t** key_overrides = (const key_override_t*[]){ */
/*     &coln_key_override, */
/*     NULL */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TG(1), KC_ESC, LCTL_T(KC_A), LALT_T(KC_S), LT(4,KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), LT(4,KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT, TT(3), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TT(3), LT(7,KC_BSPC), LGUI_T(KC_TAB), LT(2,KC_ENT), LT(6,KC_ENT), LT(1,KC_SPC), KC_BSPC),
	[1] = LAYOUT_split_3x6_3(KC_GRV, KC_GT, KC_LBRC, KC_UNDS, KC_RBRC, KC_PERC, KC_CIRC, KC_7, KC_8, KC_9, KC_EQL, KC_TRNS, DT_UP, KC_LT, KC_LPRN, KC_MINS, SC_RSPC, KC_GT, KC_PLUS, RSFT_T(KC_4), KC_5, KC_6, KC_SCLN, KC_BSLS, DT_DOWN, DT_PRNT, KC_LCBR, KC_ASTR, KC_RCBR, KC_DOT, KC_COMM, KC_1, KC_2, KC_3, KC_SLSH, KC_EQL, KC_BSPC, KC_TAB, KC_ENT, KC_0, KC_SPC, KC_BSPC),
	[2] = LAYOUT_split_3x6_3(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, SGUI(KC_3), SGUI(KC_4), KC_NO, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_split_3x6_3(KC_F14, KC_F15, KC_DEL, KC_UP, KC_TAB, KC_EQL, KC_MPRV, KC_MPLY, KC_MNXT, 0x7F, KC_VOLD, KC_VOLU, KC_TRNS, LCTL_T(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, RGB_TOG, RSFT_T(RGB_MOD), LT(4,RGB_SPI), RALT_T(RGB_HUI), RCTL_T(RGB_VAI), KC_MUTE, KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_NO, KC_NO, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_VAD, KC_TRNS, LALT_T(KC_BSPC), LT(4,KC_SPC), LSFT_T(KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_split_3x6_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_MINS), LGUI(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, LGUI(KC_BSPC), KC_TAB, LGUI(KC_ENT), KC_TRNS, LGUI(KC_0), KC_TRNS),
	[5] = LAYOUT_split_3x6_3(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TG(5), KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(3), KC_LALT, KC_SPC, LT(1,KC_ENT), LT(1,KC_ENT), LCTL_T(KC_SPC), KC_BSPC),
	[6] = LAYOUT_split_3x6_3(KC_GRV, KC_SLSH, KC_7, KC_8, KC_9, KC_PEQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_SCLN, KC_4, KC_5, KC_6, KC_PPLS, KC_NO, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS, KC_COMM, KC_1, KC_2, KC_3, KC_DOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_SPC, KC_P0, KC_NO, KC_NO, KC_NO),
	[7] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_BTN3)
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

/* const uint16_t PROGMEM capslock_combo[] = {LT(4,KC_D), LT(4,KC_K), COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = { */
/*     COMBO(capslock_combo, KC_CAPS) */
/* }; */

/* static layer_state_t prev_layer_state; */
static bool cmdOn = false;
layer_state_t layer_state_set_user(layer_state_t state) {
	/* if (state == (1 << _CMDTAB)) { */
  if (IS_LAYER_ON_STATE(state, _CMDTAB)) {
		/* register_mods(MOD_LGUI); */
		cmdOn = true;
	} else if (cmdOn) {//prev_layer_state == (1 << _CMDTAB)) {
		unregister_mods(MOD_LGUI);
	  cmdOn = false;
	}
	/* prev_layer_state = state; */
	return state;
}

#ifdef OLED_ENABLE
void set_keylog(uint16_t keycode, keyrecord_t *record);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  #ifdef OLED_ENABLE

  // TODO if we're in the tab-as-tab layer, apply whichever modifier is toggled at the top
	rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue() + 64 + rand() % 128, 255, 255);
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  #endif

  const uint8_t mods = get_mods();
	//  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#shift--backspace-for-delete-idshift-backspace-for-delete
  if (keycode == KC_BSPC) {
    static bool delkey_registered;
    if (record->event.pressed) {
      if (mods & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        register_code(KC_DEL);
        delkey_registered = true;
        // Reapplying modifier state so that the held shift key(s)
        // still work even after having tapped the Backspace/Delete key.
        set_mods(mods);
        return false;
      }
    } else {
      // In case KC_DEL is still being sent even after the release of KC_BSPC
      if (delkey_registered) {
        unregister_code(KC_DEL);
        delkey_registered = false;
        return false;
      }
    }
	// TODO make Shift+Up/Down always be PgUp/PgDn?
	} else if (cmdOn && keycode == KC_TAB) {
		register_mods(MOD_LGUI);
	}
  return true;
}


#ifndef OLED_ENABLE
void keyboard_post_init_user(void) {
	// Pico Pi onboard LED
	setPinOutput(GP25);
  writePinHigh(GP25);
}

#else
#include <stdio.h>

#define KEYLOGGER_LENGTH 70
char keylog_str[KEYLOGGER_LENGTH+1];

void keyboard_post_init_user(void) {
	/* rgblight_set_speed_noeeprom(255); */
  debug_enable = true;
  debug_matrix = true;

  for (uint8_t i = 0; i < KEYLOGGER_LENGTH; i++) {
    keylog_str[i] = ' ';
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        case KC_ENTER:
        case KC_ESC:
          return false;
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  } else {
		// needs to be 0 or 180 for logo to render correctly across lines
    return OLED_ROTATION_0; // flips the display 180 degrees if offhand
	}
}

void oled_render_layer_state(void) {
    // TODO don't get highest layer, but check if any of the layers is on but don't render Cmd layer unless it's the only thing that's active
    switch (get_highest_layer(layer_state)) {
    /* switch (layer_state) { */
        case _BASE:
            oled_write_P(PSTR("Alpha"), true);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), true);
            break;
        /* case (1 << _NUM): */
        /*     oled_write_ln_P(PSTR("Num"), true); */
        /*     break; */
        case _RNAV:
            oled_write_ln_P(PSTR("Nav"), true);
            break;
        case _LNAV:
            oled_write_ln_P(PSTR("LNav"), true);
            break;
        case _CMDTAB:
            oled_write_ln_P(PSTR("Cmd"), true);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), true);
            break;
    }
    /* if (is_caps_word_on()) { */
    /*   oled_write_P(PSTR("CAPS"), true); */
    /* } else { */
      const uint8_t mods = get_mods();
      if (mods & MOD_MASK_SHIFT) {
        oled_write_P(PSTR("Sh"), true);
      }
      if (mods & MOD_MASK_ALT) {
        oled_write_P(PSTR("Al"), true);
      }
      if (mods & MOD_MASK_GUI) {
        oled_write_P(PSTR("Cm"), true);
      }
      if (mods & MOD_MASK_CTRL) {
        oled_write_P(PSTR("Ct"), true);
      }
    /* } */
    oled_write_P(PSTR("\n"), false);
}


static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 'C', ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', 'H', ' ', ' ', ' ', ' ', 'R',  // 4x
    'L', 'D', 'U', ' ', ' ', ' ', ' ', ' ', ' ', '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }
  if (keycode < 0xFF) {
    for (uint8_t i = 1; i < KEYLOGGER_LENGTH; i++) {
      keylog_str[i-1] = keylog_str[i];
    }
    keylog_str[KEYLOGGER_LENGTH-1] = pgm_read_byte(&code_to_name[keycode]);
  }

  // update keylog
  /* snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", */
  /*          record->event.key.row, record->event.key.col, */
  /*          keycode, name); */
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

