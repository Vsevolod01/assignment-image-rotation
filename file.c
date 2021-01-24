//
// Created by vsevolod on 24.01.2021.
//

#include "file.h"
bool open_file(FILE** file, const char* path, const char *mode) {
    *file = fopen(path, mode);
    return *file != NULL;
}

bool close_file(FILE** file) {
    return fclose(*file) == 0;
}
