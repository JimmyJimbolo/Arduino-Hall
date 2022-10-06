// DOMOTICA: HA_Hall
//
// SENSORES: Puerta, clima
// MQTT (arduino/hall/...)
// OTA
//
// V1.1 MQTT: Reconexion en caso de desconexion
// V1.2 Funciones separadas para conexion/reconexion a Wifi y MQTT
// V1.3 Refresco de la IP al reconectar MQTT
// v1.4 Cambios menores. Se elimina el chequeo de aire.
// v1.5 Se calibra la temperatura (-2,6ºC) por tapa cerrada
//      Led buildin se inicia apagado
// v1.6 Se inicia OTA antes que MQTT
// v1.7 Se evitar enviar mqtt de puerta si tiempo=0.00
// v2.0 Integracion de Webhook para informar de tiempo de puerta abierta a traves de Macrodroid
// v2.1 Limpieza de codigo
// v2.2 Envio de lectura en el arranque
// v2.3 Suscripcion a canal MQTT "arduino/#" para recibir ordenes. 
//
// (C) Jimmy 2022
// -------------------------

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
WiFiClient Wclient;
PubSubClient MQTTClient(Wclient);
HTTPClient https;

int enviar = 1;

// MQTT
String ip;

// PUERTA
int pinPuerta = 5;  // D1 PUERTA
int pinLed = 2;     // LED Build
int puerta = 0;
float abierta_desde = 0;
float puerta_tiempo = 0;

// CLIMA
int pinClima = 13;  //D7 CLIMA
DHT dht(pinClima, DHT11);
float temp;
float temp_anterior = 0;
float hume;
float hume_anterior = 0;
int clima_check = 0;

// WEBHOOK
String url = "https://trigger.macrodroid.com/ID/hall?"; // ID = ID Webhook de tu dispositivo receptor
