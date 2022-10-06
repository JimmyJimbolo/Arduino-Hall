void setup() {
  Serial.begin(115200);

  // MQTT
  MQTTClient.setServer("IP", 1883);  // IP del broquer MQTT

  // PUERTA
  pinMode(pinPuerta, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);

  // CLIMA
  dht.begin();

  // OTA
  InitOTA();
}
