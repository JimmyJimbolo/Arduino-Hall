void setup() {
  Serial.begin(115200);

  // MQTT
  MQTTClient.setServer("192.168.1.200", 1883);

  // PUERTA
  pinMode(pinPuerta, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);

  // CLIMA
  dht.begin();

  // OTA
  InitOTA();
}