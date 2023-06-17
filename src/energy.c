#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "energy.h"
#include "stb_image.h"
#include "stb_image_write.h"

energy *energy_new(int h, int w) {
  energy *new_energy = malloc(sizeof(energy));
  new_energy->at = malloc(h * sizeof(double *));
  for (int i = 0; i < h; i++) {
    new_energy->at[i] = malloc(w * sizeof(double));
  }
  new_energy->h = h;
  new_energy->w = w;
  return new_energy;
}

void energy_delete(energy *e) {
  for (int i = 0; i < e->h; i++) {
    free(e->at[i]);
  }

  free(e->at);
  free(e);
}

void compute_energy(image *im, energy *e) {
  for (int i = 0; i < im->h; i++) {
    int it = (i > 0) ? i - 1 : i;
    int ib = (i < im->h - 1) ? i + 1 : i;
    for (int j = 0; j < im->w; j++) {
      int jl = (j > 0) ? j - 1 : j;
      int jr = (j < im->w - 1) ? j + 1 : j;
      e->at[i][j] =
          fabs((double)(im->at[i][jr] - im->at[i][jl])) / (double)(jr - jl) +
          fabs((double)(im->at[ib][j] - im->at[it][j])) / (double)(ib - it);
    }
  }
}

image *energy_to_image(energy *e) {
  image *im = image_new(e->w, e->h);

  double min = e->at[0][0];
  double max = e->at[0][0];

  for (int i = 0; i < e->h; i++)
    for (int j = 0; j < e->w; j++) {
      if (e->at[i][j] > max) {
        max = e->at[i][j];
      } else if (e->at[i][j] < min) {
        min = e->at[i][j];
      }
    }

  for (int i = 0; i < im->h; i++)
    for (int j = 0; j < im->w; j++) {
      im->at[i][j] = ((uint8_t)(e->at[i][j] - min) / (max - min)) * 255;
    }

  return im;
}