#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define CHORD 5 // chorded layer
enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

//här blir det combos
enum combos {
	QWF_QUIT,
	RW_HOME,
	SF_END,
	RFT_PGUP,
	RST_PGDN,
	AQ_ESC
};

const uint16_t PROGMEM qwf_combo[] = {KC_Q, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM rw_combo[] = {KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM rft_combo[] = {KC_R, KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM aq_combo[] = {KC_A, KC_Q, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[QWF_QUIT] = COMBO(qwf_combo, RGUI(KC_Q)),	
	[RW_HOME] = COMBO(rw_combo, KC_HOME),	
	[SF_END] = COMBO(sf_combo, KC_END),	
	[RFT_PGUP] = COMBO(rft_combo, KC_PGUP),	
	[RST_PGDN] = COMBO(rst_combo, KC_PGDN),	
	[AQ_ESC]   = COMBO(aq_combo, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TAB   |  F1  |  F2  |  F3  |  F4  |  F5  |GUI \ |           |LSFT Q|  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  Q   |  W   |  F   |  P   |   G  | INS  |           |CTRL+ |  J   |  L   |  U   |  Y   |  Ö   |        |
 * |--------+------+------+------+------+------|      |           |ALT+UP|------+------+------+------+------+--------|
 * |        |  A   |  R   |  S   |  T   | L2(D)|------|           |------| L3(H)|  E   |  E   |  I   |  O   |        |
 * |--------+------+------+------+------+------| DEL  |           |CTRL+ |------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  V   |  B   |      |           |ALT+DN|  K   |  M   |  Å   |  Ä   |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  ALT |  APP | MO3  |LSHFT,|                                       |MO1(.)|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | GUI+\| HOME |       | PLAY | NEXT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | LT4/ | END  |       | PGUP | LT3/ | LT2/ |
 *                                 | BSPC | TAB  |------|       |------| ENT  | SPC  |
 *                                 |      |      | ESC  |       | PGDN |      |      |
 *                                 `--------------------'       `--------------------'
 */
//[BASE] = LAYOUT_ergodox(
//
// left hand
[0] = LAYOUT_ergodox(
  KC_NO,          KC_F1,        KC_F2,         KC_F3,        KC_F4,         KC_F5,      LGUI(KC_BSLS),
  KC_NO,         KC_Q,         KC_W,          KC_F,         LT(4,KC_P),    KC_G,       KC_INS,
  KC_NO,   KC_A,         KC_R,          KC_S,         KC_T,          LT(2,KC_D),    
  KC_NO,         LCTL_T(KC_Z), LALT_T(KC_X),  RALT_T(KC_C), LGUI_T(KC_V),  LT(4,KC_B), KC_DEL,  
  KC_NO,  KC_LALT,  KC_APP,  MO(3),  LSFT_T(KC_COMMA), 
                                                 LGUI(KC_BSLS),         KC_HOME,
						                                                KC_END, 
                                                 KC_BSPC, LT(4,KC_TAB), KC_ESC,
// right hand						
 LSFT(KC_Q),       KC_F6,        KC_F7,         KC_F8,        KC_F9,         KC_F10,          KC_NO, 
 LCA(KC_UP),       KC_J,         KC_L,          KC_U,         KC_Y,          RALT(KC_P),      KC_NO, 
                   LT(3,KC_H),         KC_N,          KC_E,         KC_I,          KC_O,      KC_NO,     
 LCA(KC_DOWN),     RSFT_T(KC_K), RGUI_T(KC_M),  RALT(KC_W),   RALT(KC_Q),    RCTL_T(KC_SLSH), KC_NO, 
                                       LT(1,KC_DOT), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, 
 KC_MPLY,               KC_MFFD, 
 KC_PGUP, 
 KC_PGDN, LT(3,KC_ENT), LT(2,KC_SPC)),
						 
/* Keymap 1: Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//[SYMB] = LAYOUT_ergodox(
// left hand
[1] = LAYOUT_ergodox(
 KC_NO,  KC_NO,   KC_NO,   KC_NO,       KC_NO,           KC_NO,   KC_NO, 
 KC_NO,  KC_ESC,  KC_SCLN, KC_EXCLAIM,  KC_SLSH,         KC_PIPE, KC_NO,
 KC_NO,  KC_LPRN, KC_COLN, KC_MINS,     KC_RPRN,         KC_AT, 
 KC_NO,  KC_CIRC, KC_AMPR, KC_QUOT,     GUI_T(KC_BSLS), KC_GRV,  KC_NO, 
 KC_NO, KC_NO, KC_NO, KC_DEL, KC_LSFT,
                                                 KC_NO,          KC_NO, 
						                 KC_NO, 
					         KC_DEL, KC_NO, KC_NO, 
// right hand						 
 KC_NO,  KC_NO,        KC_NO,  KC_NO, KC_NO,   KC_NO,      KC_NO, 
 KC_NO,  KC_EQL,       KC_7,   KC_8,  KC_9,    LSFT(KC_8), KC_NO, 
         LSFT(KC_EQL), KC_4,   KC_5,  KC_6,    KC_MINS,    KC_NO, 
 KC_NO,  KC_0,         KC_1,   KC_2,  KC_3,    KC_SLSH,    KC_NO,
                       KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO,        KC_NLCK,
 KC_NO,
 KC_NO, KC_NO, KC_NO),


/* Keymap 2: Media and mouse keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//[MDIA] = LAYOUT_ergodox(
//left hand
[2] = LAYOUT_ergodox(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,
 KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT,
                                              KC_TRNS, KC_TRNS,
					               KC_TRNS,
					 KC_BTN1, KC_BTN2, KC_TRNS,
// right hand					
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP,     KC_PGDN,     KC_END,  KC_TRNS, 
          KC_APP,  KC_LEFT, KC_UP,   KC_DOWN,     KC_RGHT,     KC_SLSH,
 KC_TRNS, KC_TRNS, KC_WBAK, RCTL(KC_NO), RCTL(KC_NO), KC_WFWD, KC_TRNS,
                         KC_LGUI, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
 KC_WBAK,          KC_TRNS,
 KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS),
/* Keymap 2: Media and mouse keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
//left hand
[3] = LAYOUT_ergodox(
 KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 KC_NO, KC_TILD, KC_PERC, KC_EXLM, KC_HASH, KC_PIPE, KC_NO,
 KC_NO, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_AT,
 KC_NO, KC_CIRC, KC_AMPR, KC_DLR,  KC_BSLS, KC_EQL,  KC_NO,
   KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LSFT,
                                         KC_NO,        KC_NO,
				                       KC_NO,
				         KC_NO, KC_NO, KC_NO,
// right hand					
 KC_R,  KC_E,  KC_I,  KC_S,  KC_U,  KC_B,   KC_PSCR,
 KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_LALT,
        KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, 
 KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, 
                   KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, 
 KC_NO,          KC_NO,
 KC_NO,
 KC_NO, KC_TRNS, KC_LGUI),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// left hand
[4] = LAYOUT_ergodox(
 KC_NO, KC_NO,          KC_NO,       KC_NO,               KC_NO,                KC_NO,        KC_NO,
 KC_NO, SGUI(KC_Q),     LSFT(KC_INS),       KC_LCTL,             KC_TRNS,              LCA(KC_UP),   KC_NO,
 KC_NO, LGUI(KC_LEFT),  LGUI(KC_UP), LGUI(KC_DOWN),       LGUI(KC_RGHT),        LCA(KC_DOWN),
 KC_NO, KC_PGUP,        KC_PGDN,     LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)), KC_TRNS,      KC_NO,
   KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT,
                                       KC_NO,        KC_NO,
				                     KC_NO,
				       KC_NO, KC_NO, KC_NO,
// right hand				      
 KC_NO, KC_NO,         KC_NO,         KC_NO,       KC_NO,         KC_NO,         KC_NO,
 KC_NO, KC_NO,         KC_NO,         KC_NO,       KC_NO,         KC_NO,         KC_NO,
        LGUI(KC_BSLS), LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT), KC_NO,
 KC_NO, KC_NO,         KC_NO,         KC_NO,       KC_NO,         KC_NO,         KC_NO,
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO,        KC_NO, 
 KC_NO,
 KC_NO, KC_NO, KC_NO)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
