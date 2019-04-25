void setup()
{
  Serial.begin(115200);
}
void loop()
{
  if(Serial.available()>0){
  byte a = Serial.read();
  //char c = a;
  Serial.println(a);
  
  }
  else{
    Serial.println("failed");
    }
//  delay(1000);
}
