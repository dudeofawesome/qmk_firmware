#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define PERMISSIVE_HOLD
#define TAPPING_TERM 150

#ifdef RGBLED_NUM
#undef RGBLED_NUM
#endif
#define RGBLED_NUM 15

#endif
