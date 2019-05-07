#include QMK_KEYBOARD_H
#include <stdio.h>

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

void keyboard_post_init_user(void) {
  debug_enable = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  dprintf("process_record_user:"
          "  event.pressed = %u"
          ", event.key.col = %2u"
          ", event.key.row = %2u"
          ", event.time = %7u"
          ", tap.count = %2u"
          ", tap.interrupted = %u\n"
              , record->event.pressed
              , record->event.key.col
              , record->event.key.row
              , record->event.time
              , record->tap.count
              , record->tap.interrupted);

  if (record->event.pressed) {
    char display[16];
    snprintf(display, 16, "C%uR%u\n", record->event.key.col, record->event.key.row);
    send_string((const char *)display);
  }

  return true;
}
