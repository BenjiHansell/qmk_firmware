/* Copyright 2021 kuenhlee and Don Kjer
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

// Layer shorthand
enum _layer { _BASE, _FUNC };

// clang-format off

// TODO: only have one (or 0) Fn key in bottom right
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BASE: Base Layer (Default Layer)
   * ,-----------------------------------------------------------.  ,--------------.
   * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|  |Prnt|ScLk|Paus|
   * |-----------------------------------------------------------|  |--------------|
   * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |  | Ins|Home|PgUp|
   * |-----------------------------------------------------------|  |--------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |  | Del| End|PgDn|
   * |------------------------------------------------------ Ret |  `--------------'
   * |Fn     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| #|    |
   * |-----------------------------------------------------------|        ,----.
   * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |        | Up |
   * |-----------------------------------------------------------|   ,-------------.
   * |Ctrl|Gui |Alt |      Space            |Alt | Fn  |Fn  |Ctrl|   |Lft| Dn |Rig |
   * `-----------------------------------------------------------'   `-------------'
   */
  [_BASE] = LAYOUT_tkl_iso( /* Base Layer */
      KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,  KC_SLCK,  KC_PAUS,
      KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
      KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,   KC_DEL,   KC_END,   KC_PGDN,  
      MO(_FUNC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,
      KC_LSFT,   KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
      KC_LCTL,   KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FUNC),MO(_FUNC),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  /* Keymap _FUNC: Function Layer
   * ,-----------------------------------------------------------.  ,--------------.
   * |   |Play|Stop|Prev|Next| |Mute|Vol+|Vol-|    | |  |  |  |  |  |    |    |    |
   * |-----------------------------------------------------------|  |--------------|
   * |Esc| f1| f2| f3| f4| f5| f6| f7| f8| f9|f10|f11|f12|Backsp |  |BLDR|    |    |
   * |-----------------------------------------------------------|  |--------------|
   * |     |   |   |   |   |   |PUp|Hom| Up|End|   |   |   |     |  |    |    |    |
   * |-------------------------------------------------------    |  `--------------'
   * |       |   |   |   |   |   |PDn|Lft| Dn|Rig|Del|   |  |    |
   * |-----------------------------------------------------------|        ,----.
   * |     |  |   |   |   |   |   |   |   |   |   |   |          |        |    |
   * |-----------------------------------------------------------|   ,-------------.
   * |    |    |    |                       |    |Func|Func|     |   |    |   |    |
   * `-----------------------------------------------------------'   `-------------'
   */
  [_FUNC] = LAYOUT_tkl_iso( /* Function Layer */
      _______,  KC_MPLY,  KC_MSTP,  KC_MRWD,  KC_MFFD,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  /*    */      _______,  _______,  _______,
       KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______,        RESET,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_HOME,    KC_UP,   KC_END,  _______,  _______,  _______,  _______,      _______,  _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_DEL,  _______,  _______, /*     */      /*    */  /*    */  /*    */
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  /*    */  _______,      /*    */  _______,  /*    */
      _______,  _______,  _______,  /*    */  /*    */  /*    */  _______,  /*    */  /*    */  /*    */  _______,  _______,  _______,  _______,      _______,  _______,  _______
  )
};

// TODO: add layer which disables all non-60% keys
// TODO: add capslock via ctrl-caps
// TODO: add WASD or ESDF arrows
// TODO: add strict-shift layer
// TODO: better way to access escape using 60% keys

// clang-format on

_Noreturn void panic(void) {
    writePin(LED_CAPS_LOCK_PIN, LED_PIN_ON_STATE);
    writePin(LED_WIN_LOCK_PIN, LED_PIN_ON_STATE);
    writePin(LED_MR_LOCK_PIN, LED_PIN_ON_STATE);
    writePin(LED_SCROLL_LOCK_PIN, LED_PIN_ON_STATE);
    while (true)
        ;
    // TODO: flash rapidly
}

void expect(bool okay) {
    if (!okay) {
        panic();
    }
}

bool is_ijkl(uint16_t keycode) {
    switch (keycode) {
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
            return true;
        default:
            return false;
    }
}

int ijkl_to_uldr(uint16_t keycode) {
    switch (keycode) {
        case KC_I:
            return KC_UP;
        case KC_J:
            return KC_LEFT;
        case KC_K:
            return KC_DOWN;
        case KC_L:
            return KC_RGHT;
    }
    panic();
}

uint8_t to_arrow_index(uint16_t keycode) {
    switch (keycode) {
        case KC_I:
        case KC_UP:
            return 0;
        case KC_J:
        case KC_LEFT:
            return 1;
        case KC_K:
        case KC_DOWN:
            return 2;
        case KC_L:
        case KC_RGHT:
            return 3;
    }
    panic();
}

bool ijkl_states[]         = {false, false, false, false};
bool virtual_uldr_states[] = {false, false, false, false};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (is_ijkl(keycode)) {
        uint8_t arrow_index = to_arrow_index(keycode);
        if (record->event.pressed) {
            if (get_mods() & MOD_BIT(KC_LALT)) {
                // alt IJKL -> alt ULDR (including with any other modifier)
                // TODO: consider not allowing when start is pressed
                register_code(ijkl_to_uldr(keycode));
                expect(virtual_uldr_states[arrow_index] == false);
                virtual_uldr_states[arrow_index] = true;
            } else {
                register_code(keycode);
                expect(ijkl_states[arrow_index] == false);
                ijkl_states[arrow_index] = true;
            }
        } else {
            // unlike keydown, keyup is not based on whether alt is press.  Instead it is based on which key is currently down.  That is to prevent errors when alt is released before I/J/K/L
            if (virtual_uldr_states[arrow_index]) {
                expect(ijkl_states[arrow_index] == false);
                unregister_code(ijkl_to_uldr(keycode));
                virtual_uldr_states[arrow_index] = false;
            } else if (ijkl_states[arrow_index]) {
                unregister_code(keycode);
                ijkl_states[arrow_index] = false;
            } else {
                panic();
            }
        }
        return false;
    }
    return true;
}