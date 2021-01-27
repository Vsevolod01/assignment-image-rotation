//
// Created by vsevolod on 24.01.2021.
//

#include <malloc.h>
#include "image.h"
#include "proc.h"
#include "bmp_header.h"
#include "util.h"

enum read_status from_bmp( FILE* in, struct image* img ) {
        struct bmp_header header;
        if (!in) {
            return READ_INVALID_FILE;
        }

        if (!read_header(in, &header)) {
            return READ_INVALID_HEADER;
        }

        if (header.bfType != 0x4D42) {
            return READ_INVALID_SIGNATURE;
        }
        img->width  = header.biWidth;
        img->height = header.biHeight;
        if (read_image(in, img)) {
            return READ_IMAGE_ERROR;
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
        return WRITE_INVALID_FILE;
    }

    if (!write_header(out, &header)) {
        return WRITE_HEADER_ERROR;
    }

    if (write_image(out, img)) {
        return WRITE_IMAGE_ERROR;
    }
    return WRITE_OK;
}

//struct pixel pix_new(uint64_t i, uint64_t j, struct image* new_image) {
//    return new_image->data[j * new_image->width + i];
//}

static struct pixel pix_old(uint64_t i, uint64_t j, struct image* old_image) {
    return old_image->data[(old_image->height - i - 1) * old_image->width + j];
}

struct image rotate(struct image source) {

    struct image new_image = {0};
    uint64_t width = new_image.height = source.width;
    uint64_t height = new_image.width  = source.height;

    new_image.data = (struct pixel*) malloc(sizeof(struct pixel) * height * width);
    for (uint64_t i = 0; i < height; i++) {
        for (uint64_t j = 0; j < width; j++) {
            new_image.data[j * height + i] = pix_old(i, j, &source);
        }
    }
    return new_image;
}
