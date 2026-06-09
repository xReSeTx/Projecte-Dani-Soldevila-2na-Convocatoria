void setup() {
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Hola");
  
  pinMode(25, OUTPUT);
  
}

void loop() {

  if (Serial.available()) {
    String linea = Serial.readStringUntil('\n');
    linea.trim();
    if (linea.length() > 0) {
      Serial.print("He rebut: ");
      linea.toLowerCase();
      Serial.println(linea);
      if (linea == "on"){
        if (digitalRead(25) == LOW){
          digitalWrite(25, HIGH);
          Serial.println("Encendiendo led");
        } else {
          Serial.println("Led ya encendido");
        }
      } else if (linea == "off"){
        if (digitalRead(25) == HIGH){
          digitalWrite(25, LOW);
          Serial.println("Apagando led");
        } else {
          Serial.println("Led ya apagado");
        }
      } else {
        Serial.println("Comando no reconocido");
      }
    }
  }

}
