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

#endif
