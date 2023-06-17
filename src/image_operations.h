#ifndef IMAGE_OPERATIONS
#define IMAGE_OPERATIONS

#include "data_structures.h"
#include <stdint.h>

image *image_load(char *filename);
void image_save(image *im, char *filename);
image *image_new(int h, int w);
void image_delete(image *im);

void invert(image *im);
void binarize(image *im);
void flip_horizontal(image *im);

#endif