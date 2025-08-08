# 🌐 ESP32 Monitor de Monóxido de Carbono(CO)

Proyecto educativo IoT que utiliza un **ESP32** con el sensor **MQ7** para monitorear la concentración de **monóxido de carbono (CO)** en tiempo real.

---

## 🧠 ¿Qué hace este proyecto?

✅ Mide niveles de CO en el ambiente (ppm).  
✅ Muestra los datos en un panel web moderno.  
✅ Envío y recepción de datos en tiempo real vía MQTT.  
✅ Controla el encendido/apagado de un LED desde la interfaz.  
✅ Muestra alertas si hay niveles peligrosos de CO.  
✅ Detecta si el ESP32 está desconectado.

---

## 🛠️ Tecnologías utilizadas

### 🔌 Hardware
- ESP32 DevKit
- Sensor MQ7 (AJ-MQ7)
- LED + resistencia
- Conexión WiFi

### 💻 Software
- Arduino C++
- HiveMQ (broker MQTT público)

---

## 🧩 Estructura de temas MQTT

| Tema MQTT              | Descripción                              |
|------------------------|------------------------------------------|
| `iot/sensor/mq7`       | Valor analógico del sensor               |
| `iot/sensor/ppm`       | Estimación en ppm de CO                  |
| `iot/alert/mq7`        | Mensaje de alerta si el CO es peligroso  |
| `iot/led/control`      | Recibe "on" o "off" desde el panel web   |
| `iot/led/status`       | Reporta el estado actual del LED         |

---

## 🚀 Cómo usarlo

### 1. Clona el repositorio

```bash
git clone https://github.com/tu-usuario/esp32-airguard-dashboard.git
cd esp32-airguard-dashboard
````

### 2. Carga el código al ESP32

Abre el archivo `src/main.cpp` en el **Arduino IDE** o **VSCode con PlatformIO**, y modifica:

```cpp
const char* ssid = "nombre_wifi";       // Tu red WiFi
const char* password = "password";      // Contraseña
```

Conecta tu ESP32, selecciona el puerto y placa correcta, y sube el código.

---

### 3. Crea y ejecuta tu propio cliente para visualizar los datos

* Puedes desarrollar tu propio proyecto (por ejemplo, usando React, Angular, Vue, u otra tecnología de tu preferencia) para suscribirte a los topics publicados por el ESP32 mediante MQTT y mostrar los datos en tiempo real.
* Asegúrate de conectarte al mismo broker MQTT y usar los topics que el ESP32 publica para recibir la información de los sensores.

---

## 📌 Requisitos

* ESP32 DevKit
* Sensor AJ-MQ7
* Cable USB y conexión a Internet
* IDE para cargar el código al ESP32 (Arduino IDE o VS Code)

---

## 💡 ¿Qué es el MQ7?

El **sensor MQ7** mide la concentración de monóxido de carbono (CO) en el aire. Este gas es **altamente tóxico** y no tiene olor, por eso es útil tener un sistema de detección.

* **Valor analógico**: nivel de voltaje leído del sensor.
* **PPM**: estimación de concentración de CO (partes por millón).

---

## 🔒 Notas de seguridad

> Este sistema **no debe usarse como detector oficial de gases tóxicos** en entornos críticos. Es un proyecto educativo con aproximaciones. Para sistemas reales de detección de CO, se deben usar sensores calibrados y certificados.

---

## ✅ Mejoras futuras

* Guardar historial en base de datos (Firebase, MongoDB, etc)
* Crear app móvil
* Notificaciones push o correo
* Medir más gases con sensores adicionales (MQ2, MQ135...)

---

## ✍️ Autor

**Erick Huaman Borda** 
📧 *Si te gustó este proyecto, no dudes en dejar una ⭐ en el repo.*

---

## 🪄 Licencia

Este proyecto es de uso libre para fines educativos y personales. ¡Explóralo y modifícalo como gustes!

---
