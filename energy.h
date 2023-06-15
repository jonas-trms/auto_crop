#ifndef ENERGY
#define ENERGY

#include "data_structures.h"
#include "image_operations.h"
#include <stdint.h>

energy *energy_new(int h, int w);
void energy_delete(energy *e);
void compute_energy(image *im, energy *e);
image *energy_to_image(energy *e);

#endif