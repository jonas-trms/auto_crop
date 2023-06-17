#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define STBI_NO_FAILURE_STRINGS
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG

#include "data_structures.h"
#include "image_operations.h"
#include "pixel_operations.h"
#include "stb_image.h"
#include "stb_image_write.h"

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Please give an input, an output, and a reduction factor.\n");
    exit(EXIT_FAILURE);
  }
  char *f_in = argv[1];
  char *f_out = argv[2];
  int factor = (int)strtol(argv[3], NULL, 10);
  image *im = image_load(f_in);

  reduce_column(im, factor);

  image_save(im, f_out);

  image_delete(im);
  return 0;
}
