# Arduino-Hall
Integracion en Home Assistant (HA) con sensor de temperatura/humedad y sensor de puerta abierta.

Este codigo incluye:
- Registro en red WiFi.
- Comprobacion de la conexion WiFi y reconexion en caso de fallo.
- Registro en el broquer MQTT de Home Assistant (Mosquitto) para el envio y recepcion de datos hacia HA.
- Comprobacion del registro MQTT y reconexion en caso de fallo.
- Inicio de servicio OTA para actualizacion del codigo via WiFi.
- Envio de datos via WebHook directamente desde el Arduino.

Caracteristicas
- Envio de datos en el arranque. (Temperatura, humedad y direccion IP)
- Chequeo y envio de temperatura y humedad cada 5 minutos, solo si ha habido cambios desde la lectura anterior.
- Deteccion de puerta abierta y envio de su duraccion en segundos.
- Reenvio de datos al recibir un mensaje MQTT desde HA.
- Deteccion de nivel de luz (LDR) para automatizaciones de iluminacion.

v2.7
 - Se fuerza que en la actualizacion se envien tambien temperatura y humedad.
 - Se desactiva el envio de Webhook para probar notificaciones Whatssapp desde HA.
 - Integracion de un sensor de luz LDR.
 - Al abrir puerta, envia mqtt de puerta abierta y dato de LDR para automatizacion de iluminacion.
 
