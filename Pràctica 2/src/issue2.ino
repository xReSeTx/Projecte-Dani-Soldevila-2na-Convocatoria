const int tempPin = 2;
float temperatura = 0.0;
int valorAnalogic = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  valorAnalogic = analogRead(tempPin);
  float voltage = valorAnalogic * (3.3 / 4095.0);
  temperatura = voltage * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(2000);
}
