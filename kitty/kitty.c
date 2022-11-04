#ifndef KITTY_C
#define KITTY_C
#define LOCAL_DEBUG_MODE    KITTY_DEBUG_MODE
////////////////////////////////////////////
#include "kitty/kitty.h"
////////////////////////////////////////////
#include "ansi-codes/ansi-codes.h"
#include "bytes/bytes.h"
#include "c_fsio/include/fsio.h"
#include "c_string_buffer/include/stringbuffer.h"
#include "c_stringfn/include/stringfn.h"
#include "c_vector/vector/vector.h"
#include "log/log.h"
#include "ms/ms.h"
#include "timestamp/timestamp.h"

////////////////////////////////////////////
static bool KITTY_DEBUG_MODE = false;
///////////////////////////////////////////////////////////////////////
static void __attribute__((constructor)) __constructor__kitty(void){
  if (getenv("DEBUG") != NULL || getenv("DEBUG_kitty") != NULL) {
    log_debug("Enabling kitty Debug Mode");
    KITTY_DEBUG_MODE = true;
  }
}
void kitty_test_one(){
  log_info("test one");
}
////////////////////////////////////////////
#undef LOCAL_DEBUG_MODE
#endif
