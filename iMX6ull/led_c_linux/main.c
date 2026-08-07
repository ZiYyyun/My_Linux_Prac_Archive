#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define LED_BRIGHTNESS "/sys/class/leds/sys-led/brightness"

void main(){
  int fd;
  fd = open(LED_BRIGHTNESS, 0_RDWR);
  if (fd < 0) {
    perror("open error");
    exit(-1);
  }
  while (1) {
    write(fd, "1", 1);
    sleep(1);
    write(fd, "0", 1);
    sleep(1);
  }
}