/* Copyright 2021 Yiancar-Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define OSM_CA   OSM(MOD_LCTL|MOD_LALT)
#define L_ESC  LT(1, KC_ESC)
#define CTLA     LCTL(KC_A)

// HYPR
#define HYP1    HYPR(KC_1)
#define HYP2    HYPR(KC_2)
#define HYP3    HYPR(KC_3)
#define HYP4    HYPR(KC_4)
#define HYP5    HYPR(KC_5)

#define MAC_PSR  LGUI(LCTL(LSFT(KC_4)))
#define MAC_PS   LGUI(LSFT(KC_4))

#define OPT_SPC  MT(MOD_LALT, KC_SPC)
#define SFT_SPC  MT(MOD_LSFT, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_alice_split_bs( /* Base */
    KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
    KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN, L_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
             KC_LCTL,          KC_LGUI,          SFT_SPC, OPT_SPC,                   KC_SPC,           MO(1),                              KC_RCTL),

[1] = LAYOUT_alice_split_bs( /* FN */
    QK_BOOT, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, CTLA   , KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, MAC_PS , MAC_PSR, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, HYP1   , HYP2   , HYP3   , HYP4   , HYP5   ,                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_TRNS,          KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, OSM_CA , KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_TRNS, KC_TRNS,
             KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,          KC_TRNS,                            KC_TRNS)
};
