//
// Created by vsevolod on 23.01.2021.
//

#include <malloc.h>
#include "image.h"

uint64_t padding(const uint8_t width) {
    const uint8_t mod_4 = width * sizeof(struct pixel) % 4;
    const uint64_t padding = mod_4 ? 4 - mod_4 : mod_4;
    return padding;
}

enum read_status read_image(FILE *in, struct image *img) {
    img->data = (struct pixel*) malloc(sizeof(struct pixel) * img->width * img->height);

    for (size_t i = 0; i < img->height; i++) {
        fread(img->data + i * img->width, sizeof(struct pixel), img->width, in);
        fseek(in, padding(img->width), SEEK_CUR);
    }

    return READ_OK;
}

enum write_status write_image(FILE *out, struct image const *p_img) {
    const struct pixel trash_pixel = {0};
    for (size_t i = 0; i < p_img->height; i++) {
        fwrite(p_img->data + i * p_img->width, sizeof(struct pixel), p_img->width, out);
        fwrite(&trash_pixel, sizeof(struct pixel), padding(p_img->width), out);
    }

    return WRITE_OK;
}
