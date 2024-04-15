const int LED1= 12; // Replace with your relay pin
const int LED2= 13;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, HIGH); // Turn on LED
  digitalWrite(LED2, HIGH);
  delay(3000); // Wait for 3 seconds
  digitalWrite(LED1, LOW); // Turn off LED
  digitalWrite(LED2, LOW);
  delay(3000); // Wait for 3 seconds
}

void loop() {
  
}
