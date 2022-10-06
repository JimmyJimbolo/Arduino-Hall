# Arduino-Hall
Integracion en Home Assistant (HA) con sensor de temperatura/humedad y sensor de puerta abierta

Este codigo incluye:
- Registro en red WiFi
- Registro en el broquer MQTT de Home Assistant (Mosquitto) para el envio de datos hacia HA
- Inicio de servicio OTA para actualizacion del codigo via WiFi
- Posibilidad de envio de datos via WebHook directamente desde el Arduino.

Caracteristicas
- Envio
- Chequeo y envio de temperatura / humedad cada 5 minutos y solo si ha habido cambios desde la lectura anterior
