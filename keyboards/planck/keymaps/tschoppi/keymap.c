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
  _NUMBLOCK
};

enum tap_dance {
  TD_BRACES = 0,
  TD_BRACKETS = 1,
  TD_COLONS = 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Wide Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * |  Q   |   W  |   F  |   P  |   B  |      |   [  |   J  |   L  |   U  |   Y  |   :  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A   |   R  |   S  |   T  |   G  |   '  |   {  |   M  |   N  |   E  |   I  |  O   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Z   |   X  |   C  |   D  |   V  |   -  |   =  |   K  |   H  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt |      | GUI  | BkSp | Tab  | Entr |Space | Ctrl | BkSp |  Del | Esc  |
 * `-----------------------------------------------------------------------------------'
 */
[_WCOLEMAKDH] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______, TD(TD_BRACKETS), KC_J,   KC_L,    KC_U,    KC_Y,    TD(TD_COLONS)},
  {KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_QUOT, TD(TD_BRACES),   KC_M,   KC_N,    KC_E,    KC_I,    KC_O   },
  {KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MINS, KC_EQL,          KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_LCTL, KC_LALT, _______, KC_LGUI, LT(_NUMBLOCK, KC_BSPC), SFT_T(KC_TAB),  SFT_T(KC_ENT),  LT(_NUMROW, KC_SPC), KC_RCTL, KC_BSPC, KC_DEL, KC_ESC }
},

/* Number row
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |      |      |      |      |      |      |   |  |   \  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMROW] = {
  {KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
  {KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {KC_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_BSLS, KC_TILD},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Number block
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      | Prnt |      |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |      |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBLOCK] = {
  {RESET,   _______, KC_UP,   _______, _______, KC_PSCR, _______, _______, KC_7, KC_8,   KC_9,    KC_0},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_4, KC_5,   KC_6,    _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,   KC_3,    _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______}
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
