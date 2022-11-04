#ifndef ASSETS_C
#define ASSETS_C
#define LOCAL_DEBUG_MODE    ASSETS_DEBUG_MODE
////////////////////////////////////////////
#include "assets/assets.h"
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
INCBIN(animation_1, "assets/animation_1.png");
INCBIN(communist_goals_jpeg, "assets/communist_goals.jpeg");
INCBIN(communist_goals_png, "assets/communist_goals.png");
INCBIN(communist_goals_tiff, "assets/communist_goals.tiff");
INCBIN(communist_goals_bmp, "assets/communist_goals.bmp");
INCBIN(communist_goals_gif, "assets/communist_goals.gif");
INCBIN(kitty_icon_jpeg, "assets/kitty_icon.jpeg");
INCBIN(kitty_icon_png, "assets/kitty_icon.png");
INCBIN(kitty_icon_tiff, "assets/kitty_icon.tiff");
INCBIN(kitty_icon_bmp, "assets/kitty_icon.bmp");
INCBIN(kitty_icon_gif, "assets/kitty_icon.gif");
////////////////////////////////////////////
static bool ASSETS_DEBUG_MODE = false;
///////////////////////////////////////////////////////////////////////
static void __attribute__((constructor)) __constructor__assets(void){
  if (getenv("DEBUG") != NULL || getenv("DEBUG_assets") != NULL) {
    log_debug("Enabling assets Debug Mode");
    ASSETS_DEBUG_MODE = true;
  }
}
////////////////////////////////////////////
#undef LOCAL_DEBUG_MODE
#endif
