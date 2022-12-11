#define LDR_PIN 15
#define THRESHOLD 1000 

int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(LDR_PIN);
  Serial.println(value);
  
  if (value > THRESHOLD){
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Lampu OFF");
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Lampu ON");
  }
  delay(200);
}