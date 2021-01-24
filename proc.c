//
// Created by vsevolod on 24.01.2021.
//

#include <malloc.h>
#include "image.h"
#include "proc.h"
#include "header.h"
#include "util.h"

enum read_status from_bmp( FILE* in, struct image* img ) {
        struct bmp_header header;
        if (!in) {
            return READ_INVALID_SIGNATURE;
        }

        if (!read_header(in, &header)) {
            return READ_INVALID_HEADER;
        }

        img->width  = header.biWidth;
        img->height = header.biHeight;
        if (read_image(in, img)) {
            err("Can't read image\n");
        }
        return READ_OK;
}

enum write_status to_bmp( FILE* out, struct image const* img ) {
    struct bmp_header header = {
                    .bfType      = 0x4D42,
                    .bOffBits    = sizeof(struct bmp_header),
                    .biWidth     = img->width,
                    .biHeight    = img->height,
                    .biPlanes    = 1,
                    .biBitCount  = sizeof(struct pixel) * 8,
                    .biSizeImage = img->height * img->width * sizeof(struct pixel)
            };
    header.biSize    = header.bOffBits - 14;
    header.bfileSize = header.bOffBits + header.biSizeImage;

    if (!out) {
        return WRITE_ERROR;
    }

    if (!write_header(out, &header)) {
        err("Can't write header\n");
    }

    if (write_image(out, img)) {
        err("Can't write image\n");
    }
    return WRITE_OK;
}

struct image rotate(struct image source) {

    struct image new_image = {0};
    uint64_t weight = new_image.height = source.width;
    uint64_t height = new_image.width  = source.height;

    new_image.data = (struct pixel*) malloc(sizeof(struct pixel) * height * weight);
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < weight; j++) {
            new_image.data[j * height + i] = source.data[(height - i - 1) * weight + j];
        }
    }
    return new_image;
}
