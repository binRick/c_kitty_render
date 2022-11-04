#ifndef ASSETS_H
#define ASSETS_H
#define KITTY_ASSETS_QTY    2
#define INCBIN_SILENCE_BITCODE_WARNING
#define INCBIN_PREFIX       inc_
#define INCBIN_STYLE        INCBIN_STYLE_SNAKE
//////////////////////////////////////
#include "incbin/incbin.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//////////////////////////////////////
INCBIN_EXTERN(kitty_icon_jpeg);
INCBIN_EXTERN(kitty_icon_gif);
struct kitty_asset_t {
  unsigned long len;
  char          *format;
  unsigned char *pixels;
};
static struct kitty_asset_t kitty_assets[KITTY_ASSETS_QTY];
const unsigned long         *kitty_asset_sizes;
#endif
