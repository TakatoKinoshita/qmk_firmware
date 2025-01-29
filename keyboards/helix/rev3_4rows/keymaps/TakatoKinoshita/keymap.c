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


#define TG_META TG(_META)
#define TG_NUM TG(_NUM)
#define TG_FUNC TG(_FUNC)
#define UP_SPC LT(_RAISE, KC_SPC)
#define UP_LBRC LT(_RAISE, KC_LBRC)

#define TGL_IME C(KC_SPC)

#define SFT_ALT KC_LSFT | KC_LALT
#define SFT_TAB S(KC_TAB)
#define SFT_ENT S(KC_ENT)
#define SFT_CTL KC_LSFT | KC_LCTL


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                   KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,                   KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SCLN,                   KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BSLS, 
    TG_NUM,  KC_LALT, KC_TAB,  UP_SPC,  SC_LSPO, KC_ENT,  TGL_IME, XXXXXXX, KC_BSPC, SC_RCPC, UP_LBRC, KC_RBRC, KC_GRV,  TG_FUNC 
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
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______
  ),

  [_RAISE] =  LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,                   KC_PLUS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUES, 
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,                   KC_DQUO, _______, _______, KC_LABK, KC_RABK, KC_PIPE, 
    _______, SFT_ALT, SFT_TAB, KC_SPC,  KC_LSFT, SFT_ENT, _______, _______, KC_DEL,  SFT_CTL, KC_LCBR, KC_RCBR, KC_TILD, _______
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

const rgblight_segment_t PROGMEM rgb_qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  1,  HSV_WHITE},
    {1,  49, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_meta[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  50, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_num[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  6,  HSV_BLUE},
    {6,  5,  HSV_ORANGE},
    {11, 2,  HSV_BLUE},
    {13, 5,  HSV_ORANGE},
    {18, 32, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_func[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,  6,  HSV_CHARTREUSE}, 
    {6,  5,  HSV_PURPLE},
    {11, 2,  HSV_CHARTREUSE},
    {13, 5,  HSV_PURPLE},
    {18, 16, HSV_CHARTREUSE},
    {34, 2,  HSV_PURPLE},
    {36, 3,  HSV_CHARTREUSE},
    {39, 1,  HSV_CORAL},
    {40, 5,  HSV_CHARTREUSE},
    {45, 3,  HSV_CORAL},
    {48, 2,  HSV_CHARTREUSE}
);

const rgblight_segment_t PROGMEM rgb_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 50, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_qwerty, rgb_meta, rgb_num, rgb_func, rgb_raise
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
  rgblight_set_layer_state(_META, layer_state_cmp(state, _META));
  rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(_FUNC, layer_state_cmp(state, _FUNC));
  rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
  return state;
}

