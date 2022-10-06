// https://trigger.macrodroid.com/5041bd55-6eb3-4310-aa9e-0ba623e2bbba/hall? parametro=[parametro]&dato_1=[dato_1];

void Webhook(String parametro, float dato_1) {
  WiFiClientSecure WclientS;
  WclientS.setInsecure();
  https.begin(WclientS, url + "parametro=" + parametro + "&dato_1=" + String(dato_1));
  int httpCode = https.GET();
  https.end();
  // MQTTout ("arduino/hall/", url+"parametro="+parametro+"&dato_1="+String(dato_1));
  // MQTTout ("arduino/hall/", String(httpCode));
}