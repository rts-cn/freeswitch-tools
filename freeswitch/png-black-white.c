/*
 * Author: Seven Du <duinfang@gmail.com>
 */

#include <switch.h>

int main(int argc, char **argv)
{
	switch_image_t *img = switch_img_read_png(argv[1], SWITCH_IMG_FMT_I420);
	switch_assert(img);

	int i, j;
	int w = img->d_w;
	int h = img->d_h;

	// yuv size need a even number
	if (w % 2) w--;
	if (h % 2) h--;

	for(j = 0; j < h / 2; j++) {
		for(i = 0; i < w / 2; i++) {
			uint8_t *u = img->planes[SWITCH_PLANE_U] + j * img->stride[SWITCH_PLANE_U] + i;
			uint8_t *v = img->planes[SWITCH_PLANE_V] + j * img->stride[SWITCH_PLANE_V] + i;
			*u = 128;
			*v = 128;
		}
	}

	switch_img_write_png(img, argv[2]);
	switch_img_free(&img);
}
