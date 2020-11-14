#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _I3SWAY 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};
//här blir det combos
enum combos {
	QWF_QUIT,
	RW_HOME,
	SF_END,
	ACOMMA_ESC,
	ARNE_ESC,
	TD_ESC,
	ENT_TAB,
	NL_COLON, // :
	EU_DOT,   // .
        IY_COMMA, // ,
	HN_TAB,
        RSE_ENTER,
	RSI_TAB,
	RSU_QUOT, // '
        RSY_DQUOT,// "
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
const uint16_t PROGMEM hn_combo[] =     {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM td_combo[] =     {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM acomma_combo[] = {KC_A, KC_COMMA, COMBO_END};
const uint16_t PROGMEM arne_combo[] =   {KC_A, KC_R, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ent_combo[] =    {KC_E, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM nl_combo[] =     {KC_N, KC_L, COMBO_END};
const uint16_t PROGMEM eu_combo[] =     {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM iy_combo[] =     {KC_I, KC_Y, COMBO_END};
const uint16_t PROGMEM rse_combo[] =    {KC_R, KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM rsi_combo[] =    {KC_R, KC_S, KC_I, COMBO_END};
const uint16_t PROGMEM rsu_combo[] =    {KC_R, KC_S, KC_U, COMBO_END};
const uint16_t PROGMEM rsy_combo[] =    {KC_R, KC_S, KC_Y, COMBO_END};
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
	[TD_ESC]     = COMBO(td_combo,     KC_ESC),
	[ENT_TAB]    = COMBO(ent_combo,    KC_TAB),
	[NL_COLON]   = COMBO(nl_combo,     SE_COLN),
	[EU_DOT]     = COMBO(eu_combo,     SE_DOT),
	[IY_COMMA]   = COMBO(iy_combo,     SE_COMM),
	[HN_TAB]     = COMBO(hn_combo,     KC_TAB),
	[RSE_ENTER]  = COMBO(rse_combo,    KC_ENTER),
	[RSI_TAB]    = COMBO(rsi_combo,    KC_TAB),
	[RSU_QUOT]   = COMBO(rsu_combo,    SE_QUOT),
	[RSY_DQUOT]  = COMBO(rsy_combo,    SE_DQUO),
	[EIO_ENTER]  = COMBO(eio_combo,    KC_ENTER),
	[EIW_LCBR]   = COMBO(eiw_combo,    SE_LCBR),
	[EIF_RCBR]   = COMBO(eif_combo,    SE_RCBR),
	[EIR_LBRC]   = COMBO(eir_combo,    SE_LBRC),
	[EIS_RBRC]   = COMBO(eis_combo,    SE_RBRC),
	[EIA_LPRN]   = COMBO(eia_combo,    SE_LPRN),
	[EIT_RPRN]   = COMBO(eit_combo,    SE_RPRN),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( \

  KC_TAB,          KC_Q,         KC_W,         KC_F,          LT(_I3SWAY,KC_P), KC_G,              KC_J,         KC_L,         KC_U,    KC_Y,    SE_ODIA,        SE_QUOT,\
  SE_COMM, KC_A,         KC_R,         KC_S,          KC_T,             KC_D,              KC_H,         KC_N,         KC_E,    KC_I,    KC_O,           SE_DOT ,\
  SE_ACUT,         LCTL_T(KC_Z), LALT_T(KC_X), RALT_T(KC_C),  LGUI_T(KC_V),             LT(_I3SWAY,KC_B),  RSFT_T(KC_K), RGUI_T(KC_M), SE_ARNG, SE_ADIA, RCTL_T(SE_DOT), SE_BSLS,\
                                LT(_ADJUST,KC_TAB), KC_LSFT, KC_BSPC,                     LT(_ADJUST,KC_SPC),  MO(_LOWER),  LT(_RAISE,KC_ENT) \
  ),

  [_LOWER] = LAYOUT( \

 SE_TILD, SE_BSLS, SE_PERC, SE_EXLM, SE_HASH, SE_PIPE,                                     SE_EQL, SE_7, SE_8,  SE_9,    SE_ASTR,    SE_DQUO,\
 SE_LCBR, SE_LPRN, SE_LBRC, SE_RBRC, SE_RPRN, SE_AT,                                       SE_PLUS,      SE_4,   SE_5,  SE_6,    SE_MINS,    SE_RCBR,\
 SE_DIAE, SE_CIRC, SE_AMPR, SE_DLR,  SE_LABK, SE_RABK,                                     SE_0,         SE_1,   SE_2,  SE_3,    SE_SLSH,    SE_DOT,\
                                   KC_TRNS, KC_LSFT,KC_DEL,                               KC_TRNS, KC_NO, KC_NO \

    ),

  [_RAISE] = LAYOUT( \
 KC_NO,  KC_ESC,  SE_SCLN, SE_EXLM, SE_SLSH,        SE_PIPE,                               KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_LALT,\
 KC_NO,  SE_LPRN, SE_COLN, SE_MINS, SE_RPRN,        SE_AT,                                 KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,\
 KC_NO,  SE_CIRC, SE_AMPR, SE_QUOT, GUI_T(KC_BSLS), SE_GRV,                                KC_INS, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO,\
            KC_DEL, KC_LSFT,  KC_DEL,                                                     KC_RSFT, KC_NO, KC_LGUI \
  ),

  [_ADJUST] = LAYOUT( \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_HOME, KC_PGUP,     KC_PGDN,     KC_END,  KC_TRNS,\
 KC_TRNS, KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,                                     KC_APP,  KC_LEFT, KC_UP,       KC_DOWN,     KC_RGHT, KC_SLSH,\
 KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_TRNS,                                     KC_TRNS, KC_WBAK, RCTL(KC_NO), RCTL(KC_NO), KC_WFWD, KC_TRNS,\
    KC_TRNS, KC_LSFT,KC_BTN1,                                                             KC_LGUI, KC_WBAK,  KC_TRNS \
  ),
  
    [_I3SWAY] = LAYOUT( \
 KC_NO, SGUI(KC_Q),     LSFT(KC_INS),KC_LCTL,             KC_TRNS,                         LCA(KC_UP),  KC_NO,         KC_NO,         KC_NO,       KC_NO,         KC_NO,         KC_NO,\
 KC_NO, LGUI(KC_LEFT),  LGUI(KC_UP), LGUI(KC_DOWN),       LGUI(KC_RGHT),                   LCA(KC_DOWN),LGUI(KC_BSLS), LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT), KC_NO,\
 KC_NO, KC_PGUP,        KC_PGDN,     LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)),            KC_TRNS,     KC_NO,         KC_NO,         KC_NO,       KC_NO,         KC_NO,         KC_NO,\
   KC_NO, KC_LSFT, KC_NO,                                                                  KC_NO,  KC_NO, KC_NO \
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
