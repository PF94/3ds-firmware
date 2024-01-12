#ifndef N3DS_FRAMEBUFFER_H
#define N3DS_FRAMEBUFFER_H

#include <shared/types.h>

#define FB_TOP_WIDTH 400
#define FB_BOTTOM_WIDTH 320
#define FB_HEIGHT 240 // Both displays have the same height

void fillrect(u8 *fb, u32 hex, u32 x, u32 y, u32 w, u32 h);
void fb_clear(void);
void putc(bool isTopScreen, u32 posX, u32 posY, u32 color, char c);
void deinit_displays(void);

#endif // N3DS_FRAMEBUFFER_H