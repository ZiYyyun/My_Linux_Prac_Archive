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

void mqtt_main(void)
{
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.clientID.cstring = "gateway_client_01";
    data.keepAliveInterval = 60;
    data.cleansession = 1;

    len = MQTTSerialize_connect(buf, sizeof(buf), &data);
    send(sockfd, buf, len, 0);

    //receive and chaijie CONNACK
    rc = recv(sockfd, buf, 0);
    if (rc <= 0) {
        printf("did not receive Broker response...\n");
        close(sockfd);
        return 1;
    }

    // PUBLISH baowen
    unsigned char dup = 0;
    int qos = 0;
    unsigned char retained = 0;
    unsigned short packetid = 1;

    char *payload = "hello from C gateway";
    int payloadlen = strlen(payload);

    len = MQTTSerialize_publish(buf, sizeof(buf), dup, qos, retained, packetid, topicString);


}