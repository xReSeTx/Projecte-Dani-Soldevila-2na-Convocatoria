const int ldrPin = 4;
int valorLDR = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  valorLDR = analogRead(ldrPin);
  Serial.println(valorLDR);
  delay(2000);
}
