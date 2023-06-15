#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "pixel_operations.h"
#include "stb_image.h"
#include "stb_image_write.h"

void remove_pixel(uint8_t *line, double *e, int w) {
  double min = e[0];
  int ind = 0;
  for (int j = 0; j < w; j++) {
    if (e[j] < min) {
      min = e[j];
      ind = j;
    }
  }

  for (int j = ind; j < w - 1; j++) {
    line[j] = line[j + 1];
  }
}

void reduce_one_pixel(image *im, energy *e) {
  compute_energy(im, e);
  for (int i = 0; i < im->h; i++) {
    remove_pixel(im->at[i], e->at[i], im->w);
  }

  im->w = im->w - 1;
  e->w = e->w - 1;
}

void reduce_pixels(image *im, int n) {
  energy *e = energy_new(im->h, im->w);

  for (int i = 0; i < n; i++) {
    reduce_one_pixel(im, e);
  }

  energy_delete(e);
}

int best_column(energy *e) {
  double min = 255 * e->h + 1;
  int col = 0;

  for (int j = 0; j < e->w; j++) {
    double somme = 0;
    for (int i = 0; i < e->h; i++) {
      somme += e->at[i][j];
    }

    if (somme < min) {
      col = j;
      min = somme;
    }
  }

  return col;
}

void reduce_one_column(image *im, energy *e) {
  compute_energy(im, e);
  int col = best_column(e);
  for (int i = 0; i < e->h; i++)
    for (int j = col; j < e->w - 1; j++) {
      im->at[i][j] = im->at[i][j + 1];
    }

  im->w = im->w - 1;
  e->w = e->w - 1;
}

void reduce_column(image *im, int n) {
  energy *e = energy_new(im->h, im->w);

  for (int i = 0; i < n; i++) {
    reduce_one_column(im, e);
  }

  energy_delete(e);
}