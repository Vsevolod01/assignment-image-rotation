//
// Created by vsevolod on 24.01.2021.
//

#ifndef IMAGE_ROTATION_FILE_H
#define IMAGE_ROTATION_FILE_H

#include <stdio.h>
#include <stdbool.h>

bool open_file(FILE** file, const char* path, const char *mode);

bool close_file(FILE** file);

#endif //IMAGE_ROTATION_FILE_H
