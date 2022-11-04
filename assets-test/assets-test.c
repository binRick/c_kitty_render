#include "assets/assets.h"
#include "ansi-codes/ansi-codes.h"
#include "assets-test/assets-test.h"
#include "bytes/bytes.h"
#include "c_fsio/include/fsio.h"
#include "c_greatest/greatest/greatest.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "c_vector/vector/vector.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"

TEST t_assets_test2(){
  PASS();
}

TEST t_assets_test1(){
  log_info("assets 1");
  log_info("size: %d",
      inc_kitty_icon_gif_size
      );
  log_info("size: %s",
      bytes_to_string(inc_kitty_icon_gif_size)
      );
  PASS();
}

SUITE(s_assets_test) {
  RUN_TEST(t_assets_test1);
  if (isatty(STDOUT_FILENO))
    RUN_TEST(t_assets_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_assets_test);
  GREATEST_MAIN_END();
}
