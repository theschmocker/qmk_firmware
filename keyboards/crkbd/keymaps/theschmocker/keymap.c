// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum {
    _ALPHA,   // default
    _COLEMAK,
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_LALX LALT_T(KC_X)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPEC MO(_SPECIAL)
#define KC_CTL_O  MT(MOD_RCTL, KC_O)     // Tap for colon, hold for Control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT_split_3x5_3( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_CTLA, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_CTSC,
    KC_LSHZ, KC_LALX, KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_RLSH,
                   KC_TRNS, KC_SPEC, KC_LGUI,            MT(MOD_LSFT, KC_ENT), LT(_NUMBERS, KC_SPC), KC_TRNS
  ),

  [_COLEMAK] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,   KC_F,   KC_P,   KC_B,            KC_J,   KC_L,   KC_U,     KC_Y,   KC_SCLN,
         KC_CTLA, KC_R,   KC_S,   KC_T,   KC_G,             KC_M,   KC_N,   KC_E,     KC_I,   KC_CTL_O,
         KC_LSHZ, KC_LALX,   KC_C,   KC_D,   KC_V,          KC_K,   KC_H,   KC_COMMA, KC_DOT, KC_RLSH,
                       KC_TRNS, KC_SPEC, KC_LGUI,           MT(MOD_LSFT, KC_ENT), LT(_NUMBERS, KC_SPC), KC_TRNS
  ),

  [_SPECIAL] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_TILD, KC_GRV,  KC_PIPE,   KC_PIPE, KC_LCBR, KC_RCBR,  KC_TRNS, KC_DEL,
    KC_HASH, KC_DLR,  KC_PLUS, KC_EQL,  KC_BTN2,   KC_AMPR, KC_LPRN, KC_RPRN,  KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_DQUO, KC_MINS, KC_BTN1,   KC_EQL,  KC_LBRC, KC_RBRC,  KC_DOT,  KC_MINS,
                       KC_TRNS, KC_SCLN, KC_EQL,    KC_EQL,  KC_TRNS, KC_TRNS
    ),

  [_NUMBERS] = LAYOUT_split_3x5_3(
    KC_1,  KC_2,  KC_3,    KC_4,   KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1, KC_F2, KC_F3,   KC_F4,  KC_F5,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    KC_F6, KC_F7, KC_F8,   KC_F9,  KC_F10,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
                  KC_TRNS, KC_F11, KC_F12,    KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Fixes issue where typing Z/SHIFT and the desired shifted key too quickly would cause z and the key to be output
    case KC_LSHZ:
      return false;
    default:
      return true;
  }
}

int8_t get_combo_layer(uint8_t current_layer) {
    if (current_layer == _COLEMAK) {
        return _ALPHA;
    }

    return current_layer;
}
