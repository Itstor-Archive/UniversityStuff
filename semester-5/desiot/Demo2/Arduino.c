#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <Arduino_JSON.h>

#define LDR_PIN 36
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const String API_KEY = "DHs2mWcBWzTqKnz9hP^BMEqcSR%Rf$T";
const String BASE_URL = "http://192.168.219.24/desiot/api.php?api_key=" + API_KEY;
const String SENSORID_LDR = "2bbb3b54-421b-11ed-a552-00ff00d6b0a0";
const String SENSORID_HUMID = "9c48521e-4881-11ed-bd79-00ff00d6b0a0";
const String SENSORID_TEMP = "ad433d7c-4881-11ed-bd79-00ff00d6b0a0";
const char * ssid = "ITS-ASRAMA-F";
const char * password = "itssurabaya";

void sendData(String value, String sensor_id);

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LDR_PIN, INPUT);
}

void loop() {
  delay(5000);

  int ldrValue = analogRead(LDR_PIN);
  float humidValue = dht.readHumidity();
  float tempValue = dht.readTemperature();
  
  Serial.println("LDR Sensor Value: " + String(ldrValue));
  Serial.println("DHT Temp Sensor Value: " + String(tempValue));
  Serial.println("DHT Humid Sensor Value: " + String(humidValue));

  sendData(String(ldrValue), SENSORID_LDR);
  if (!isnan(humidValue)) sendData(String(humidValue), SENSORID_HUMID);
  if (!isnan(tempValue)) sendData(String(tempValue), SENSORID_TEMP);
}

void sendData(String value, String sensor_id){
  HTTPClient http;

  http.begin(BASE_URL);
  http.addHeader("Content-Type", "application/json");

  int responseCode = http.POST("{\"id\":\"" + sensor_id + "\", \"value\":" + value + "}");

  if (responseCode > 0){
    if (responseCode == 200) {
      Serial.println("Success");
    } else {
      JSONVar response = JSON.parse(http.getString());
      Serial.println("Failed");
      Serial.println("Response Code: " + String(responseCode));
      Serial.println("Message: " + JSON.stringify(response["message"]));
      // Serial.println(http.getString());
    }
  } else {
    Serial.println("Can't connect to API");
  }

  http.end();
}
