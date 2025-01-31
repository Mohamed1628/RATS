// Analog Pin for FSR sensor reading
const int fsrPin = 4; 

void setup() {
  // Set baud rate for ESP32
  Serial.begin(115200); 
  delay(1000); 

  Serial.println("Reading FSR Values");
}

void loop() {
  // Read and print the FSR value
  int fsrValue = analogRead(fsrPin); 
  Serial.print("FSR Sensor Value: ");
  Serial.println(fsrValue);

  // Delay
  delay(16);
}
