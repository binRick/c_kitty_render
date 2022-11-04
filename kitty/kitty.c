#ifndef KITTY_C
#define KITTY_C
#define LOCAL_DEBUG_MODE    KITTY_DEBUG_MODE
#include "kitty/kitty.h"
////////////////////////////////////////////
static bool KITTY_DEBUG_MODE = false;
static struct winsize *kitty_terminal_winsize(void);
static void __attribute__((constructor)) __constructor__kitty(void);

bool kitty_terminal_position(int *x, int *y){
  char           buf[30] = { 0 }, ch;
  int            ret, i, pow;
  struct termios term, restore;

  tcgetattr(0, &term);
  tcgetattr(0, &restore);
  term.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &term);
  write(1, "\x1b[6n", 4);
  for ( i = 0, ch = 0; ch != 'R'; i++ ) {
    ret = read(0, &ch, 1);
    if (!ret) {
      tcsetattr(0, TCSANOW, &restore);
      return(false);
    }
    buf[i] = ch;
  }
  if (i < 2) {
    tcsetattr(0, TCSANOW, &restore);
    return(false);
  }
  for ( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
    *x = *x + (buf[i] - '0') * pow;
  for ( i--, pow = 1; buf[i] != '['; i--, pow *= 10)
    *y = *y + (buf[i] - '0') * pow;
  tcsetattr(0, TCSANOW, &restore);

  return(true);
}
static struct winsize *kitty_terminal_winsize(){
  struct winsize *sz = calloc(1, sizeof(struct winsize));

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, sz) != EXIT_SUCCESS) {
    log_error("Failed to query window size");
    return(NULL);
  }
  return(sz);
}

bool kitty_terminal_size(int *width, int *height){
  struct winsize *sz = NULL;

  if (!(sz = kitty_terminal_winsize())) {
    log_error("winsize error");
    return(false);
  }
  *width  = sz->ws_col;
  *height = sz->ws_row;
  free(sz);
  return(true);
}
struct kitty_screen_t *kitty_screen(void){
  struct kitty_screen_t *s  = calloc(1, sizeof(struct kitty_screen_t));
  struct winsize        *sz = kitty_terminal_winsize();

  s->cols    = sz->ws_col;
  s->rows    = sz->ws_row;
  s->xpixels = sz->ws_xpixel;
  s->ypixels = sz->ws_ypixel;
  if (!kitty_terminal_position(&(s->x), &(s->y))) {
    log_error("terminal position error");
    return(NULL);
  }
  return(s);
}

////////////////////////////////////////////
static void __attribute__((constructor)) __constructor__kitty(void){
  if (getenv("DEBUG") != NULL || getenv("DEBUG_kitty") != NULL) {
    log_debug("Enabling kitty Debug Mode");
    KITTY_DEBUG_MODE = true;
  }
}
#undef LOCAL_DEBUG_MODE
#endif
