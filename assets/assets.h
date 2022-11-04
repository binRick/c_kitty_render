#ifndef ASSETS_H
#define ASSETS_H
#define INCBIN_SILENCE_BITCODE_WARNING
#define INCBIN_PREFIX inc_
#define INCBIN_STYLE INCBIN_STYLE_SNAKE
//////////////////////////////////////
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "incbin/incbin.h"
//////////////////////////////////////
INCBIN_EXTERN(kitty_icon_jpeg);
INCBIN_EXTERN(kitty_icon_gif);
#endif
