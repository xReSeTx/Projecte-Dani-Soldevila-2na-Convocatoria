void setup() {
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("Hola");

}

void loop() {

  String linea = Serial.readStringUntil('\n');
  linea.trim();

}
