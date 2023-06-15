#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <stdint.h>

struct image {
    uint8_t **at;
    int h;
    int w;
};

typedef struct image image;

struct energy {
    double **at;
    int h;
    int w;
};

typedef struct energy energy;

#endif
