#ifndef __BUFFER_TEST_H__
#define __BUFFER_TEST_H__

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 64

typedef struct {
  char data[BUFFER_SIZE];
  int length;
} Buffer;

/* 双缓冲 */
typedef struct {
  Buffer buf[2];
  Buffer *write_buf;
  Buffer *read_buf;
} DoubleBuffer;

void DoubleBuffer_Init(DoubleBuffer *db);
void DoubleBuffer_Write(DoubleBuffer *db, const char *data);
void DoubleBuffer_Swap(DoubleBuffer *db);

#endif
