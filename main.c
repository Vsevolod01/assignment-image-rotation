//
// Created by vsevolod on 23.01.2021.
//
#include <stdio.h>
#include "image.h"
#include "proc.h"
#include "util.h"
#include "file.h"

int main(int argc, char** argv) {
    error(argc);

    FILE* old = NULL;
    bool open_old = open_file(&old, argv[1], "rb");
    if (!open_old) {
        err("Can't open old file\n");
    }

    struct image img = {0};

    switch (from_bmp(old, &img)) {
        case READ_OK:
            printf("Read successfully\n");
            break;
        case READ_INVALID_SIGNATURE:
            err("Invalid signature\n");
        case READ_INVALID_BITS:
            err("Invalid bits\n");
        case READ_INVALID_HEADER:
            err("Invalid header\n");
    }

    FILE* new = NULL;
    bool open_new = open_file(&new, "new_file.bmp", "wb");
    if (!open_new) {
        err("Can't create new file\n");
    }

    struct image new_img = rotate(img);
    switch (to_bmp(new, &new_img)) {
        case WRITE_OK:
            printf("Written successfully\n");
            break;
        case WRITE_ERROR:
            err("Some errors occurred\n");
    }

    bool close_old = close_file(&old);
    if(!close_old) {
        err("Can't close old file\n");
    }

    bool close_new = close_file(&new);
    if(!close_new) {
        err("Can't close new file\n");
    }
    return 0;
}
