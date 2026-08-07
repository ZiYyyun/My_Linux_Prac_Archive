#include "app_mqtt.h"

MQTTClient client;
static int (*mqtt_recv_callback)(char *json) = NULL;

static void delivered(void *context, MQTTClient_deliveryToken dt) {
  log_debug("消息发送完成");
}

static int msgarrvd(void *context, char *topicName, int topicLen,
                    MQTTClient_message *message) {
  int result = 0;
  if (mqtt_recv_callback != NULL) {
    result = mqtt_recv_callback(message->payload) == 0 ? 1 : 0;
  }

  MQTTClient_freeMessage(&message);
  MQTTClient_free(topicName);

  return result;
}

/**
 * @brief 初始化mqtt客户端
 */
int app_mqtt_init(MQTTClient_create(&client, const char *serverURI,
                                    const char *clientId, int persistence_type,
                                    void *persistence_context)) {
  if (MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE,
                        NULL) != MQTTCLIENT_SUCCESS) {
    printf("MQTT Client create failed");
    return -1;
  }

  if (MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered) !=
      MQTTCLIENT_SUCCESS) {
    printf("MQTT CallBack function regist failed...");
    MQTTClient_destory(&client);
  }

  if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
    printf("MQTT回调函数注册失败");
    MQTTClient_destroy(&client);
  }

  if (MQTTClient_subscribe(&client, TOPIC_PULL, QOS) != MQTTCLIENT_SUCCESS) {
    printf("MQTT 订阅主题失败");
    MQTTClient_disconnected(client, TIMEOUT);
    MQTTClient_destroy(&client);
    return -1;
  }
}

/**
 * @brief 关闭mqtt客户端
 */
void app_mqtt_close(void) {
  MQTTClient_unsubscribe(client, TOPIC_PULL);
  MQTTClient_disconnect(client, TIMEOUT);
  MQTTClient_destroy(&client);
}

/**
 * @brief 发送消息
 */
int app_mqtt_send(char *json) {
  pubmsg.payload = json;
  pubmsg.payloadlen = (int)strlen(json);
  pubmsg.qos = QOS;

  if (MQTTClient_publishMessage(client, TOPIC_PUSH, &pubmsg, NULL) !=
      MQTTCLIENT_SUCCESS) {
    printf("MQTT Publish message Failed!");
    return -1;
  }
  return 0;
}

/**
 * @brief 注册接收处理接收到的消息的回调函数
 */
void app_mqtt_registerRecvCallback(int (*callback)(char *json)) {
  mqtt_recv_callback = callback;
  return 0;
}

int main(int argc, char const *argv[]) {
  // 初始化
  app_mqtt_init();
  // 注册接收的回调函数
  app_mqtt_registerRecvCallback(handle_callback);
  // 发送数据
  app_mqtt_send("{\"name\":\"tom\", \"age\":18}");
  // 休眠50秒，让当前运行的程序不立即结束 =》 为了能接受消息
  sleep(50);
  // 关闭
  app_mqtt_close();
  return 0;
}
