//c++ code
//gm to kg converter 

void setup()
{
  Serial.begin(9600);
  
  float gm= 1500;
  float kg;
  kg = gm/1000;
  
  Serial.println(kg);
}

void loop()
{
  
}