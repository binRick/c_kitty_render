#include "kitty-test/kitty-test.h"
char                  *msg;
int                   x = 0, y = 0, width = 0, height = 0;
struct kitty_screen_t *ks = NULL;

TEST t_kitty_test_screen(){
  if (!(ks = kitty_screen()))
    FAILm("Failed to query terminal screen");
  ASSERT_GT(ks->x, 0);
  ASSERT_GT(ks->y, 0);
  ASSERT_GT(ks->rows, 0);
  ASSERT_GT(ks->cols, 0);
  ASSERT_GT(ks->xpixels, 0);
  ASSERT_GT(ks->ypixels, 0);
  asprintf(&msg, "Kitty Screen Position: %dx%d, size: %dx%d, pixels: %dx%d",
           ks->x, ks->y,
           ks->rows, ks->cols,
           ks->xpixels, ks->ypixels
           );
  PASSm(msg);
}

TEST t_kitty_test_position(){
  if (!kitty_terminal_position(&x, &y))
    FAILm("Failed to query terminal position");
  ASSERT_GT(x, 0);
  ASSERT_GT(y, 0);
  asprintf(&msg, "Terminal Position: %dx%d", x, y);
  PASSm(msg);
}

TEST t_kitty_test_size(){
  if (!kitty_terminal_size(&width, &height))
    FAILm("Failed to query terminal size");
  ASSERT_GT(width, 0);
  ASSERT_GT(height, 0);
  asprintf(&msg, "Terminal Size: %dx%d", width, height);
  PASSm(msg);
}

SUITE(s_kitty_test) {
  RUN_TEST(t_kitty_test_size);
  RUN_TEST(t_kitty_test_position);
  RUN_TEST(t_kitty_test_screen);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  if (isatty(STDOUT_FILENO))
    RUN_SUITE(s_kitty_test);
  GREATEST_MAIN_END();
}
