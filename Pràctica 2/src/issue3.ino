const int tempPin = 2;
const int ldrPin = 4;
const int ledPin = 25;

float temperatura = 0.0;
int valorTemp = 0;
int valorLDR = 0;

unsigned long lastPrint = 0;
const unsigned long interval = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  valorTemp = analogRead(tempPin);
  float voltage = valorTemp * (3.3 / 4095.0); 
  temperatura = voltage * 100.0;

  valorLDR = analogRead(ldrPin);

  if (temperatura > 15.0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ALERTA: Sobreescalfament CPD!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (valorLDR > 1000) { 
    Serial.println("AVÍS: Porta oberta o llum encesa");
  }

  if (currentMillis - lastPrint >= interval) {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C, Llum: ");
    Serial.println(valorLDR);
    lastPrint = currentMillis;
  }
  delay(2000);
}
