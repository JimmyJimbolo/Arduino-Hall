void MQTTconnect() {
  while (!MQTTClient.connected()) {
    if (MQTTClient.connect("", "USUARIO", "PASS")) {  // Usuario y contraseña del cliente MQTT
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
  char payload[120];
  dato.toCharArray(payload, 120);
  MQTTClient.publish(topic, payload);
}

void MQTTin(char* topic, byte* message, unsigned int length) {
  String strTopic = String((char*)topic);
  if (strTopic == "arduino/refrescar") {
    MQTTout("arduino/hall/ip", ip);
    enviar = 1;
  }
}
