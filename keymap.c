#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │TG1│LC0│Ply│Mut│
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │Bsp│
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ - │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ + │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │Ent│
     * ├───┼───┼───┼───┤
     * │ 0 │00 │Spc│ . │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x4(
        TG(1),   LCTL(0), KC_MPLAY, KC_MUTE,  
        KC_NUM,  KC_PSLS, KC_PAST, KC_BSPC,
        KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_00,   KC_SPC,  KC_PDOT
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │TG1│LC0│ N │Mut│
     * ├───┼───┼───┼───┤
     * │Num│ A │ B │ C │
     * ├───┼───┼───┼───┤
     * │ D │ E │ F │ G │
     * ├───┼───┼───┼───┤
     * │ H │ I │ J │ K │
     * ├───┼───┼───┤───┤
     * │ L │ M │ N │ O │
     * ├───┼───┼───┼───┤
     * │ P │ Q │ R │ S │
     * └───┴───┴───┴───┘
     */
    [1] = LAYOUT_numpad_6x4(
        _______, _______, KC_N,   _______,
        _______, KC_A,    KC_B,   KC_C,
        KC_D,    KC_E,    KC_F,   KC_G,
        KC_H,    KC_I,    KC_J,   KC_K,
        KC_L,    KC_M,    KC_N,   KC_O,
        KC_P,    KC_Q,    KC_R,   KC_S
    )
}

enum my_keycodes {
  KC_00 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode){ 
    case KC_00:
            if (record->event.pressed) {
                tap_code(KC_P0);
                register_code(KC_P0);
            } else { 
                unregister_code(KC_P0);
            }
            return false;
   }    
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { encoder0(KC_MS_WH_DOWN, KC_MS_WH_UP), encoder1(LCTL(KC_PPLS), LCTL(KC_PMNS)), encoder2(KC_LEFT, KC_RIGHT), encoder3(KC_VOLD, KC_VOLU) },
    [1] =  { encoder0(KC_LEFT_BRACKET, KC_RIGHT_BRACKET), encoder1(KC_MS_WH_UP, KC_MS_WH_DOWN), encoder2(KC_MINUS, LSFT(KC_MINUS)), encoder3(KC_VOLD, KC_VOLU) }
};
#endif
