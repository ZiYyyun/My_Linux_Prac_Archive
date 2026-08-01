#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage:\n", "%s <on|off>\n", argv[0]);
    exit(-1);
  }
  if (!strcmp(argv[1], "on")) {
    printf("The command is LED on!\n");
  } else if (!strcmp(argv[1], "off")) {
    printf("The command is LED off!\n");
  } else {
    fprintf(stderr, "usage:\n", "%s <on|off>\n", argv[0]);
    exit(-1);
  }
}