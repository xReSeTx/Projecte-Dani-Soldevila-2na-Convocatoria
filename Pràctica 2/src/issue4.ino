const int tempPin = 2;
const int ldrPin = 4;
const int ledPin = 25;

float temperatura = 0.0;
int valorTemp = 0;
int valorLDR = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
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

  if (Serial.available()) {
    String linea = Serial.readStringUntil('\n');
    linea.trim();
    linea.toLowerCase();
    if (linea == "status"){
      Serial.print("Temperatura: ");
      Serial.print(temperatura);
      Serial.println(" ºC");
      Serial.print("Lluminositat: ");
      Serial.println(valorLDR);
    } else if (linea == "off" and digitalRead(25) == HIGH) {
      digitalWrite(ledPin, LOW);
      Serial.println("Led apagat manualment");
    } else if (linea == "off" and digitalRead(25) == LOW){
      
    } else {
      Serial.println("Error: ordre desconeguda.");
    }
  }
  delay(2000);
  
}
