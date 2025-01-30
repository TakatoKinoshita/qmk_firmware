/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _META,
  _NUM,
  _FUNC,
  _RAISE
};


enum tap_dance {
  _DT_LCP = 0,
  _DT_RCP,
  _DT_MIUN,
  _DT_CLN,
  _DT_EQPL,
  _DT_SLQU,
  _DT_QUOT,
  _DT_CMLA,
  _DT_DTRA,
  _DT_BSPI,
  _DT_GRTL,
};

tap_dance_action_t tap_dance_actions[] = {
  [_DT_LCP ] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LPRN),
  [_DT_RCP ] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RPRN),
  [_DT_MIUN] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
  [_DT_CLN ] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [_DT_EQPL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,  KC_PLUS),
  [_DT_SLQU] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
  [_DT_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [_DT_CMLA] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LABK),
  [_DT_DTRA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,  KC_RABK),
  [_DT_BSPI] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
  [_DT_GRTL] = ACTION_TAP_DANCE_DOUBLE(KC_GRV,  KC_TILD),
};

#define DT_LCP  TD(_DT_LCP)
#define DT_RCP  TD(_DT_RCP)
#define DT_MIUN TD(_DT_MIUN)
#define DT_CLN  TD(_DT_CLN)
#define DT_EQPL TD(_DT_EQPL)
#define DT_SLQU TD(_DT_SLQU)
#define DT_QUOT TD(_DT_QUOT)
#define DT_CMLA TD(_DT_CMLA)
#define DT_DTRA TD(_DT_DTRA)
#define DT_BSPI TD(_DT_BSPI)
#define DT_GRTL TD(_DT_GRTL)


#define TG_META TG(_META)
#define TG_NUM  TG(_NUM)
#define TG_FUNC TG(_FUNC)
#define UP_SPC  LT(_RAISE, KC_SPC)
#define UP_LBRC LT(_RAISE, KC_LBRC)

#define TGL_IME C(KC_SPC)

#define SFT_ALT S(KC_LALT)
#define SFT_TAB S(KC_TAB)
#define SFT_ENT S(KC_ENT)

#define CTL_ALT C(KC_LALT)
#define CTL_TAB C(KC_TAB)
#define CTL_ENT C(KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                   KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    DT_MIUN,                   DT_EQPL, KC_H,    KC_J,    KC_K,    KC_L,    DT_SLQU, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DT_CLN,                    DT_QUOT, KC_N,    KC_M,    DT_CMLA, DT_DTRA, DT_BSPI, 
    TG_NUM,  KC_LALT, KC_TAB,  UP_SPC,  KC_LSFT, KC_ENT,  TGL_IME, XXXXXXX, KC_BSPC, KC_LCTL, UP_LBRC, KC_RBRC, DT_GRTL, TG_FUNC 
  ),

  [_META] = LAYOUT(
    _______, _______, _______, _______, _______, KC_LGUI,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                   _______, _______, _______, _______, _______, _______,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FUNC] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F11,  KC_F12,  _______, _______, _______,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,                   _______, _______, KC_UP,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______
  ),

  [_RAISE] =  LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,                   KC_PLUS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUES, 
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,                   KC_DQUO, _______, _______, KC_LABK, KC_RABK, KC_PIPE, 
    _______, SFT_ALT, SFT_TAB, KC_SPC,  KC_F7,   SFT_ENT, _______, _______, KC_DEL,  KC_CAPS, DT_LCP,  DT_RCP,  KC_TILD, _______
  )

};


const uint16_t PROGMEM combo[] = {TG_NUM, TG_FUNC, COMBO_END};
combo_t key_combos[] = {
  COMBO(combo, TG_META)
};


bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* Left side encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Right side encoder */
    switch (get_highest_layer(layer_state)){
      case _QWERTY:
      case _META:
        if (clockwise) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_RGHT);
        }
        break;

      case _NUM:
        if (clockwise) {
          tap_code(MS_WHLU);
        } else {
          tap_code(MS_WHLD);
        }
        break;

      case _FUNC:
        if (clockwise) {
          tap_code(KC_VOLD);
        } else {
          tap_code(KC_VOLU);
        }
        break;

      case _RAISE:
        if (clockwise) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_DOWN);
        }
        break;
    }
  }

  return false;
}

const rgblight_segment_t PROGMEM rgb_default[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1,  HSV_OFF},
    {1,  49, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1,  HSV_OFF}
);

const rgblight_segment_t PROGMEM rgb_meta[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1,  HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_num[] = RGBLIGHT_LAYER_SEGMENTS(
    {6,  5,  HSV_BLUE},
    {13, 5,  HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_func[] = RGBLIGHT_LAYER_SEGMENTS(
    {6,  5,  HSV_CHARTREUSE},
    {13, 5,  HSV_CHARTREUSE},
    {34, 2,  HSV_CHARTREUSE},
    {39, 1,  HSV_ORANGE},
    {45, 3,  HSV_ORANGE},
    {48, 1,  HSV_CORAL}
);

const rgblight_segment_t PROGMEM rgb_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,  5,  HSV_MAGENTA},
    {6,  5,  HSV_BLUE},
    {13, 5,  HSV_BLUE},
    {22, 1,  HSV_CHARTREUSE},
    {26, 5,  HSV_MAGENTA},
    {32, 4,  HSV_ORANGE},
    {47, 1,  HSV_CHARTREUSE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_default, rgb_qwerty, rgb_meta, rgb_num, rgb_func, rgb_raise
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
  rgblight_set_layer_state(2, layer_state_cmp(state, _META));
  rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(4, layer_state_cmp(state, _FUNC));
  rgblight_set_layer_state(5, layer_state_cmp(state, _RAISE));
  return state;
}

