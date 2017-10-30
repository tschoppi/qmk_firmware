/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _WCOLEMAKDH,
  _NUMROW,
  _GUIROW,
  _NUMBLOCK,
  _UMLAUT
};

enum tap_dance {
  TD_BRACES = 0,
  TD_BRACKETS = 1,
  TD_COLONS = 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Wide Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * |  Q   |   W  |   F  |   P  |   B  | Uml  |   [  |   J  |   L  |   U  |   Y  |   :  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A   |   R  |   S  |   T  |   G  |   '  |   {  |   M  |   N  |   E  |   I  |  O   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Z   |   X  |   C  |   D  |   V  |   -  |   =  |   K  |   H  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt |      | GUI  | BkSp | Tab  | Entr |Space | Ctrl | BkSp |  Del | Esc  |
 * `-----------------------------------------------------------------------------------'
 */
[_WCOLEMAKDH] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    MO(_UMLAUT), TD(TD_BRACKETS), KC_J,   KC_L,    KC_U,    KC_Y,    TD(TD_COLONS)},
  {KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_QUOT,     TD(TD_BRACES),   KC_M,   KC_N,    KC_E,    KC_I,    KC_O   },
  {KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MINS,     KC_EQL,          KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_LCTL, KC_LALT, _______, OSL(_GUIROW), LT(_NUMBLOCK, KC_BSPC), SFT_T(KC_TAB),  SFT_T(KC_ENT),  LT(_NUMROW, KC_SPC), KC_RCTL, KC_BSPC, KC_DEL, KC_ESC }
},

/* Number row
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |      |      |   |  |   \  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMROW] = {
  {KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
  {KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_BSLS, KC_TILD},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* GUI row
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GUIROW] = {
  {LGUI(KC_1),     LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    _______, _______, LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9),    LGUI(KC_0)},
  {LGUI(KC_EXLM),  LGUI(KC_AT),   LGUI(KC_HASH), LGUI(KC_DLR),  LGUI(KC_PERC), _______, _______, LGUI(KC_CIRC), LGUI(KC_AMPR), LGUI(KC_ASTR), LGUI(KC_LPRN), LGUI(KC_RPRN)},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Number block
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |  Up  |      |      |      | Prnt |      |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |      |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBLOCK] = {
  {RESET,   _______, KC_UP,   _______, _______,   KC_PSCR, _______, _______, KC_7, KC_8,   KC_9,    KC_0},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, S(KC_INS), _______, _______, KC_4, KC_5,   KC_6,    _______},
  {_______, _______, _______, _______, _______,   _______, _______, _______, KC_1, KC_2,   KC_3,    _______},
  {_______, _______, _______, _______, _______,   _______, _______, _______, KC_0, KC_DOT, _______, _______}
},

/* Umlaut layer
 * ,-----------------------------------------------------------------------------------.
 * |  Á   |      |      |      |      |      |      |      |      |   Ü  |  Ú   |  Ó   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ä   |      |      |      |      |      |      |      |      |      |      |  Ö   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UMLAUT] = {
  {RALT(KC_A),    RALT(KC_W),    RALT(KC_F),    RALT(KC_P),    RALT(KC_B),    _______, RALT(KC_DQT), RALT(KC_J),   RALT(KC_L),    RALT(KC_Y),    RALT(KC_U),    RALT(KC_O)},
  {RALT(KC_Q),    RALT(KC_R),    RALT(KC_S),    RALT(KC_T),    RALT(KC_G),    RALT(KC_QUOT), RALT(KC_GRV),   RALT(KC_M),   RALT(KC_N),    RALT(KC_E),    RALT(KC_I),    RALT(KC_P)},
  {RALT(KC_Z),    RALT(KC_X),    RALT(KC_C),    RALT(KC_D),    RALT(KC_V),    KC_MINS, RALT(KC_TILD),          RALT(KC_K),   RALT(KC_H),    RALT(KC_COMM), RALT(KC_DOT),  RALT(KC_SLSH)},
  {_______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______}
}
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   return true; */
/* } */

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_BRACES]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRACKETS]= ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_COLONS] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN)
};
