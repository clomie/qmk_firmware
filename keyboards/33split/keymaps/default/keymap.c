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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define _NORMAL 0
#define _RAISE 1

#define RSESC LT(_RAISE, KC_ESC)
#define KC_UNDO LCMD(KC_Z)
#define KC_REDO SCMD(KC_Z)
#define KC_SAVE LCMD(KC_S)
#define KC_VIA SCMD(KC_V)
#define CTL_TPV LCMD_T(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAL] = LAYOUT( /* Base */
    RSESC,   KC_D,    KC_BSPC,        RGB_MOD,   RGB_TOG,  RGB_HUI,\
    KC_UNDO, KC_X,    CTL_TPV,        RGB_RMOD,  KC_E,     KC_F\
  ),
  [_RAISE] = LAYOUT( /* Base */
    RSESC,   KC_SAVE, KC_M,           RGB_MOD,   RGB_TOG,  RGB_HUI,\
    KC_REDO, KC_X,    KC_VIA,         RGB_RMOD,  KC_E,     KC_F\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
