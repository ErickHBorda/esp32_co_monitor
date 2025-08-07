# 🌐 ESP32 AirGuard Dashboard

Este es un proyecto IoT que utiliza un **ESP32**, un **sensor de monóxido de carbono (MQ7)**, y una interfaz web construida con React para **monitorear en tiempo real la calidad del aire** y **controlar un LED** a través de **MQTT**.

---

## 🚀 ¿Qué hace este proyecto?

- Mide la concentración de **monóxido de carbono (CO)** con el sensor **AJ-MQ7**.
- Calcula una estimación en **ppm (partes por millón)**.
- Envía los datos mediante **MQTT** a un **panel web**.
- Si los niveles de CO son peligrosos, **envía una alerta** visual.
- Permite **encender o apagar** un LED desde el panel web.
- Detecta si el ESP32 está **desconectado**.

---

## 🧠 Tecnologías usadas

### 🖥️ Frontend (interfaz web)
- React + Tailwind CSS
- MQTT.js (cliente MQTT)
- Iconos de `react-icons`
- Recharts (para gráficos en tiempo real)

### 🤖 Backend (ESP32)
- Arduino/C++
- Sensor MQ7
- WiFi y MQTT (usando `WiFi.h` y `PubSubClient.h`)
- Broker MQTT público: `broker.hivemq.com`

---

## 🛠️ Cómo usarlo

### 1. Clona este repositorio

```bash
git clone https://github.com/tu-usuario/esp32-airguard-dashboard.git
cd esp32-airguard-dashboard
````
### 2. Cambia o agrega más cogigo y súbelo a tu microcontrolador ESP32

---
### ✍️ Autor
- Erick Huamán – Proyecto educativo IoT

Si te fue útil este proyecto, ¡⭐ dale estrella en GitHub!
