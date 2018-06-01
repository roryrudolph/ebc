#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct display display_t;

display_t *display_init(uint8_t width_px, uint8_t height_px);
void display_swap_buffers(display_t *display);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_H_
