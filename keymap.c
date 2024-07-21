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
    _NUM,
    _RNAV,
    _MOUSE,// + F keys
    _LNAV,// + media keys
    _ALTSYM,
    _QWERTY
};

// ; gets mapped to - but S-; stays :, gotta map it explicitly to underscore 
// (but it's swapped on the OS side, so actually send colon!?)
const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_UNDS);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t ltspacetab_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(1,KC_SPC), KC_TAB);
const key_override_t lguispacetab_key_override = ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_SPC), KC_TAB);

const key_override_t** key_overrides = (const key_override_t*[]){
        &underscore_override,
        &delete_key_override,
        &ltspacetab_key_override,
        &lguispacetab_key_override,
        NULL
};

/* enum qk_keycode_defines KC_MAINMOD = KC_LCTL; */
/* enum mods_5bit TAB_MOD = MOD_LALT; */
// LGUI_T(kc) is just MT(MOD_LGUI, kc) !!
#define MAIN_T LGUI_T
#define KC_MAIN KC_LGUI
#define MOD_TAB MOD_LGUI
// :s/LGUI_T/MAIN_T/g
// :s/KC_LGUI/KC_MAIN/g

#include "praxis.c"

// https://github.com/qmk/qmk_firmware/issues/1907
static layer_state_t prev_layer_state;

layer_state_t layer_state_set_user(layer_state_t state) {
#ifndef OLED_ENABLE
    if (get_highest_layer(state) == _LNAV) {
        // Pico Pi onboard LED
        writePinLow(GP25); // off
    } else {
        writePinHigh(GP25); // on
    }
#endif

    /* if (get_highest_layer(state) == _CMDTAB) { */
    /*     register_mods(MOD_TAB); */
    /* } else if (get_highest_layer(prev_layer_state) == _CMDTAB) { */
    /*     unregister_mods(MOD_TAB); */
    /* } */
    if (IS_LAYER_ON_STATE(state, _ALTSYM) && IS_LAYER_OFF_STATE(state, _QWERTY)) {
        register_mods(MOD_LALT);
        state = state | (1 << _QWERTY);
    } else if (IS_LAYER_ON_STATE(prev_layer_state, _ALTSYM) && IS_LAYER_OFF_STATE(state, _ALTSYM)) {
        unregister_mods(MOD_LALT);
        state = state & ~(1 << _QWERTY);
    }
    prev_layer_state = state;
    return state;
}

/* static bool cmdOn = false; */
/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   if (IS_LAYER_ON_STATE(state, _CMDTAB)) { */
/*     cmdOn = true; */
/*   } else if (cmdOn) { */
/*     unregister_mods(MOD_LGUI); */
/*     cmdOn = false; */
/*   } */
/*   return state; */
/* } */

#ifdef OLED_ENABLE
void set_keylog(uint16_t keycode, keyrecord_t *record);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  #ifdef OLED_ENABLE

  // TODO if we're in the tab-as-tab layer, apply whichever modifier is toggled at the top
  rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue() + 64 + rand() % 128, 255, 255);
  if (record->event.pressed) {
    /* set_keylog(keycode, record); */
  }
  #endif

  /* const uint8_t mods = get_mods(); */
  /* //  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#shift--backspace-for-delete-idshift-backspace-for-delete */
  /* if (keycode == KC_BSPC) { */
  /*   static bool delkey_registered; */
  /*   if (record->event.pressed) { */
  /*     if (mods & MOD_MASK_SHIFT) { */
  /*       del_mods(MOD_MASK_SHIFT); */
  /*       register_code(KC_DEL); */
  /*       delkey_registered = true; */
  /*       // Reapplying modifier state so that the held shift key(s) */
  /*       // still work even after having tapped the Backspace/Delete key. */
  /*       set_mods(mods); */
  /*       return false; */
  /*     } */
  /*   } else { */
  /*     // In case KC_DEL is still being sent even after the release of KC_BSPC */
  /*     if (delkey_registered) { */
  /*       unregister_code(KC_DEL); */
  /*       delkey_registered = false; */
  /*       return false; */
  /*     } */
  /*   } */
  /* } else if (cmdOn && keycode == KC_TAB) { */
    /* register_mods(MOD_LGUI); */
  /* } */
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

void oled_render_layer_state(void) {
    // https://www.reddit.com/r/olkb/comments/o5924u/get_heighest_layer_and_default_layer_change/h2pq9rd/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Alpha"), true);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), true);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num"), true);
            break;
        case _RNAV:
            oled_write_ln_P(PSTR("Nav"), true);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), true);
            break;
        case _LNAV:
            oled_write_ln_P(PSTR("LNav"), true);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), true);
            break;
        case _QWERTY:
            if (IS_LAYER_ON(_ALTSYM)) {
              oled_write_ln_P(PSTR("Punct"), true);
            } else {
              oled_write_ln_P(PSTR("QWERT"), false);
            }
            break;
        case _ALTSYM:
            oled_write_ln_P(PSTR("AltSym"), true);
            break;
        case _CMDTAB:
            oled_write_ln_P(PSTR("Cmd"), true);
            break;
    }
    /* if (is_caps_word_on()) { */
    /*   oled_write_P(PSTR("CAPS"), true); */
    /* } else { */
      /* const uint8_t mods = get_mods(); */
      /* if (mods & MOD_MASK_GUI) { */
      /*   oled_write_P(PSTR("Cmd"), true); */
      /* } */
      /* if (mods & MOD_MASK_CTRL) { */
      /*   oled_write_P(PSTR("Ctl"), true); */
      /* } */
      /* if (mods & MOD_MASK_ALT) { */
      /*   oled_write_P(PSTR("Alt"), true); */
      /* } */
      /* if (mods & MOD_MASK_SHIFT) { */
      /*   oled_write_P(PSTR("Sh"), true); */
      /* } */
    /* } */
    /* oled_write_P(PSTR("\n"), false); */
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


#include <unistd.h>

int timer = 0;
/* char wpm_text[5]; */
int x = 31;
int currwpm = 0;
int vert_count = 0;

//=============  USER CONFIG PARAMS  ===============
float max_wpm = 110.0f; //WPM value at the top of the graph window
int graph_refresh_interval = 120; //in milliseconds
int graph_area_fill_interval = 2; //determines how dense the horizontal lines under the graph line are; lower = more dense
int vert_interval = 2; //determines frequency of vertical lines under the graph line
bool vert_line = true; //determines whether to draw vertical lines
int graph_line_thickness = 1; //determines thickness of graph line in pixels
//=============  END USER PARAMS  ===============

void oled_render_wpm(void) {
    //get current WPM value
    currwpm = get_current_wpm();

    //check if it's been long enough before refreshing graph
    if(timer_elapsed(timer) > graph_refresh_interval){

        // main calculation to plot graph line
        x = 32 - ((currwpm / max_wpm) * 32);

        //first draw actual value line
        for(int i = 0; i <= graph_line_thickness - 1; i++){
            oled_write_pixel(126, x + i, true);
        }

        //then fill in area below the value line
        if(vert_line){
            if(vert_count == vert_interval){
                vert_count = 0;
                while(x <= 32){
                    oled_write_pixel(126, x, true);
                    x++;
                }
            } else {
                for(int i = 32; i > x; i--){
                    if(i % graph_area_fill_interval == 0){
                        oled_write_pixel(126, i, true);
                    }
                }
                vert_count++;
            }
        } else {
            for(int i = 32; i > x; i--){
                if(i % graph_area_fill_interval == 0){
                    oled_write_pixel(126, i, true);
                }
            }
        }

        //then move the entire graph one pixel to the LEFT
        oled_pan(true); 

        //refresh the timer for the next iteration
        timer = timer_read();

    }

    //format current WPM value into a printable string
    /* sprintf(wpm_text,"%i", currwpm); */

    //formatting for triple digit WPM vs double digits, then print WPM readout
    if (currwpm > 0) {
        // clear box around the text
        for (uint8_t i = 0; i < 43; i++) {
            oled_write_pixel(i, 22, false);
            oled_write_pixel(i, 23, false);
        }
        for (uint8_t i = 24; i < 32; i++) {
            oled_write_pixel(42, i, false);
        }

        oled_set_cursor(0, 3);
        oled_write_P(PSTR("WPM: "), false);
        oled_set_cursor(4, 3);
        oled_write(get_u8_str(currwpm, ' '), false);
        /* oled_write(wpm_text, false); */
    }
    if(currwpm >= 100){
    } else if (currwpm >= 10){
        oled_write_P(PSTR(" "), false);
    } else if (currwpm > 0) {
        oled_write_P(PSTR("  "), false);
    }
}

void oled_render_solid_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,
        0};
    oled_write_P(crkbd_logo, false);
}
void oled_render_full_logo(void) {
    oled_set_cursor(1, 1);
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_outline_logo(void) {
    static const char PROGMEM font_logo[] = {0x91, 0x92, 0x93, 0x94, 0x95, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0};
    oled_write_P(font_logo, false);
}

void oled_render_kapi_logo(void) {
    static const char PROGMEM font_kapi_logo[2][16] = {
        {0x96, 0x97, 0x98, 0x99, 0x9a, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0},
        {0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0}
    };
    oled_write_P(font_kapi_logo[get_current_wpm() % 2], false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        // needs to be 0 or 180 for logo to render correctly across lines
        return OLED_ROTATION_0;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(0, 0);
        /* oled_render_solid_logo(); */
        oled_render_outline_logo();
        oled_write_ln_P(PSTR("crkbd\n"), false);
        oled_render_layer_state();
        oled_set_cursor(0, 10);
        oled_render_kapi_logo();
    } else {
        /* oled_render_keylog(); */
        oled_render_wpm();
    }
    return false;
}

#endif // OLED_ENABLE

