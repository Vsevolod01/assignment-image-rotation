//
// Created by vsevolod on 24.01.2021.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "util.h"
_Noreturn void err(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    exit(1);
}

void usage()
{
    fprintf(stderr, "Usage: ./image-rotation BMP_FILE_NAME\n");
}

void error(int argc) {
    if (argc < 2) {
        usage();
        err("Not enough arguments \n");
    }
    else if (argc > 3) {
        usage();
        err("Too many arguments \n");
    }
}
