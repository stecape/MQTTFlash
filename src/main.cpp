#include <Arduino.h>

/*
 Basic MQTT example with Authentication

  - connects to an MQTT server, providing username
    and password
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic"
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "./HMI/db_HMI.h"

//Network params
byte macArduino[] = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ipArduino(192, 168, 2, 100);
IPAddress ipServer(192, 168, 2, 231);
EthernetClient ethClient;
PubSubClient MQTTclient(ethClient);

// Node identifier
String ID = "PLC";
//callback
void callback(char* topic, byte* payload, unsigned int length) {
  // Get messages
  String strTopic = (String) topic;
  //Gets the last part of the topic, after the ID + / (es: given the topic HMI/PLC/A, this will returns the substring after the ID ("PLC") + "/": "A")
  strTopic = strTopic.substring(strTopic.lastIndexOf(ID + "/")+(ID.length()+1));
  
  DynamicJsonDocument doc(1024); 

  // You can use a String as your JSON input.
  // WARNING: the string in the input  will be duplicated in the JsonDocument.
  deserializeJson(doc, (String)(char*)payload);
  JsonObject data = doc.as<JsonObject>();

  // parse them
  if (strTopic == "LL"){
    //this kind of frames will be structured like this:
    //{ID: #, cmd: #}

  }
  else if (strTopic == "LS"){
    //not a thing, statuses will never comes from HMI to PLC

  }
  else if (strTopic == "LC"){
    //this kind of frames will be structured like this:
    //{ID: #, cmd: #}

  }
  else if (strTopic == "AS"){
    //this kind of frames will be structured like this:
    //{ID: #, val: #}

  }
  else if (strTopic == "AA"){
    //not a thing, analogic actuals will never comes from HMI to PLC

  }
  else if (strTopic == "AlL"){
    //not a thing, logic alarms will never comes from HMI to PLC. Maybe I will implement single ack

  }
  else if (strTopic == "AlA"){
    //not a thing, logic alarms will never comes from HMI to PLC. Maybe I will implement single ack
    //or enables and boundaries parametrizazion

  }
  else if (strTopic == "Gen"){
    //stuffs like send all or alarms ack
    //{ID: "Ack", val: true}

  }

  // store to flash
  // Serial.print("Message arrived [");
  // Serial.print(topic);
  // Serial.print("] ");
  // for (int i=0;i<length;i++) {
  //   Serial.print((char)payload[i]);
  // }
  // Serial.println("");
  Serial.print("ID: ");
  Serial.println(data["ID"].as<int>());
  Serial.print("val: ");
  Serial.println(data["val"].as<float>(),5);
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!MQTTclient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (MQTTclient.connect("MQTTclient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      MQTTclient.publish("PLC/HMI","Connected");
      // ... and resubscribe
      MQTTclient.subscribe("HMI/PLC/#");
    } else {
     Serial.print("failed, rc=");
      Serial.print(MQTTclient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);

  MQTTclient.setServer(ipServer, 1883);
  MQTTclient.setCallback(callback);

  Ethernet.begin(macArduino, ipArduino);
  // Allow the hardware to sort itself out
  delay(1500);

}

void loop() {
  if (!MQTTclient.connected()) {
    reconnect();
  }
  MQTTclient.loop();
}