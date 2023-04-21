#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
  MAC_TAB = SAFE_RANGE,
};

enum layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _NUM,
    _NAV,
    _SYM,
    _ADJUST,
};

// laters
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define ADJUST   MO(_ADJUST)

// custom kc

// one shots
#define OSM_CA   OSM(MOD_LCTL|MOD_LALT)
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_GUI  OSM(MOD_LGUI)
#define OSM_SFT  OSM(MOD_LSFT)

// mac stuff
#define MAC_PSR  LGUI(LCTL(LSFT(KC_4)))
#define MAC_PS   LGUI(LSFT(KC_4))
#define MAC_GRV  LGUI(KC_GRV)

#define CTLA     LCTL(KC_A)
#define ESC_GUI  MT(MOD_LGUI, KC_ESC)
#define TAB_NAV  LT(NAV, KC_TAB)
#define DEL_ADJ  LT(ADJUST, KC_DEL)
#define SPC_SFT  MT(MOD_LSFT, KC_SPC)
#define ENT_SYM  LT(SYM, KC_ENT)
#define A_CTL    MT(MOD_LCTL, KC_A)
#define S_ALT    MT(MOD_LALT, KC_S)
#define D_GUI    MT(MOD_LGUI, KC_D)
#define F_SFT    MT(MOD_LSFT, KC_F)
#define BS_NUM   LT(NUM, KC_BSPC)
#define SC_GUI   MT(MOD_RGUI, KC_SCLN)

// temp
#define ESC_CTL  MT(MOD_LCTL, KC_ESC)

// HYPR
#define HYP1    HYPR(KC_1)
#define HYP2    HYPR(KC_2)
#define HYP3    HYPR(KC_3)
#define HYP4    HYPR(KC_4)
#define HYP5    HYPR(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ESC_GUI, TAB_NAV, SPC_SFT,    ENT_SYM,  BS_NUM, DEL_ADJ
                                      //`--------------------------'  `--------------------------'

  ),

  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ESC_GUI, TAB_NAV, SPC_SFT,    ENT_SYM,  BS_NUM, DEL_ADJ
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_GRV, KC_TILD, XXXXXXX, KC_COLN, KC_PIPE,                      XXXXXXX, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_BSLS,                       KC_DQT, KC_QUOT, KC_COMM, KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_GRV, KC_TILD, XXXXXXX, KC_COLN, KC_PIPE,                      XXXXXXX, KC_PLUS, KC_UNDS, KC_MINS,  KC_EQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    CTLA, XXXXXXX, XXXXXXX, KC_SCLN, KC_BSLS,                       KC_DQT, KC_QUOT, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, MAC_TAB, MAC_GRV,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    HYP1,    HYP2,    HYP3,    HYP4,    HYP5,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT,  OSM_CA,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, MAC_PSR,                      XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX,  MAC_PS,                      RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

static int8_t nav_layer = -1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_TAB:
      if (record->event.pressed) {
        if (nav_layer < 0) {
            nav_layer = layer_switch_get_layer(record->event.key);
            register_code(KC_LGUI);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (nav_layer >= 0 && !layer_state_cmp(state, nav_layer)) {
        unregister_code(KC_LGUI);
        nav_layer = -1;
    }
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_CTL:
        case S_ALT:
        case D_GUI:
        case F_SFT:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
