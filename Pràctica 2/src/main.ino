const int tempPin = 2;
const int ldrPin  = 4;
const int ledPin  = 25;

float temperatura = 0.0;
int valorTemp     = 0;
int valorLDR      = 0;

unsigned long lastPrint = 0;
const unsigned long interval = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== Sistema de monitoritzacio CPD llest ===");
  Serial.println("Ordres disponibles: STATUS / LED_OFF");
  Serial.println("==========================================");
}

void loop() {
  unsigned long currentMillis = millis();

  valorLDR = analogRead(ldrPin);
  valorTemp = analogRead(tempPin);
  float voltage = valorTemp * (3.3 / 4095.0);
  temperatura = voltage * 100.0;

  if (temperatura > 25.0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ALERTA: Sobreescalfament CPD!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (valorLDR > 1000) {
    Serial.println("AVIS: Porta oberta o llum encesa");
  }

  if (currentMillis - lastPrint >= interval) {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" C  |  Llum: ");
    Serial.println(valorLDR);
    lastPrint = currentMillis;
  }

  if (Serial.available()) {
    String linea = Serial.readStringUntil('\n');
    linea.trim();
    linea.toLowerCase();

    if (linea == "status") {
      Serial.println("--- STATUS ---");
      Serial.print("Temperatura: ");
      Serial.print(temperatura);
      Serial.println(" C");
      Serial.print("Lluminositat: ");
      Serial.println(valorLDR);
      Serial.println("--------------");
    } else if (linea == "led_off") {
      if (digitalRead(ledPin) == HIGH) {
        digitalWrite(ledPin, LOW);
        Serial.println("LED apagat manualment");
      } else {
        Serial.println("El LED ja estava apagat");
      }
    } else {
      Serial.println("Error: ordre desconeguda.");
    }
  }
}
