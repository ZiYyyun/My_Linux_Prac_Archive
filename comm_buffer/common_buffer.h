#ifndef COMMON_BUFFER_H
#define COMMON_BUFFER_H

#include <stdint.h>

typedef enum {

  COM_FAIL = -1,

  COM_OK = 0

} ComStatus;

typedef struct {

  char *buf;

  uint16_t size;

  uint16_t used_len;

} SubBuffer;

typedef struct {

  SubBuffer *buf_arr[2];

  uint8_t read_index;

  uint8_t write_index;

} DoubleBuffer;

ComStatus Common_Buffer_CreateDoubleBuffer(DoubleBuffer **buffer,
                                           uint16_t size);

void Common_Buffer_Destroy(DoubleBuffer *buffer);

#endif