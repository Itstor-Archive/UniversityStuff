#include <WiFi.h>
#include "PubSubClient.h"
#include <DHT.h>

#define LDR_PIN 36
#define DHTPIN 13
#define DHTTYPE DHT11

const char * SSID = "ITS-ASRAMA-F";
const char * PASSWORD = "itssurabaya";
const char * MQTT_SERVER = "10.8.108.230";
const char * MQTT_USER = "user";
const char * MQTT_PASS = "user";
const String DEVICES_ID = "d292e0a2-5d98-11ed-9b6a-0242ac120002";
const String SENSORID_LDR = "2bbb3b54-421b-11ed-a552-00ff00d6b0a0";
const String SENSORID_HUMID = "9c48521e-4881-11ed-bd79-00ff00d6b0a0";
const String SENSORID_TEMP = "ad433d7c-4881-11ed-bd79-00ff00d6b0a0";
const String TOPICS = "iot/devices/" + DEVICES_ID + "/";
const String LDR_TOPICS = TOPICS + "ldr/";
const String HUMID_TOPICS = TOPICS + "humid/";
const String TEMP_TOPICS = TOPICS + "temp/";
unsigned long upTime;

WiFiClient wifiClient;
DHT dht(DHTPIN, DHTTYPE);
PubSubClient client(wifiClient);

void setup() {
    Serial.begin(115200);
    delay(10);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    pinMode(LDR_PIN, INPUT);

    client.setServer(MQTT_SERVER, 1883);
}

void loop() {
    delay(2000);

    if (!client.connected()) {
        reconnect();
    }

    int ldrValue = analogRead(LDR_PIN);
    float humidValue = dht.readHumidity();
    float tempValue = dht.readTemperature();

    Serial.println("LDR Sensor Value: " + String(ldrValue));
    Serial.println("DHT Temp Sensor Value: " + String(tempValue));
    Serial.println("DHT Humid Sensor Value: " + String(humidValue));

    pubData((LDR_TOPICS + "value").c_str(), ("{ \"id\" : \"" + SENSORID_LDR + "\", " + "\"value\": " + String(ldrValue) + " }").c_str());
    if (!isnan(humidValue)) pubData((HUMID_TOPICS + "value").c_str(), ("{ \"id\" : \"" + SENSORID_HUMID + "\", " + "\"value\": " + String(humidValue) + " }").c_str());
    if (!isnan(tempValue)) pubData((TEMP_TOPICS + "value").c_str(), ("{ \"id\" : \"" + SENSORID_TEMP + "\", " + "\"value\": " + String(tempValue) + " }").c_str());

    upTime = millis();

    pubData((TOPICS + "status").c_str(), ("{ \"id\" : \"" + DEVICES_ID + "\", " + "\"up_time\" :" + String(upTime) + " }").c_str());
}

void pubData(const char * topic, const char * payload) {
    if (client.publish(topic, payload)) {
        Serial.print("Success: ");
    } else {
        Serial.print("Failed: ");
    }

    Serial.print(topic);
    Serial.print(" ");
    Serial.print(payload);

    Serial.println();
}

void reconnect() {
    Serial.println("In reconnect...");
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("Arduino Weather Sensor", MQTT_USER, MQTT_PASS)) {
            Serial.println("connected");
        } else {
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}