#include <WiFi.h>
#include <PubSubClient.h>
#include <math.h>

const char* ssid = "nombre_wifi"; //Tu wifi
const char* password = "password"; //Cambia por la contraseña de tu wifi

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

const int ledPin = 14; // Pin de salida para el led
const int mq7Pin = 33; // Usamos el pin de salida analógica GPIO 33 para el sensor AJ-MQ7

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastSensorRead = 0;
const unsigned long interval = 5000;

float calcularPPM(int analogValue) {
  // Simulación de curva logarítmica (aproximación general)
  float voltage = (analogValue / 4095.0) * 5.0; // Voltaje estimado
  float ppm = pow(voltage, 2.0) * 100; // Fórmula estimada
  return ppm;
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (message == "on") {
    digitalWrite(ledPin, HIGH);
    client.publish("iot/led/status", "on", true);
  } else if (message == "off") {
    digitalWrite(ledPin, LOW);
    client.publish("iot/led/status", "off", true);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando al broker MQTT... ");
    if (client.connect("ESP32Client_IoT")) {
      Serial.println("¡Conectado!");
      client.subscribe("iot/led/control");
    } else {
      Serial.print("Fallo, rc=");
      Serial.println(client.state());
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(mq7Pin, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Conectando al WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi conectado.");
  client.setServer(mqtt_server, mqtt_port);
  client.publish("iot/status", "ESP32 Online", true);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastSensorRead >= interval) {
    lastSensorRead = now;

    int analogValue = analogRead(mq7Pin);
    float ppm = calcularPPM(analogValue);

    Serial.print("MQ7 Valor: ");
    Serial.print(analogValue);
    Serial.print(" | Estimado CO: ");
    Serial.print(ppm);
    Serial.println(" ppm");

    // Envío de datos a los topics MQTT
    client.publish("iot/sensor/mq7", String(analogValue).c_str());
    client.publish("iot/sensor/ppm", String(ppm).c_str());

    // Enviar alerta si supera umbral
    if (ppm > 100.0) {
      client.publish("iot/alert/mq7", "⚠️ Nivel peligroso de CO detectado. ¡Ventilar la habitación!");
      Serial.println("🚨ALERTA: Monóxido de carbono alto");
    }
  }
}