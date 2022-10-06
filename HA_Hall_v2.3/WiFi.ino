void Wificonnect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("SSID", "PASS");  // SSIS y PASS de tu red WiFi
  while (WiFi.status() != WL_CONNECTED) { delay(200); }
  ip = WiFi.localIP().toString();
}
