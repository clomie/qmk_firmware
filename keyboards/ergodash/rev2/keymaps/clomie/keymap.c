#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MC_DEBG,
};

#define SHIFTSP MT(MOD_LSFT, KC_SPC)

enum user_macro {
  UM_RAISE_KANA_HENKAN,
  UM_LOWER_EISU_MUHENKAN,
};
#define RAISE MACROTAP(UM_RAISE_KANA_HENKAN)
#define LOWER MACROTAP(UM_LOWER_EISU_MUHENKAN)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1!   |   2"   |   3#   |   4$   |   5%   |   6&   |                        |   6&   |   7'   |   8(   |   9)   |    0   |   -=   |   ^~   |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * | Tab  |    Q   |    W   |    E   |    R   |    T   |   [{   |                        |   ]}   |    Y   |    U   |    I   |    O   |    P   |   @`   |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * |      |    A   |    S   |    D   |    F   |    G   | PrtScr |                        |    B   |    H   |    J   |    K   |    L   |   ;+   |   :*   |
   * |------+--------+--------+--------+--------+--------+---------------------------------+--------+--------+--------+--------+--------+--------+--------|
   * | Shift|    Z   |    X   |    C   |    V   |    B   |        |                        |  Bcksp |    N   |    M   |   ,>   |   .>   |   /?   |   \_   |
   * |---------------+--------+--------+--------+--------+--------+--------+------+--------+--------+--------+--------+--------+--------+-----------------|
   * | Ctrl |   Alt  |   GUI  |   Alt  ||||||||||  Lower |Spc/Shft|  Enter ||||||||  Enter |Spc/Shft|  Raise ||||||||||  Left  |  Down  |   Up   |  Right |
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, JP_CIRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_LBRC,                          JP_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT,   \
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PSCR,                          KC_B,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,                          KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
    KC_LCTL, KC_LALT, KC_LWIN, KC_LALT,          LOWER,   SHIFTSP, KC_ENT,         KC_ENT,  SHIFTSP, RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |                        |   F6   |   F7   |   F8   |   F9   |   F10  |   F11  |   \|   |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * | Tab  |        |        |        |        |        |        |                        |        |        |  Home  |        |  PgUp  |   F12  |   [{   |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * |      |        |        |        |        |        |        |                        |        |        |   End  |   ↑   |  PgDn  |        |   ]}   |
   * |------+--------+--------+--------+--------+--------+---------------------------------+--------+--------+--------+--------+--------+--------+--------|
   * | Shift|        |        |        |        |        |        |                        |   Del  |        |   ←   |   ↓   |   →   |        |        |
   * |---------------+--------+--------+--------+--------+--------+--------+------+--------+--------+--------+--------+--------+--------+-----------------|
   * | Ctrl |        |   GUI  |   Alt  |||||||||| Adjust |        |        ||||||||        |        |        ||||||||||  Left  |  Down  |   Up   |  Right |
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  JP_YEN,  \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_PGUP, KC_F12,  JP_LBRC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, KC_END,  KC_UP,   KC_PGDN, XXXXXXX, JP_RBRC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                          KC_DEL,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, _______, _______, _______,          ADJUST,  _______, _______,        _______, KC_LCTL, _______,          XXXXXXX, XXXXXXX, XXXXXXX, KC_NO    \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   * |      |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |                        |   F6   |   F7   |   F8   |   F9   |   F10  |   F11  |   \|   |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * |      |        |        |        |        |        |        |                        |        |    %   |    7   |    8   |    9   |   F12  |        |
   * |------+--------+--------+--------+--------+--------+--------+------------------------+--------+--------+--------+--------+--------+--------+--------|
   * |      |        |        |        |        |        |        |                        |        |    /   |    4   |    5   |    6   |    -   |        |
   * |------+--------+--------+--------+--------+--------+---------------------------------+--------+--------+--------+--------+--------+--------+--------|
   * |      |        |        |        |        |        |        |                        |        |    *   |    1   |    2   |    3   |    +   |        |
   * |---------------+--------+--------+--------+--------+--------+--------+------+--------+--------+--------+--------+--------+--------+-----------------|
   * |      |        |        |        ||||||||||        |        |        ||||||||        |        | Adjust ||||||||||    0   |    .   |    ,   |        |
   * ,----------------------------------------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    JP_ZHTG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 , KC_F12,  JP_YEN,  \
    _______, _______, _______, _______, _______, _______, _______,                          XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PGUP, KC_PSCR, \
    _______, _______, _______, _______, _______, _______, _______,                          XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PGDN, XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______,                          KC_BSPC, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, \
    _______, _______, _______, _______,          _______, _______, _______,        XXXXXXX, XXXXXXX, ADJUST,           KC_0,    KC_DOT,  KC_COMM, KC_NO    \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Mac |      |      |      |      |      |      |                    |      |      |      |      |      |      |  Win |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Debug| Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    AG_SWAP, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, AG_NORM, \
    MC_DEBG, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, _______,                         _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC , _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,       _______, _______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MC_DEBG:
      if (record->event.pressed) {
        debug_enable = !debug_enable;
        if (debug_enable) {
          dprint("DEBUG: enabled.\n");
        }
      }
      break;
  }
  return true;
}


// Macro actions for each corresponding ID.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  dprintf("action_get_macro   : id = %u"
          ", opt = %u"
          ", event.pressed = %u"
          ", event.time = %7u"
          ", tap.count = %2u"
          ", tap.interrupted = %u\n"
              , id
              , opt
              , record->event.pressed
              , record->event.time
              , record->tap.count
              , record->tap.interrupted);

  switch(id) {
    case UM_RAISE_KANA_HENKAN:
      // Hold: RAISE, Tap: LANG1(かな on MaxOSX) & INT4(変換 on Windows)
      return MACRO_TAP_HOLD_LAYER(record, MACRO(T(LANG1), T(INT4), END), _RAISE);
    case UM_LOWER_EISU_MUHENKAN:
      // Hold: LOWER, Tap: LANG2(英数 on MaxOSX) & INT5(無変換 on Windows)
      return MACRO_TAP_HOLD_LAYER(record, MACRO(T(LANG2), T(INT5), END), _LOWER);
  }
  return MACRO_NONE;
}
