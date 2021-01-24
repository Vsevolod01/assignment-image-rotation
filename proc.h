//
// Created by vsevolod on 24.01.2021.
//

#ifndef IMAGE_ROTATION_PROC_H
#define IMAGE_ROTATION_PROC_H

#include <stdbool.h>
#include <stdio.h>
#include "image.h"
#include "status.h"


enum read_status from_bmp( FILE* in, struct image* img );

enum write_status to_bmp( FILE* out, struct image const* img );

struct image rotate(struct image source);
#endif //IMAGE_ROTATION_PROC_H
