#pragma once
#ifndef KITTY_H
#define KITTY_H
//////////////////////////////////////
#include "ansi-codes/ansi-codes.h"
#include "bytes/bytes.h"
#include "c_fsio/include/fsio.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "c_vector/vector/vector.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <errno.h>
#include <fcntl.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <unistd.h>
#include <unistd.h>
//////////////////////////////////////
const char *KITTY_ESC_CODE_CLEAR                   = "\x1b_Ga=d,q=2\x1b\\";
const char *KITTY_ESC_QUERY                        = "\x1b_Gi=1,a=q;\x1b\\";
const char *KITTY_ESC_CHECK_TERMINAL_CAPS          = "\x1b_Ga=q,s=1,v=1,i=1;YWJjZA==\x1b\\";
const char *KITTY_ESC_DELETE_ALL_VISIBLE_PLAYMENTS = "\x1b_Ga=d\x1b\\";
const char *KITTY_ESC_QUERY_BG_COLOR               = "\033]11;?\033\\";
struct kitty_screen_t {
  int x, y;
  int rows, cols;
  int xpixels, ypixels;
};

bool kitty_terminal_position(int *x, int *y);
bool kitty_terminal_pixel_position(int *x, int *y);
bool kitty_terminal_size(int *width, int *height);
struct kitty_screen_t *kitty_screen(void);

#endif
