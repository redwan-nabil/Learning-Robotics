int gas_sensor=A0, flame_sensor=7, buzzer=11;

void setup() {
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT);
 pinMode(flame_sensor, INPUT);
 
}

void loop() {
  if(digitalRead(flame_sensor)){
    Serial.print("Fire Detected");
    digitalWrite(buzzer, HIGH);

  }
  else{
    Serial.print("No Fire Detected");
    digitalWrite(buzzer, LOW);
  }
  if(analogRead(A0)>200){
    Serial.print(" Smoke Detected");
    digitalWrite(buzzer, HIGH);
  }
  else{
    Serial.print(" Smoke not Detected");
    digitalWrite(buzzer, LOW);
  }
  Serial.println(" ");
}
