/* Copyright 2020 yushakobo
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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _DVORAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Dvorak
     * ,-----------------------------------------.             ,-----------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Tab  |   ,  |   .  |   P  |   Y  |   F  |             |   G  |   C  |   R  |   L  |   /  |   \  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * | Caps |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |   ]  |   B  |   M  |   W  |   V  |   Z  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | OFHnd|   `  | Ctrl |  Alt | Cmd  |Lower |Space |Enter |Raise |  Alt | Left | Down |  Up  |Right |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                    KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,  \
      KC_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                    KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_BSLS, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,  KC_LBRC, KC_RBRC, KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
      KC_NO,   KC_GRV,  KC_LCTL, KC_LALT, KC_LCMD, LOWER, KC_SPC,  KC_ENT,  RAISE, KC_RALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),
    /* Lower
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |  f1  |  f2  |  f3  |  f4  |  f5  |             |  f6  |  f7  |  f8  |  f9  | f10  | DEL  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |   1  |   2  |   3  |      |      |      |             |      |   -  |   =  |  f11 | f12  | Ctrl |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |   4  |   5  |   6  |      |      |      |      |      |      |      |      |      | PgUp |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |   7  |   8  |   9  |   0  |      |      |      |      |ADJUST|      |      | Home | PgDn | End  |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
      _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
      KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______,                   _______, KC_MINS, KC_EQL,  KC_F11,  KC_F12,  KC_RCTL, \
      KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______, _______, _______, _______, ADJUST,  _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END \
  ),
    /* Raise
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |      |      |      |      |      |      |             | CAPS |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      | LMB  | MseU | RMB  |      |      |             | NUML |      |      |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      | MseL | MseD | MseR |      |      |             | SCRL |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | BTN3 | MsWU | BTN4 |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | MsWL | MsWD | MsWR |      |ADJUST|      |      |      |      |      |      |      |      |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   KC_CLCK, _______, _______, _______, _______,  _______, \
      _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,                   KC_SLCK, _______, _______, _______, _______, _______, \
      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_NLCK, _______, _______, _______, _______, _______, \
      _______, KC_BTN3, KC_WH_U, KC_BTN4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, ADJUST,  _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |RGBTOG| Hue+ | Val+ | Sat- |      |      |             | Aud+ | Next | Pause|      |      | Brg+ |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |RGBMOD| Hue- | Val- | Sat- |      |      |             | Aud- | Prev |      |      |      | Brg- |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |RESET |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      RGB_TOG, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______,                   KC_VOLU, KC_MNXT, KC_MPLY, _______, _______, KC_BRIU, \
      RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, _______, _______,                   KC_VOLD, KC_MPRV, _______, _______, _______, KC_BRID, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};


//LEADER_EXTERNS();
//
//void matrix_scan_user(void) {
//  LEADER_DICTIONARY() {
//    leading = false;
//    leader_end();
//
//    SEQ_TWO_KEYS(KC_COLON, KC_W) {
//      SEND_STRING(SS_LCTL("s"));
//    }
//  }
//}
