/* DOMOTICA: HA_Hall

 SENSORES: CO (MQ7), puerta, clima
 MQTT (arduino/hall/...)
 OTA

 V1.1 MQTT: Reconexion en caso de desconexion.
 V1.2 Funciones separadas para conexion/reconexion a Wifi y MQTT.
 V1.3 Refresco de la IP al reconectar MQTT.
 v1.4 Cambios menores. Se elimina el chequeo de aire.
 v1.5 Se calibra la temperatura (-2,6ºC) por tapa cerrada.
      Led buildin se inicia apagado.
 v1.6 Se inicia OTA antes que MQTT.
 v1.7 Se evitar enviar mqtt de puerta si tiempo=0.00
 v2.0 Integracion de Webhook para informar de tiempo de puerta abierta a traves de Macrodroid.
 v2.1 Limpieza de codigo.
 v2.2 Envio de lectura en el arranque.
 v2.3 Suscripcion a canal MQTT "arduino/refrescar" para recibir ordenes de actualizacion.
 v2.4 Se fuerza que en la actualizacion se envien tambien temperatura y humedad.
 v2.5 Se desactiva el envio de Webhook para probar notificaciones Whatssapp desde HA.
 v2.6 Integracion de un sensor de luz
 v2.7 Al abrir puerta, envia mqtt de puerta abierta y dato de LDR para automatizacion de iluminacion

 (C) Jimmy 2022
 -------------------------
*/

#include <ESP8266WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
WiFiClient Wclient;
PubSubClient MQTTClient(Wclient);
// #include <ESP8266HTTPClient.h>
// HTTPClient https;

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

// SENSOR LUZ
int pinLuz = A0;
int Luz = 0;
int Luz_anterior = 0;
int Luz_check = 0;

// WEBHOOK
// String url = "https://trigger.macrodroid.com/5041bd55-6eb3-4310-aa9e-0ba623e2bbba/hall?";