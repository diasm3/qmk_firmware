#include QMK_KEYBOARD_H

enum custom_keycodes {
    OBS_START = SAFE_RANGE,
    OBS_STOP,
    OBS_PAUSE,
    OBS_UNPAUSE,
    OBS_SCENE,
    BRUSH_SWITCH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    OBS_START,     OBS_STOP,     OBS_PAUSE,
    OBS_UNPAUSE,   OBS_SCENE,    BRUSH_SWITCH,
    KC_TAB,        _______,      QK_BOOT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case OBS_START:
                SEND_STRING(SS_LCTL(SS_LOPT(SS_LGUI("1"))));
                return false;
            case OBS_STOP:
                SEND_STRING(SS_LCTL(SS_LOPT(SS_LGUI("2"))));
                return false;
            case OBS_PAUSE:
                SEND_STRING(SS_LCTL(SS_LOPT(SS_LGUI("3"))));
                return false;
            case OBS_UNPAUSE:
                SEND_STRING(SS_LCTL(SS_LOPT(SS_LGUI("4"))));
                return false;
            case OBS_SCENE:
                SEND_STRING(SS_LGUI("1"));
                return false;
            case BRUSH_SWITCH:
                SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
                return false;
        }
    }
    return true;
}
