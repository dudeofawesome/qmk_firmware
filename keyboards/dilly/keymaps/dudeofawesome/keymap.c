#include "dilly.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum dilly_layers {
  _QWERTY,
  _WORKMAN,

  _RAISE,
  _LOWER,
  _FN3,
  _FN4,
  _ADJUST,
};

enum dilly_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,

  RAISE,
  LOWER,
  FN3,
  FN4,
  ADJUST,

  GUI_UND,
};

#define KC_ KC_TRNS

// Tap-Hold keys
#define KC_ASFT MT(MOD_LSFT, KC_A)
#define KC_SESC MT(MOD_LSFT, KC_ESC)
#define KC_F_L3 LT(_FN3, KC_F)
#define KC_T_L3 LT(_FN3, KC_T)
#define KC_ZCTL MT(MOD_LCTL, KC_Z)
#define KC_XALT MT(MOD_LALT, KC_X)
#define KC_CGUI MT(MOD_LGUI, KC_C)
#define KC_MGUI MT(MOD_LGUI, KC_M)
#define KC_V_L4 LT(_FN4, KC_V)
#define KC_C_L4 LT(_FN4, KC_C)
#define KC_SPL2 LT(_LOWER, KC_SPC)
#define KC_B_L1 LT(_RAISE, KC_B)
#define KC_V_L LT(_LOWER, KC_V)
#define KC_K_R LT(_RAISE, KC_K)
#define KC_N_L5 LT(_ADJUST, KC_N)
#define KC_K_L5 LT(_ADJUST, KC_K)
#define KC_L_L5 LT(_ADJUST, KC_L)
#define KC_MALT MT(MOD_RALT, KC_M)
#define KC_BSCT MT(MOD_RCTL, KC_BSPC)
#define KC_ENTS MT(MOD_RSFT, KC_ENT)
#define KC_ESCS MT(MOD_RSFT, KC_ESC)

#define KC_GUIC LGUI(KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
      Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     ASFT, S  , D  ,F_L3, G  , H  , J  , K  , L  ,ESCS,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     ZCTL,XALT,CGUI,V_L4,SPL2,B_L1,N_L5,MALT,BSPC,ENTS
  //└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  ),

  [_WORKMAN] = KC_KEYMAP(
  //┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
      Q  , D  , R  , W  , B  , J  , F  , U  , P  ,SCLN,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     ASFT, S  , H  ,T_L3, G  , Y  , N  , E  , O  , I  ,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     ZCTL,XALT,MGUI,C_L4,V_L ,K_R ,L_L5,SPL2,BSPC,ENTS
  //└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  ),

  [_RAISE] = KC_KEYMAP(
  //┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
      1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
      F7 , F8 , F9 ,F10 ,F11 ,F12 ,MINS,EQL ,LBRC,RBRC,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     MPLY,VOLD,VOLU,MNXT,    ,    ,    ,    ,PGUP,PGDN
  //└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  ),

  [_LOWER] = KC_KEYMAP(
  //┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
      F1 , F2 , F3 , F4 , F5 , F6 ,UNDS,PLUS,LCBR,RCBR,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     MPLY,VOLD,VOLU,MNXT,    ,    ,    ,    ,HOME,END
  //└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  ),

  [_FN3] = KC_KEYMAP(
  //┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
     TAB ,    ,    ,    ,    ,MINS,EQL ,LBRC,RBRC,BSLS,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     SESC,    ,    ,    ,    ,SCLN,QUOT,COMM,DOT ,SLSH,
  //├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
         ,    ,    ,    ,BSPC,    ,LEFT,DOWN, UP ,RGHT
  //└────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
  ),

  [_FN4] = KEYMAP(
  //┌───────────────────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     KC_TAB             ,_______,_______,_______,_______,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
  //├───────────────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     MT(MOD_LSFT,KC_ESC),_______,_______,_______,_______,KC_COLN,KC_DQUO,KC_LT  ,KC_GT  ,KC_QUES,
  //├───────────────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______            ,_______,GUI_UND,_______,KC_BSPC,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END
  //└───────────────────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
  ),

  [_ADJUST] = KEYMAP(
  //┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     RGB_TOG,RGB_MOD,_______,RESET  ,RGB_HUI,RGB_SAI,RGB_VAI,_______,_______,QWERTY ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     KC_CAPS,_______,DEBUG  ,_______,RGB_HUD,RGB_SAD,RGB_VAD,_______,_______,WORKMAN,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     BL_STEP,_______,GUI_UND,_______,_______,_______,_______,_______,KC_DEL ,_______
  //└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;

    case GUI_UND: {
    // TODO: parameterize the keycode to use
      uint16_t gui_und_kc = LGUI(KC_M);
      register_code(gui_und_kc);
      unregister_code(gui_und_kc);
      return false;
    }
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}
