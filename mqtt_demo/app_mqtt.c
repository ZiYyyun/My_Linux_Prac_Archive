#include "app_mqtt.h"

MQTTClient client; // mqtt客户端句柄
MQTTClient_connectOptions conn_opts =
    MQTTClient_connectOptions_initializer; // mqtt连接参数
static int (*mqtt_recv_callback)(char *json) = NULL;
static MQTTClient_message pubmsg = MQTTClient_message_initializer;

/**
 * @brief 初始化mqtt客户端
 */
int app_mqtt_init() {
  if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
    printf("MQTT Connect Failed...");
    MQTTClient_destroy(client);
    return -1;
  }

  if (MQTTClient_setCallbacks(client, NULL, conn_opts, msgarrvd, delivered)) {
  }
}

/**
 * @brief 关闭mqtt客户端
 */
void app_mqtt_close();

/**
 * @brief 发送消息
 */
int app_mqtt_send(char *json);

/**
 * @brief 注册接收处理接收到的消息的回调函数
 */
void app_mqtt_registerRecvCallback(int callback(char *json));