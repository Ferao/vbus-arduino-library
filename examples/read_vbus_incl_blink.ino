#include "VBUSDecoder.h"

VBUSDecoder vb;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // LED_BUITIN maybe needs to be changed to a Pin number
  Serial.begin(9600);
  vb.initialise();
  
}

void loop()
{
  //added blink
  digitalWrite(LED_BUILTIN, HIGH);
  
  vb.readSensor();

  Serial.println("");
  Serial.println("*** Fresh Read ***");
  Serial.print("Collector Temp: ");
  Serial.println(vb.getS1Temp());
  Serial.print("Top Tank Temp: ");
  Serial.println(vb.getS3Temp());
  Serial.print("Bottom Tank Temp: ");
  Serial.println(vb.getS2Temp());
  Serial.print("Water Pump Status: ");
  Serial.println(vb.getP1Status());
  Serial.print("Water Pump Speed: ");
  Serial.println(vb.getP1Speed());
  Serial.print("Pump Hours Operation: ");
  Serial.println(vb.getP1OperatingHours());
  Serial.print("System Alert Status: ");
  Serial.println(vb.getAlertStatus());
  Serial.print("Scheme: ");
  Serial.println(vb.getScheme());
  Serial.print("System Time: ");
  Serial.println(vb.getSystemTime());
  Serial.println("*** End Read ***");
  // added blink   
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(300);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(20000);
}
