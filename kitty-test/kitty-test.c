
#include "ansi-codes/ansi-codes.h"
#include "bytes/bytes.h"
#include "c_fsio/include/fsio.h"
#include "c_greatest/greatest/greatest.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "c_vector/vector/vector.h"
#include "kitty-test/kitty-test.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"
#include "kitty/kitty.h"

TEST t_kitty_test2(){
  PASS();
}

TEST t_kitty_test1(){
  kitty_test_one();
  PASS();
}

SUITE(s_kitty_test) {
  RUN_TEST(t_kitty_test1);
  if (isatty(STDOUT_FILENO))
    RUN_TEST(t_kitty_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_kitty_test);
  GREATEST_MAIN_END();
}
