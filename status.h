//
// Created by vsevolod on 24.01.2021.
//

#ifndef IMAGE_ROTATION_STATUS_H
#define IMAGE_ROTATION_STATUS_H

/*  deserializer   */
enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
    /* коды других ошибок  */
};

/*  serializer   */
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
    /* коды других ошибок  */
};

#endif //IMAGE_ROTATION_STATUS_H
