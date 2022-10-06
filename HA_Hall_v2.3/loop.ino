void loop() {

  // Comprobacion de Wifi
  if (!WiFi.isConnected()) { Wificonnect(); }

  //OTA
  ArduinoOTA.handle();

  // Comprobacion de MQTT
  if (!MQTTClient.connected()) { MQTTconnect(); }
  MQTTClient.loop();

  // CLIMA
  if (millis() - clima_check > (5 * 60000) || enviar == 1) {
    clima_check = millis();
    temp = dht.readTemperature();
    temp = temp - 2.6;
    hume = dht.readHumidity();
    if (temp != temp_anterior) {
      String S_temp = String(temp, 2);
      MQTTout("arduino/hall/temperatura", S_temp);
      temp_anterior = temp;
    }
    if (hume != hume_anterior) {
      String S_hume = String(hume, 2);
      MQTTout("arduino/hall/humedad", S_hume);
      hume_anterior = hume;
    }
    enviar = 0;
  }

  // PUERTA
  puerta = digitalRead(pinPuerta);
  if (puerta == 1 and abierta_desde == 0) {
    abierta_desde = millis();
    digitalWrite(pinLed, LOW);
  }
  if (puerta == 0 and abierta_desde > 0) {
    puerta_tiempo = (millis() - abierta_desde) / 1000;
    String S_puerta_tiempo = String(puerta_tiempo, 2);
    abierta_desde = 0;
    digitalWrite(pinLed, HIGH);
    if (S_puerta_tiempo != "0.00") {
      MQTTout("arduino/hall/puerta", S_puerta_tiempo);
      Webhook("puerta", puerta_tiempo);
    }
  }
}
