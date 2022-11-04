#ifndef MSG_C
#define MSG_C
#define LOCAL_DEBUG_MODE    MSG_DEBUG_MODE
////////////////////////////////////////////
#include "msg/msg.h"
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
static bool MSG_DEBUG_MODE = false;
///////////////////////////////////////////////////////////////////////
static void __attribute__((constructor)) __constructor__msg(void){
  if (getenv("DEBUG") != NULL || getenv("DEBUG_msg") != NULL) {
    log_debug("Enabling msg Debug Mode");
    MSG_DEBUG_MODE = true;
  }
}
////////////////////////////////////////////
#undef LOCAL_DEBUG_MODE
#endif
