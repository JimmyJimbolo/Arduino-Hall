void MQTTconnect() {
  while (!MQTTClient.connected()) {
    if (MQTTClient.connect("", "jimbo", "aquiles13")) {
    } else {
      delay(250);
    }
  }
  MQTTClient.setCallback(MQTTin);
  MQTTClient.subscribe("arduino/#");
  MQTTout("arduino/hall/ip", "0");
  MQTTout("arduino/hall/ip", ip);
}

void MQTTout(String tema, String dato) {
  char topic[30];
  tema.toCharArray(topic, 30);
  char payload[30];
  dato.toCharArray(payload, 30);
  MQTTClient.publish(topic, payload);
}

void MQTTin(char* topic, byte* message, unsigned int length) {
  String strTopic = String((char*)topic);
  if (strTopic == "arduino/refrescar") {
    MQTTout("arduino/hall/ip", ip);
    temp_anterior = 0;
    hume_anterior = 0;
    enviar = 1;
  }
}
//  Serial.print("Message arrived on topic: ");
//  Serial.print(topic);
//  Serial.print(". Message: ");
//  String messageTemp;

//  for (int i = 0; i < length; i++) {
//    Serial.print((char)message[i]);
//    messageTemp += (char)message[i];
//  }
//  Serial.println();
// Feel free to add more if statements to control more GPIOs with MQTT
// If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
// Changes the output state according to the message
//  Serial.print("Changing output to ");
//  if(messageTemp == "on"){
//    Serial.println("on");
//    digitalWrite(ledPin, HIGH);
//  }
//  else if(messageTemp == "off"){
//    Serial.println("off");
//    digitalWrite(ledPin, LOW);
//  }