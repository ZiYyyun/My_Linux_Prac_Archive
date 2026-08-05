#include "mqtt_prac.h"

static void TCP_Create()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { printf("Create socket failed!\n"); return 1;}

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AD_INET;
    serv_addr.sin_port = htons(1883);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

}