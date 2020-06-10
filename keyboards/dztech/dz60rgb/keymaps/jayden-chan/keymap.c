#include QMK_KEYBOARD_H
#define DEFAULT_LAYER 0
#define DVORAK_LAYER 1
#define CSGO_LAYER 2
#define GTA_LAYER 3
#define FN_LAYER 4
#define FN_CSGO_LAYER 5
#define FN_GTA_LAYER 6

#define QQ_DELAY 6

enum custom_keys {
        CU_TEST = SAFE_RANGE,
        CU_PASS,
        CU_QQ
};

uint16_t q_timer;
bool q_triggered = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [DEFAULT_LAYER] = LAYOUT_ANSI(
                KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,         KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,\
                KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,         KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLASH,\
                KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,         KC_SCLN,  KC_QUOT,            KC_ENT, \
                KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,       KC_SLSH,  KC_UP, \
                KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 MO(FN_LAYER), KC_LEFT,  KC_DOWN,            KC_RIGHT),

        [DVORAK_LAYER] = LAYOUT_ANSI(
                KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,         KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,\
                KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,         KC_L,     KC_SLSH,  KC_EQL,   KC_BSLASH,\
                KC_ESC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,         KC_S,     KC_MINS,            KC_ENT, \
                KC_LSFT,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,         KC_Z,     KC_UP, \
                KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 MO(FN_LAYER), KC_LEFT,  KC_DOWN,            KC_RIGHT),

        [CSGO_LAYER] = LAYOUT_ANSI(
                KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,         KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,\
                KC_TAB,   CU_QQ,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,         KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLASH,\
                KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,         KC_SCLN,  KC_QUOT,            KC_ENT, \
                KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,       KC_SLSH,  KC_UP, \
                KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                            MO(FN_CSGO_LAYER), KC_LEFT,  KC_DOWN,            KC_RIGHT),

        [GTA_LAYER] = LAYOUT_ANSI(
                KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,         KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,\
                KC_TAB,   CU_QQ,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_P7,        KC_P8,    KC_P9,    KC_RBRC,  KC_BSLASH,\
                KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_P4,        KC_P5,    KC_P6,              KC_ENT, \
                KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_P1,    KC_P2,        KC_P3,    KC_UP, \
                KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                            MO(FN_GTA_LAYER),  KC_LEFT,  KC_DOWN,            KC_RIGHT),

        [FN_LAYER] = LAYOUT_ANSI(
                KC_F13,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,        KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
                CU_TEST,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  CU_PASS,      KC_MPLY,  KC_MPRV,  KC_MNXT,  RESET  ,\
                KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLU,  KC_PGUP,      KC_HOME,  KC_END,             DF(CSGO_LAYER),\
      DF(DEFAULT_LAYER),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MUTE,  KC_VOLD,  KC_PGDN,      KC_PSCR,  DF(DVORAK_LAYER), \
                KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_MPLY,                                KC_TRNS,      KC_F14,   KC_RSFT,            KC_RCTL),

        [FN_CSGO_LAYER] = LAYOUT_ANSI(
                KC_F13,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,        KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
                KC_TRNS,  KC_Q,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,       KC_P7,    KC_P8,    KC_P9,    KC_TRNS,\
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P4,        KC_P5,    KC_P6,              DF(GTA_LAYER),\
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,        KC_P3,    KC_P0, \
                KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,      KC_PSLS,  KC_PAST,            KC_PMNS),

        [FN_GTA_LAYER] = LAYOUT_ANSI(
                KC_F13,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,        KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
                KC_TRNS,  KC_Q,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,       KC_P7,    KC_P8,    KC_P9,    KC_TRNS,\
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P4,        KC_P5,    KC_P6,              DF(DEFAULT_LAYER),\
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,        KC_P3,    KC_P0, \
                KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,      KC_PSLS,  KC_PAST,            KC_PMNS),
        };

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {}

void rgb_matrix_indicators_user(void) {
        uint8_t this_led = host_keyboard_leds();
        if (this_led & (1<<USB_LED_CAPS_LOCK)) {
                rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
        }

}

void matrix_init_user(void) {
        //user initialization
}

void matrix_scan_user(void) {
        //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
                case CU_TEST:
                        if (record->event.pressed) {
                                SEND_STRING("testingstring");
                        }
                        break;
                case CU_PASS:
                        if (record->event.pressed) {
                                SEND_STRING("testingstring");
                        }
                        break;
                case CU_QQ:
                        if (record->event.pressed) {
                                q_timer = timer_read();
                                q_triggered = true;
                                SEND_STRING("3");
                        } else if (q_triggered) {
                                while (timer_elapsed(q_timer) < QQ_DELAY);
                                q_triggered = false;
                                SEND_STRING("q");
                        }
                        break;

        }
        return true;
}
