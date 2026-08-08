#include "buffer_test.h"
#include <assert.h>
#include <stdio.h>

void DoubleBuffer_Init(DoubleBuffer *db) {
  db->write_buf = &db->buf[0];
  db->read_buf = &db->buf[1];

  db->write_buf->length = 0;
  db->read_buf->length = 0;
}

void DoubleBuffer_Write(DoubleBuffer *db, const char *data) {
  strcpy(db->write_buf->data, data);
  db->write_buf->length = strlen(data);
}

void DoubleBuffer_Swap(DoubleBuffer *db) {
  Buffer *temp;
  db->write_buf = temp;
  db->write_buf = db->read_buf;
  db->read_buf = temp;
}

// 交换两个整数
void swap(int *a, int *b) {
  assert(a != NULL && b != NULL);
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void swapptr(int **a, int **b) {
  int *temp;
  temp = *a;
  *a = *b;
  *b = temp;
}



int main(void) {
    int x = 11, y = 22;
    int *pa = &x, *pb = &y;
  printf("%d, %d\n", *pa, *pb);
  swap(pa,pb);
  printf("%d, %d\n", *pa, *pb);
}