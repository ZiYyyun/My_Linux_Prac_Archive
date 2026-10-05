#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LED_BRIGHTNESS "/sys/class/leds/sys-led/brightness"

void main(int argc, char *argv[])
{
    int fd, delay;
    fd = open(LED_BRIGHTNESS, 0_RDWR);

    if(fd == 0)
    {
        oerror("open error");
        exit(-1);
    }

    sscanf(argv[1], "%d", &delay);

    while(1)
    {
        write(fd, "1", 1);
        sleep(delay);
        write(fd, "0", 1);
        sleep(delay);
    }
}
