#include QMK_KEYBOARD_H

enum custom_keycodes {
    OBS_START = SAFE_RANGE,
    OBS_STOP,
    OBS_PAUSE,
    OBS_UNPAUSE,
    OBS_SCENE,
    BRUSH_SWITCH,
    OBS_ZOOM_RESET,
};

bool scene_toggle = false; // 전역 변수 위치 수정

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    OBS_START,   OBS_STOP,   OBS_PAUSE,
    OBS_UNPAUSE, OBS_SCENE,  BRUSH_SWITCH,
    KC_TAB,      OBS_ZOOM_RESET, QK_BOOT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case OBS_START:
                // Command+Option+Control+1 (OBS 시작)
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                wait_ms(100);
                register_code(KC_1);
                wait_ms(100);
                unregister_code(KC_1);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                return false;
                
            case OBS_STOP:
                // Command+Option+Control+2
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                wait_ms(100);
                register_code(KC_2);
                wait_ms(100);
                unregister_code(KC_2);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                return false;
                
            case OBS_PAUSE:
                // Command+Option+Control+3
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                wait_ms(100);
                register_code(KC_3);
                wait_ms(100);
                unregister_code(KC_3);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                return false;
                
            case OBS_UNPAUSE:
                // Command+Option+Control+4
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_LCTL);
                wait_ms(100);
                register_code(KC_4);
                wait_ms(100);
                unregister_code(KC_4);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
                return false;
                
            case OBS_SCENE:
                // Command+1 또는 Command+2 토글
                register_code(KC_LGUI);
                wait_ms(100);
                
                if (scene_toggle) {
                    register_code(KC_2);
                    wait_ms(100);
                    unregister_code(KC_2);
                } else {
                    register_code(KC_1);
                    wait_ms(100);
                    unregister_code(KC_1);
                }
                
                unregister_code(KC_LGUI);
                scene_toggle = !scene_toggle; // 상태 반전
                return false;
                
            case BRUSH_SWITCH:
                // Control+Tab (컨트롤 키를 계속 누른 상태에서 탭)
                register_code(KC_CAPS);
                wait_ms(100);
                tap_code(KC_TAB);
                wait_ms(100);
                unregister_code(KC_CAPS);
                return false;
                
            case OBS_ZOOM_RESET:
                // Option+Command+8 (확대 취소)
                register_code(KC_LALT);
                register_code(KC_LGUI);
                wait_ms(100);
                register_code(KC_8);
                wait_ms(100);
                unregister_code(KC_8);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                return false;
        }
    }
    return true;
}