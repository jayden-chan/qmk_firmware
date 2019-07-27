#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_ANSI( /* Base */
                KC_GRV,          KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,      KC_MINS,  KC_EQL,  KC_BSPC,\
                KC_TAB,          KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,      KC_LBRC,  KC_RBRC, KC_BSLASH,\
                KC_ESC,          KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,   KC_QUOT,           KC_ENT, \
                KC_LSFT,         KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,   KC_UP, \
                KC_LCTL,         KC_LGUI,  KC_LALT,                KC_SPC,                         MO(1),    KC_LEFT,   KC_DOWN,           KC_RIGHT),
		[_LAYER1] = LAYOUT_ANSI( /* FN Layer */
				KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
			    KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_MPLY,  KC_MPRV,  KC_MNXT,  RESET  ,\
			    KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_HOME,  KC_END,             KC_TRNS,\
				TO(3),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MUTE,  KC_TRNS,  KC_PGDN,  KC_PSCR,                      KC_TRNS, \
				KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_MPLY,                                KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS),
		[_LAYER2] = LAYOUT_ANSI( /* Dvorak Layout */
                KC_GRV,          KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,      KC_MINS,  KC_EQL,  KC_BSPC,\
                KC_TAB,          KC_QUOT,  KC_COMM,  KC_DOT,KC_P,  KC_Y,  KC_F,    KC_G,  KC_C,    KC_R,     KC_L,      KC_SLSH,  KC_UQL,  KC_BSLASH,\
                KC_ESC,          KC_A,     KC_O,     KC_E,  KC_U,  KC_I,  KC_D,    KC_H,  KC_T,    KC_N,     KC_S,      KC_MINS,           KC_ENT, \
                KC_LSFT,         KC_SCLN,  KC_Q,     KC_J,  KC_K,  KC_X,  KC_B,    KC_M,  KC_W,    KC_V,     KC_Z,      KC_UP, \
                KC_LCTL,         KC_LGUI,  KC_LALT,                KC_SPC,                         MO(3),    KC_LEFT,   KC_DOWN,           KC_RIGHT),
		[_LAYER3] = LAYOUT_ANSI( /* FN Layer (Identical to FN layer 1 other than left shift)*/
				KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
			    KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_MPLY,  KC_MPRV,  KC_MNXT,  RESET  ,\
			    KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_HOME,  KC_END,             KC_TRNS,\
				TO(0),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MUTE,  KC_TRNS,  KC_PGDN,  KC_PSCR,                      KC_TRNS, \
				KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_MPLY,                                KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS),
		};

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {}

void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
	      case _LAYER1:
		    rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false); break;
	      case _LAYER2:
	        rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false); break;
	      case _LAYER3:
	        rgb_matrix_layer_helper(0x00, 0x00, 0xFF, false); break;
	      case _LAYER4:
	        rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false); break;
	    							  }
	                        }
	  if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
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
	  return true;
	}
