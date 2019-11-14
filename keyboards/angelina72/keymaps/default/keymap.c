/* Copyright 2019 clomie
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
#include "keymap_jp.h"

enum layer_names {
  _MAC,
  _WIN,
  _RAISE,
  _LOWER,
  _ADJUST,
};

enum custom_keycodes {
  MAC = SAFE_RANGE,
  WIN,
};

#define SPRAISE LT(_RAISE,  KC_SPACE)
#define SPLOWER LT(_LOWER,  KC_SPACE)
#define SPADJST LT(_ADJUST, KC_SPACE)

#define MACZKHK RCMD(KC_SPACE)
#define CTLHOME RCTL(KC_HOME)
#define CTLEND  RCTL(KC_END)
#define CTLPGUP RCTL(KC_PGUP)
#define CTLPGDN RCTL(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAC] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, JP_CIRC, JP_YEN,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,   JP_LBRC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, JP_RBRC, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PSCR,        KC_DEL,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
    KC_LCTL, KC_LALT, KC_LCMD, JP_MEISU,         SPLOWER, MACZKHK,        KC_ENT,  SPRAISE,          JP_MKANA,KC_RCMD, KC_RALT, KC_RCTL  \
  ),

  [_WIN] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, JP_CIRC, JP_YEN,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,   JP_LBRC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, JP_RBRC, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PSCR,        KC_DEL,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
    KC_LCTL, KC_LWIN, KC_LALT, JP_MHEN,          SPLOWER, JP_ZHTG,        KC_ENT,  SPRAISE,          JP_HENK, KC_RALT, KC_APP,  KC_RCTL   \
  ),

  [_RAISE] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
    _______, _______, _______, _______, _______, _______,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          SPADJST, _______,        _______, _______,          _______, _______, _______, _______ \
  ),

  [_LOWER] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
    _______, _______, _______, _______, _______, _______,                          _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,        _______, SPADJST,          KC_0,    KC_DOT,  _______, _______ \
  ),

  [_ADJUST] = LAYOUT( \
    MAC,     _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, WIN,     \
    _______, _______, _______, _______, RESET,   _______,                          RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______, _______, \
    _______, _______, _______, DEBUG,   _______, _______,                          RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,        _______, _______,          _______, _______, _______, _______ \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  dprintf("process_record_user: keycode = %5u"
          ", event.pressed = %u"
          ", event.time = %7u"
          ", tap.count = %2u"
          ", tap.interrupted = %u\n"
              , keycode
              , record->event.pressed
              , record->event.time
              , record->tap.count
              , record->tap.interrupted);

  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        dprintln("Enable MAC mode");
        set_single_persistent_default_layer(_MAC);
      }
      break;
    case WIN:
      if (record->event.pressed) {
        dprintln("Enable WIN mode");
        set_single_persistent_default_layer(_WIN);
      }
      break;
  }
  return true;
}
