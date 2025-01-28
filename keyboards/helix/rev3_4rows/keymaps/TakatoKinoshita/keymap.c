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
  _NUM,
  _FUNC,
  _RAISE
};


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
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LGUI,                   KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,                   KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SCLN,                   KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BSLS, 
    TG_NUM,  KC_LALT, KC_TAB,  UP_SPC,  SC_LSPO, KC_ENT,  TGL_IME, XXXXXXX, KC_BSPC, SC_RCPC, UP_LBRC, KC_RBRC, KC_GRV,  TG_FUNC 
  ),

  [_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                   _______, _______, _______, _______, _______, _______,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [_FUNC] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F11,  KC_F12,  _______, _______, _______,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] =  LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,                   KC_PLUS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUES, 
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN,                   KC_DQUO, _______, _______, KC_LABK, KC_RABK, KC_PIPE, 
    _______, SFT_ALT, SFT_TAB, KC_SPC,  KC_LSFT, SFT_ENT, _______, XXXXXXX, KC_DEL,  SFT_CTL, KC_LCBR, KC_RCBR, KC_TILD, _______
  )

};

#define ZM_IN LCTL(MS_WHLU)
#define ZM_OUT LCTL(MS_WHLD)

//#if defined(ENCODER_MAP_ENABLE)
//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//    [_QWERTY] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_RGHT, KC_LEFT)},
//    [_NUM]    = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_UP,   KC_DOWN)},
//    [_FUNC]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
//    [_RAISE]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(ZM_IN,   ZM_OUT) },
//};
//#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* Left side encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_LEFT);
    } else {
      tap_code(KC_RGHT);
    }
  }
    
//  if (index == 1) { /* Right side encoder */
//    switch (get_highest_layer(layer_state)){
//      case _QWERTY:
//        if (clockwise) {
//          tap_code(KC_LEFT);
//        } else {
//          tap_code(KC_RGHT);
//        }
//        break;
//
//      case _NUM:
//        if (clockwise) {
//          tap_code(MS_WHLU);
//        } else {
//          tap_code(MS_WHLD);
//        }
//        break;
//
//      case _FUNC:
//        if (clockwise) {
//          tap_code(KC_VOLU);
//        } else {
//          tap_code(KC_VOLD);
//        }
//        break;
//
//      case _RAISE:
//        if (clockwise) {
//          tap_code16(C(MS_WHLU));
//        } else {
//          tap_code16(C(MS_WHLD));
//        }
//        break;
//    }
//
//    return true;
//  }

  return false;
}

