#include "common_buffer.h"

ComStatus Common_Buffer_CreateDoubleBuffer(DoubleBuffer **buffer,
                                           uint16_t size) {
  SubBuffer *readBuffer;
  readBuffer = malloc(sizeof(SubBuffer));
  readBuffer->buf = malloc(size);

  SubBuffer *writeBuffer;
  writeBuffer = malloc(sizeof(SubBuffer));
  writeBuffer->buf = malloc(size);

  DoubleBuffer *db;
  db = malloc(sizeof(DoubleBuffer));

  
}