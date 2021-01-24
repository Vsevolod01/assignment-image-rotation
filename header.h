//
// Created by vsevolod on 24.01.2021.
//

#ifndef IMAGE_ROTATION_HEADER_H
#define IMAGE_ROTATION_HEADER_H
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

struct __attribute__((packed)) bmp_header {
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};

bool read_header( FILE* f, struct bmp_header* header );

bool write_header(FILE *f, struct bmp_header const *p_header);

#endif //IMAGE_ROTATION_HEADER_H
