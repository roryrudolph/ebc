#include "display.h"
#include <stdlib.h>

struct display
{
	uint16_t width;
	uint16_t height;
	uint32_t num_pixels;
	uint8_t **buffer_front;
	uint8_t **buffer_back;
};

/**
 * Write a pixel to the display driver
 * @param pixel The pixel to write
 * @param row The pixel's row position
 * @param col The pixel's column position
 */
static void write_pixel(uint8_t *pixel, uint16_t row, uint16_t col)
{

}

/**
 * TODO Document
 * @param width TODO Document
 * @param height TODO Document
 * @return TODO Document
 */
display_t *display_init(uint8_t width, uint8_t height)
{
	display_t *d = (display_t *) malloc(sizeof(display_t));

	d->width = width;
	d->height = height;
	d->num_pixels = width * height;

	for (uint16_t i = 0; i < height; ++i)
	{
		d->buffer_front[i] = (uint8_t *) malloc(sizeof(uint8_t) * width);
		d->buffer_back[i] = (uint8_t *) malloc(sizeof(uint8_t) * width);
	}

	return (d);
}

/**
 * TODO Document
 * @param display TODO Document
 */
void display_swap_buffers(display_t *display)
{
	for (uint16_t col = 0; col < display->width; ++col)
	{
		for (uint16_t row = 0; row < display->height; ++row)
		{
			write_pixel(&display->buffer_back[row][col], row, col);
		}
	}

}
