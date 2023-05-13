#include QMK_KEYBOARD_H

enum anne_pro_layers {
    _BASE_LAYER,
    _MOUSE_LAYER,
    _ARROW_LAYER,
    _FUNCTION_LAYER,
    _MEDIA_LAYER,
    _VANILLA_LAYER,
};

enum {
    ESC_GRV_TAP_DANCE,
    CAPS_TAP_DANCE,
    BTN23_TAP_DANCE
};

enum custom_keycodes {
    BOOTLOADER = SAFE_RANGE
};

const uint16_t PROGMEM bootloader_combo[] = {KC_BSPC, KC_RBRC, KC_BSLS, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(bootloader_combo, BOOTLOADER),
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_60_ansi( /* BASE LAYER */
        TD(ESC_GRV_TAP_DANCE),        KC_1,                         KC_2,                          KC_3,   KC_4,                KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,
        KC_TAB,                       KC_Q,                         KC_W,                          KC_E,   KC_R,                KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,       KC_RBRC, KC_BSLS,
        TD(CAPS_TAP_DANCE),           KC_A,                         KC_S,                          KC_D,   KC_F,                KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,
        KC_LSFT,                      KC_Z,                         KC_X,                          KC_C,   KC_V,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
        LM(_VANILLA_LAYER, MOD_LCTL), LM(_VANILLA_LAYER, MOD_LGUI), LM(_FUNCTION_LAYER, MOD_LALT), KC_SPC, TG(_FUNCTION_LAYER), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_MOUSE_LAYER] = LAYOUT_60_ansi( /* MOUSE CONTROL LAYER */
        _______, _______, _______, _______, _______,             _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WH_U, KC_MS_U, KC_WH_D, TD(BTN23_TAP_DANCE), _______, TD(BTN23_TAP_DANCE), KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,             _______, KC_BTN1,             KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,
        _______, _______, _______, _______, _______,             _______, _______,             _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______,             _______, _______,             _______
    ),
    [_ARROW_LAYER] = LAYOUT_60_ansi( /* WASD AS ARROW LAYER*/
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, 
        KC_LCTL, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FUNCTION_LAYER] = LAYOUT_60_ansi( /* FN LAYER */
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MO(_MEDIA_LAYER), _______, _______, _______, _______, _______, _______, _______
    ),
    [_MEDIA_LAYER] = LAYOUT_60_ansi( /* MEDIA LAYER */
        KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______,  _______, _______, _______, _______, KC_AP2_BT_UNPAIR,
        _______,    _______,    _______,    _______,    _______,    _______, KC_MUTE, KC_MPRV, KC_MPLY,  KC_MNXT, _______, KC_BRID, KC_BRIU, _______,
        _______,    _______,    _______,    _______,    _______,    _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  _______, _______, _______,
        _______,    _______,    _______,    _______,    _______,    _______, _______, _______, KC_VOLD,  KC_VOLU, _______, _______,
        _______,    _______,    _______,    _______,    _______,    _______, _______, _______
    ),
    [_VANILLA_LAYER] = LAYOUT_60_ansi( /* VANILLA LAYER */
        _______, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,       KC_RBRC, KC_BSLS,
        _______, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
};

/* Light top most row with the specified color */
void set_first_row_light(uint8_t red, uint8_t green, uint8_t blue) {
    const ap2_led_t color = {
        .p.red   = red,
        .p.green = green,
        .p.blue  = blue,
        .p.alpha = 0xFF,
    };
    const uint8_t row = 0;
    const uint8_t start_col = 0; /* Esc key, left most */
    const uint8_t end_col = 13; /* Backspace key, right most */

    for(uint8_t cur = start_col; cur <= end_col; cur++) {
        ap2_led_mask_set_key(row, cur, color);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    /* Override AP2 LED Profiles with black*/
    ap2_led_set_foreground_color(0x00, 0x00, 0x00);

    /* Add custom lightings on top of the black */
    switch (get_highest_layer(state)) {
        case _BASE_LAYER:
            set_first_row_light(0x00, 0x00, 0x00);
            break;
        case _FUNCTION_LAYER:
            set_first_row_light(0x00, 0xFF, 0x00);
            break;
        case _MOUSE_LAYER:
            set_first_row_light(0x00, 0x88, 0xFF);
            break;
        case _ARROW_LAYER:
            set_first_row_light(0x7A, 0x7A, 0x00);
            break;
        case _VANILLA_LAYER:
            set_first_row_light(0xFF, 0x4D, 0x94);
            break;
        default:
            set_first_row_light(0x00, 0x00, 0x00);
            break;
        }
    return state;
}

void caps_dance_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count)
    {
        case 1:
            if (layer_state_is(_BASE_LAYER)) {
                layer_move(_MOUSE_LAYER);
            } else {
                layer_clear();
            }
            break;
        case 2: 
            layer_move(_ARROW_LAYER);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
  [CAPS_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_dance_finished, NULL),
  [ESC_GRV_TAP_DANCE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
  [BTN23_TAP_DANCE] = ACTION_TAP_DANCE_DOUBLE(KC_BTN2, KC_BTN3)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BOOTLOADER:
            if (record->event.pressed) {
                bootloader_jump();
            } 
            break;
        }
    return true;
};