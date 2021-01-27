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

    const char* read_errors[] = {[READ_INVALID_SIGNATURE] = "Invalid signature\n",
            [READ_INVALID_BITS] = "Invalid bits\n",
            [READ_INVALID_HEADER] = "Invalid header\n",
            [READ_INVALID_FILE] = "File reading error\n",
            [READ_IMAGE_ERROR] = "Image reading error\n"
    };
    enum read_status rst = from_bmp(old, &img);
    if (rst != READ_OK) err(read_errors[rst]);
    else fprintf(stdout, "Read successfully\n");

    FILE* new = NULL;
    bool open_new = open_file(&new, "new_file.bmp", "wb");
    if (!open_new) {
        err("Can't create new file\n");
    }

    struct image new_img = rotate(img);

    const char* write_errors[] = {[WRITE_HEADER_ERROR] = "Can't write header\n",
           [WRITE_IMAGE_ERROR] = "Can't write image\n",
           [WRITE_INVALID_FILE] = "File writing error"
    };
    enum write_status wst = to_bmp(new, &new_img);
    if (wst != WRITE_OK) err(write_errors[wst]);
    else fprintf(stdout, "Written successfully\n");

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
