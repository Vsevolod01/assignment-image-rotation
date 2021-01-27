//
// Created by vsevolod on 24.01.2021.
//

#include "header.h"

bool read_header( FILE* f, struct bmp_header* header ) {
    return fread( header, sizeof( struct bmp_header ), 1, f );
}

bool write_header(FILE *f, struct bmp_header const *p_header) {
    return fwrite(p_header, sizeof(struct bmp_header), 1, f);
}
