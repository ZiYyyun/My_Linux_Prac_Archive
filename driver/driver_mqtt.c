#ifndef __DRIVER_MQTT_H__
#define __DRIVER_MQTT_H__

#include "driver_mqtt.h"
#include <assert.h>


static MQTTClient client;
static MQTTClient_connectOptions conn_opts =
    MQTTClient_connectOptions_initializer;

static MqttReceiveCallback receiveHandle;

void Driver_MQTT_ConnectionLost(void *context, char *cause) {
  res = MQTTClient_connect(client, &conn_opts);
    assert(res);
  res = MQTTClient_subscribe(client, PULL_TOPIC, MQTTREASONCODE_GRANTED_QOS_0);
    assert(res)
  continue;
}

int Driver_MQTT_MessageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    receiveHandle(message->payloadlen, (char*)message->payload);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);

    return -1;
}

void Driver_MQTT_DeliveryComplete(void *context, MQTTClient_deliveryToken dt)
{
  printf("message send succ!");
}

void Driver_MQTT_Init(MqttReceiveCallback rcb)
{
  //创建客户端
  res = MQTTClient_create(&client, MQTT);
  //设置回调
  MQTTClient_setCallbacks(MQTTClient handle, void *context, MQTTClient_connectionLost *cl, MQTTClient_messageArrived *ma, MQTTClient_deliveryComplete *dc);
  //连接服务器
  MQTTClient_connect(MQTTClient handle, MQTTClient_connectOptions *options);
  //订阅topic
  MQTTClient_subscribe(MQTTClient handle, const char *topic, int qos);                                              
}

#endif
