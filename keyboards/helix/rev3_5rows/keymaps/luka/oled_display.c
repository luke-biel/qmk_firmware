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

 /*
   How to Customize

   $ make helix/rev3_5rows:YOUR_KEYMAP:clean
   $ cp keyboards/helix/rev3_5rows/oled_display.c keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP

   $ edit keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP/oled_display.c
   $ make helix/rev3_5rows:YOUR_KEYMAP
   $ make helix/rev3_5rows:YOUR_KEYMAP:flash
 */

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _DVORAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

#ifdef OLED_DRIVER_ENABLE

void render_status(void) {
  // Render to mode icon
  static const char os_logo[][2][3] PROGMEM  ={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if (is_mac_mode()) {
    oled_write_P(os_logo[0][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(os_logo[0][1], false);
  }else{
    oled_write_P(os_logo[1][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(os_logo[1][1], false);
  }

  oled_write_P(PSTR(" "), false);

  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
      case _DVORAK:
          oled_write_P(PSTR("DVORAK\n"), false);
          break;
      case _RAISE:
          oled_write_P(PSTR("RISE\n"), false);
          break;
      case _LOWER:
          oled_write_P(PSTR("LOWER\n"), false);
          break;
      case _ADJUST:
          oled_write_P(PSTR("ADJUST\n"), false);
          break;
      default:
          // Or use the write_ln shortcut over adding '\n' to the end of your string
          oled_write_ln_P(PSTR("Undefined"), false);
  }

  oled_write_P(PSTR("\n"), false);

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

static void render_wpm(void) {
#ifdef WPM_ENABLE
    char buf[30];
    snprintf(buf, sizeof(buf), "WPM %d.0\n", get_current_wpm());
    oled_write(buf, false);
#endif
}

static void render_rgbled_status(bool full) {
#ifdef RGBLIGHT_ENABLE
  char buf[30];
  if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
      if (full) {
          snprintf(buf, sizeof(buf), "LED %2d: %d,%d,%d ",
                   rgblight_get_mode(),
                   rgblight_get_hue()/RGBLIGHT_HUE_STEP,
                   rgblight_get_sat()/RGBLIGHT_SAT_STEP,
                   rgblight_get_val()/RGBLIGHT_VAL_STEP);
      } else {
          snprintf(buf, sizeof(buf), "[%2d] ", rgblight_get_mode());
      }
      oled_write(buf, false);
  }
#endif
}

void oled_task_user(void) {
  if(is_keyboard_master()){
    render_status();
  }else{
//    render_logo();
    render_wpm();
    render_rgbled_status(true);
  }
}
#endif
