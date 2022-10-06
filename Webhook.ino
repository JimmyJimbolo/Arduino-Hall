// https://trigger.macrodroid.com/ID/hall? parametro=[parametro]&dato_1=[dato_1];  // ID Webhook del dispostivo que recibe el mensaje

void Webhook(String parametro, float dato_1) {
  WiFiClientSecure WclientS;
  WclientS.setInsecure();
  https.begin(WclientS, url + "parametro=" + parametro + "&dato_1=" + String(dato_1));
  int httpCode = https.GET();
  https.end();
}
