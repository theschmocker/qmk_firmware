/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

/* Combomap
 *
 * _ALPHA
 *
 * ,-----------------------------.       ,------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH    |
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
 * |      |   BSPC   ENT    |     |      |    LES    |    GRT    |      |
 * |------+-----+-----+-RMB-+-LMB-|      |-----+-----+-----+-----+------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |      |
 * `------+-----+-----+-----+-----'      `------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 *
 * _NUMBERS
 *
 * ,-----------------------------.       ,------------------------------.
 * |      |     |     |     |     |      |     |     |     |     |      |
 * |------+-----+-----+-----+-----|      |-----+-----+-----+-----+------|
 * |      |     |     |     |     |      |     |     |     |     |      |
 * |------+-----+-----+-RMB-+-LMB-|      |---PLAY----+-PRV-+-NXT-+------|
 * |      |     |     |     |     |      |     |     |     |     |      |
 * `------+-----+-----+-----+-----'      `------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .------------------------.              .-------------------------------.
 *  |       | _SPECIAL | CMD |             | SHIFT/ENT| SPC(_NUMBERS) |     |
 *  '-----------------------'              '-------------------------------'
 */
[_ALPHA] = LAYOUT_split_3x5_3(
    KC_Q,               KC_W,               KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P, 
    MT(MOD_LCTL, KC_A), KC_S,               KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   MT(MOD_LCTL, KC_SCLN),
    MT(MOD_RSFT, KC_Z), MT(MOD_LALT, KC_X), KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

 	  KC_TRNS,              MO(_SPECIAL),          KC_LGUI, // Left
		MT(MOD_LSFT, KC_ENT), LT(_NUMBERS, KC_SPC),  KC_TRNS  // Right
    ),
/* Keymap 1: Symbols layer
 * ,------------------------------.      ,--------------------------------.
 * |  !   |  @  |  ~  |  `  |  |  |      |  |  |  {  |  }  |     |   DEL  |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  +  |  =  | LMB |      |  &  |  (  |  )  |  *  |    '   |
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |  %   |  ^  |  "  |  -  | RMB |      |  =  |  [  |  ]  |  .  |   -    |
 * `------+-----+-----+------+----'      `--------------------------------'
 *      .-----------------.           .------------------.
 *      |    |  ;   |  =  |           |  =  |     |      | // TODO: figure out better uses for thumbs in this layer
 *      '-----------------'           '------------------'
 */
[_SPECIAL] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_TILD, KC_GRV,  KC_PIPE,   KC_PIPE, KC_LCBR, KC_RCBR,  KC_TRNS, KC_DEL,
    KC_HASH, KC_DLR,  KC_PLUS, KC_EQL,  KC_BTN2,   KC_AMPR, KC_LPRN, KC_RPRN,  KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_DQUO, KC_MINS, KC_BTN1,   KC_EQL,  KC_LBRC, KC_RBRC,  KC_DOT,  KC_MINS,
                      KC_TRNS, KC_SCLN, KC_EQL,    KC_EQL,  KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP |
 * |-----+-----+-----+-----+------+      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *      .-----------------.           .-----------------.
 *      |     | F11 | F12 |           |     |     |     |
 *      '-----------------'           '-----------------'
 */
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
    case MT(MOD_RSFT, KC_Z):
      return false;
    default:
      return true;
  }
}
