#include "dilly.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum dilly_layers {
  _QWERTY,
  _WORKMAN,
  _FN1,
  _FN2,
  _FN3,
  _FN4,
  _ADJUST,
};

enum dilly_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  FN1,
  FN2,
  FN3,
  FN4,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

// Tap-Hold keys
#define KC_ASFT MT(MOD_LSFT, KC_A)
#define KC_F_L3 LT(_FN3, KC_F)
#define KC_T_L3 LT(_FN3, KC_T)
#define KC_ZCTL MT(MOD_LCTL, KC_Z)
#define KC_XALT MT(MOD_LALT, KC_X)
#define KC_CGUI MT(MOD_LGUI, KC_C)
#define KC_MGUI MT(MOD_LGUI, KC_M)
#define KC_V_L4 LT(_FN4, KC_V)
#define KC_C_L4 LT(_FN4, KC_C)
#define KC_SPL2 LT(_FN2, KC_SPC)
#define KC_B_L1 LT(_FN1, KC_B)
#define KC_V_L1 LT(_FN1, KC_V)
#define KC_N_L5 LT(_ADJUST, KC_N)
#define KC_K_L5 LT(_ADJUST, KC_K)
#define KC_L_L5 LT(_ADJUST, KC_L)
#define KC_MALT MT(MOD_RALT, KC_M)
#define KC_BSCT MT(MOD_RCTL, KC_BSPC)
#define KC_ENTS MT(MOD_RSFT, KC_ENT)
#define KC_ESCS MT(MOD_RSFT, KC_ESC)

#define KC_GUIC LGUI(KC_C)

#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
      Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,
  //|----+----+----+----+----+----+----+----+----+----|
     ASFT, S  , D  ,F_L3, G  , H  , J  , K  , L  ,ESCS,
  //|----+----+----+----+----+----+----+----+----+----|
     ZCTL,XALT,CGUI,V_L4,SPL2,B_L1,N_L5,MALT,BSPC,ENTS
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_WORKMAN] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
      Q  , D  , R  , W  , B  , J  , F  , U  , P  ,ESCS,
  //|----+----+----+----+----+----+----+----+----+----|
     ASFT, S  , H  ,T_L3, G  , Y  , N  , E  , O  , I  ,
  //|----+----+----+----+----+----+----+----+----+----|
     ZCTL,XALT,MGUI,C_L4,SPL2,V_L1,K_L5, L  ,BSPC,ENTS
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_FN1] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
      1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,
  //|----+----+----+----+----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,
  //|----+----+----+----+----+----+----+----+----+----|
         ,    ,    ,    ,BSPC,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_FN2] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
     EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,
  //|----+----+----+----+----+----+----+----+----+----|
     F11 ,F12 ,    ,    ,    ,    ,    ,    ,    ,GRV ,
  //|----+----+----+----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,    ,    ,    ,
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_FN3] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,MINS,EQL ,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----+----+----+----+----|
     TAB ,    ,    ,    ,    ,COMM,DOT ,SLSH,SCLN,QUOT,
  //|----+----+----+----+----+----+----+----+----+----|
         ,    ,    ,    ,BSPC,    ,LEFT,DOWN, UP ,RGHT
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_FN4] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,UNDS,PLUS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----+----+----+----+----|
     TAB ,    ,    ,    ,    , LT , GT ,QUES,COLN,DQUO,
  //|----+----+----+----+----+----+----+----+----+----|
         ,    ,GUIC,    ,BSPC,    ,HOME,PGDN,PGUP,END
  //`----+----+----+----+----+----+----+----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     RGB_TOG,RGB_MOD,_______,RESET  ,RGB_HUI,RGB_SAI,RGB_VAI,_______,_______,QWERTY ,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     _______,_______,DEBUG  ,_______,RGB_HUD,RGB_SAD,RGB_VAD,_______,_______,WORKMAN,
  //├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     BL_STEP,_______,KC_GUIC,_______,_______,_______,_______,_______,_______,_______
  //└───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
  )

};
