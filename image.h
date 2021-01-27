//
// Created by vsevolod on 23.01.2021.
//

#ifndef IMAGE_ROTATION_IMAGE_H
#define IMAGE_ROTATION_IMAGE_H

#include  <stdint.h>
#include "status.h"

struct pixel { uint8_t b, g, r; };

struct image {
    uint64_t width, height;
    struct pixel* data;
};

enum read_status read_image(FILE *in, struct image *img);

enum write_status write_image(FILE *out, struct image const *p_img);

#endif //IMAGE_ROTATION_IMAGE_H
