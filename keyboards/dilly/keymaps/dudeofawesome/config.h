#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define PERMISSIVE_HOLD
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef RGBLIGHT_ENABLE
  #ifdef RGBLED_NUM
  #undef RGBLED_NUM
  #endif
  #define RGBLED_NUM 27

  #define RGBLIGHT_EFFECT_BREATHE_MAX 200
  #define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3   // How many LEDs wide to light up
  #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 10   // The led to start at
  #define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 9  // How many LEDs to travel
#endif

#endif
