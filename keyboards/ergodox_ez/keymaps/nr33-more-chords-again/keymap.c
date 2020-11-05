#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
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
	ACOMMA_ESC,
	ARNE_ESC,
	ENT_TAB,
//	ENS_COLON,
//	ENR_SCOLON,
	EIO_ENTER,
	EIW_LCBR, // {
	EIF_RCBR, // }
	EIR_LBRC, // [
	EIS_RBRC, // ]
	EIA_LPRN, // (
	EIT_RPRN, // )

};

const uint16_t PROGMEM qwf_combo[] =    {KC_Q, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM rw_combo[] =     {KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM sf_combo[] =     {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM acomma_combo[] = {KC_A, KC_COMMA, COMBO_END};
const uint16_t PROGMEM arne_combo[] =   {KC_A, KC_R, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ent_combo[] =    {KC_E, KC_N, KC_T, COMBO_END};
//const uint16_t PROGMEM ens_combo[] =    {KC_E, KC_N, KC_S, COMBO_END};
//const uint16_t PROGMEM enr_combo[] =    {KC_E, KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM eio_combo[] =    {KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM eiw_combo[] =    {KC_E, KC_I, KC_W, COMBO_END};
const uint16_t PROGMEM eif_combo[] =    {KC_E, KC_I, KC_F, COMBO_END};
const uint16_t PROGMEM eir_combo[] =    {KC_E, KC_I, KC_R, COMBO_END};
const uint16_t PROGMEM eis_combo[] =    {KC_E, KC_I, KC_S, COMBO_END};
const uint16_t PROGMEM eia_combo[] =    {KC_E, KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM eit_combo[] =    {KC_E, KC_I, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[QWF_QUIT]   = COMBO(qwf_combo,    SGUI(KC_Q)),	
	[RW_HOME]    = COMBO(rw_combo,     KC_HOME),	
	[SF_END]     = COMBO(sf_combo,     KC_END),	
	[ACOMMA_ESC] = COMBO(acomma_combo, KC_ESC),
	[ARNE_ESC]   = COMBO(arne_combo,   KC_ESC),
	[ENT_TAB]  = COMBO(ent_combo,      KC_TAB),
//	[ENS_COLON]  = COMBO(ens_combo,    KC_COLON),
//	[ENR_SCOLON] = COMBO(enr_combo,    KC_SCOLON),
	[EIO_ENTER]  = COMBO(eio_combo,    KC_ENTER),
	[EIW_LCBR]  = COMBO(eiw_combo,    SE_LCBR),
	[EIF_RCBR]  = COMBO(eif_combo,    SE_RCBR),
	[EIR_LBRC]  = COMBO(eir_combo,    SE_LBRC),
	[EIS_RBRC]  = COMBO(eis_combo,    SE_RBRC),
	[EIA_LPRN]  = COMBO(eia_combo,    SE_LPRN),
	[EIT_RPRN]  = COMBO(eit_combo,    SE_RPRN),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TAB   |   1  |   2  |   3  |   4  |   5  |GUI \ |           |C+A+UP|   6  |   7  |   8  |   9  |  10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Esc   |  Q   |  W   |  F   |  P   |   G  | INS  |           |CTRL+ |  J   |  L   |  U   |  Y   |  Ö   |   "    |
 * |--------+------+------+------+------+------|      |           |ALT+DN|------+------+------+------+------+--------|
 * |   ,    |  A   |  R   |  S   |  T   | L2(D)|------|           |------|  H   |  E   |  E   |  I   |  O   |   .    |
 * |--------+------+------+------+------+------| DEL  |           |MO 3  |------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  V   |  B   |      |           |      |  K   |  M   |  Å   |  Ä   |  .   |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  ALT |  APP | MO3  |LSHFT |                                       | MO1  |      |      |      |      |
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
  KC_NO,      SE_1,         SE_2,          SE_3,         SE_4,          SE_5,       LGUI(KC_BSLS),
  KC_ESC,     KC_Q,         KC_W,          KC_F,         LT(4,KC_P),    KC_G,       KC_INS,
  SE_COMM,    KC_A,         KC_R,          KC_S,         KC_T,          LT(2,KC_D),    
  SE_ACUT,    LCTL_T(KC_Z), LALT_T(KC_X),  RALT_T(KC_C), LGUI_T(KC_V),  LT(4,KC_B), KC_DEL,  
  KC_NO,      KC_LALT,  KC_APP,  MO(3),  KC_LSFT, 
                                                 LGUI(KC_BSLS),         KC_HOME,
						                                                KC_END, 
                                                 KC_BSPC, LT(4,KC_TAB), KC_ESC,
// right hand						
  KC_NO,         KC_6,         KC_7,          KC_8,         KC_9,          KC_0,            KC_NO, 
  LCA(KC_UP),    KC_J,         KC_L,          KC_U,         KC_Y,          SE_ODIA,         SE_QUOT, 
                 KC_H,         KC_N,          KC_E,         KC_I,          KC_O,            SE_DOT,     
  LCA(KC_DOWN),         RSFT_T(KC_K), RGUI_T(KC_M),  SE_ARNG,     SE_ADIA,       RCTL_T(SE_DOT), SE_SLSH, 
                                       MO(1), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, 
 KC_MPLY,               KC_MFFD, 
 KC_PGUP, 
 KC_PGDN, LT(3,KC_ENT), LT(2,KC_SPC)),
						 
/* Keymap 1: Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   {    |  (   |  [   |  ]   |  )   |  @   |------|           |------|      |      |      |      |      |   }    |
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
 KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 SE_TILD, SE_BSLS, SE_PERC, SE_EXLM, SE_HASH, SE_PIPE, KC_NO,
 SE_LCBR, SE_LPRN, SE_LBRC, SE_RBRC, SE_RPRN, SE_AT,
 SE_DIAE, SE_CIRC, SE_AMPR, SE_DLR,  SE_LABK, SE_RABK,  KC_NO,
   KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LSFT,
                                         KC_NO,        KC_NO,
				                       KC_NO,
				         KC_DEL, KC_NO, KC_NO,

// right hand						 
 KC_NO,  KC_NO,        KC_NO,  KC_NO, KC_NO,   KC_NO,      KC_NO, 
 KC_NO,  SE_EQL,       SE_7,   SE_8,  SE_9,    SE_ASTR,    SE_DQUO, 
         SE_PLUS,      SE_4,   SE_5,  SE_6,    SE_MINS,    SE_RCBR, 
 KC_NO,  SE_0,         SE_1,   SE_2,  SE_3,    SE_SLSH,    SE_DOT,
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
 KC_NO,  KC_NO,   KC_NO,   KC_NO,       KC_NO,           KC_NO,   KC_NO, 
 KC_NO,  KC_ESC,  SE_SCLN, SE_EXLM,  SE_SLSH,         SE_PIPE, KC_NO,
 KC_NO,  SE_LPRN, SE_COLN, SE_MINS,     SE_RPRN,         SE_AT, 
 KC_NO,  SE_CIRC, SE_AMPR, SE_QUOT,     GUI_T(KC_BSLS),  SE_GRV,  KC_NO, 
            KC_NO, KC_NO, KC_NO, KC_DEL, KC_LSFT,
                                                 KC_NO,          KC_NO, 
						                 KC_NO, 
					         KC_DEL, KC_NO,  KC_NO, 
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
