#include QMK_KEYBOARD_H

enum my_keycodes {
  KC_00 = SAFE_RANGE
};
/*this is a custom keycode for making 00 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_00:
            if (record->event.pressed) {
                tap_code(KC_P0);
                register_code(KC_P0);
            } else { 
                unregister_code(KC_P0);
            }
            return true;
   }    
   return true;
};
/*this is the code of said 00 */

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
        TG(1),   LCTL(0), KC_MPLY, KC_MUTE,  
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
     This layout is just temporary, will be changed later with VIAL  */ 
    [1] = LAYOUT_numpad_6x4(
        _______, _______, KC_N,   _______,
        _______, KC_A,    KC_B,   KC_C,
        KC_D,    KC_E,    KC_F,   KC_G,
        KC_H,    KC_I,    KC_J,   KC_K,
        KC_L,    KC_M,    KC_N,   KC_O,
        KC_P,    KC_Q,    KC_R,   KC_S
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =  { ENCODER_CCW_CW(KC_LEFT_BRACKET, KC_RIGHT_BRACKET), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MINUS, LSFT(KC_MINUS)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
