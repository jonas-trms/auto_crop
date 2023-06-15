#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "image_operations.h"
#include "stb_image.h"
#include "stb_image_write.h"

image *image_load(char *filename) {
  int w, h, channels;
  uint8_t *data = stbi_load(filename, &w, &h, &channels, 0);
  if (!data) {
    fprintf(stderr, "Read error.\n");
    stbi_failure_reason();
    exit(EXIT_FAILURE);
  }
  if (channels != 1) {
    fprintf(stdout, "Not a grayscale image.\n");
    exit(EXIT_FAILURE);
  }
  image *im = image_new(h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      im->at[i][j] = data[j + i * w];
    }
  }
  free(data);
  return im;
}

void image_save(image *im, char *filename) {
  int h = im->h;
  int w = im->w;
  int stride_length = w;
  uint8_t *data = malloc(w * h * sizeof(uint8_t));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      data[j + i * w] = im->at[i][j];
    }
  }
  if (!stbi_write_png(filename, w, h, 1, data, stride_length)) {
    fprintf(stderr, "Write error.\n");
    image_delete(im);
    free(data);
    exit(EXIT_FAILURE);
  }
  free(data);
}

image *image_new(int h, int w) {
  image *new_image = malloc(sizeof(image));
  new_image->at = malloc(h * sizeof(uint8_t *));
  for (int i = 0; i < h; i++) {
    new_image->at[i] = malloc(w * sizeof(uint8_t));
  }
  new_image->h = h;
  new_image->w = w;
  return new_image;
}

void image_delete(image *im) {
  for (int i = 0; i < im->h; i++) {
    free(im->at[i]);
  }

  free(im->at);
  free(im);
}

void invert(image *im) {
  for (int i = 0; i < im->h; i++)
    for (int j = 0; j < im->w; j++)
      im->at[i][j] = 255 - im->at[i][j];
}

void binarize(image *im) {
  for (int i = 0; i < im->h; i++)
    for (int j = 0; j < im->w; j++) {
      if (im->at[i][j] < 128) {
        im->at[i][j] = 0;
      } else {
        im->at[i][j] = 255;
      }
    }
}

void flip_horizontal(image *im) {
  for (int i = 0; i < im->h; i++)
    for (int j = 0; j < (im->w) / 2; j++) {
      uint8_t tmp = im->at[i][j];
      im->at[i][j] = im->at[i][im->w - 1 - j];
      im->at[i][im->w - 1 - j] = tmp;
    }
}
