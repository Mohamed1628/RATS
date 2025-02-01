// Change this pin to match the ESP32's analog input pin
const int potPin = 4;  // Example pin, change to match your setup

void setup() {
  // Serial Monitor
  Serial.begin(115200); 
  delay(1000); 

  Serial.println("ESP32 Potentiometer Test - Reading Values");
}

void loop() {
  // Read and print the potentiometer value
  int potValue = analogRead(potPin); 
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  delay(16);
}
