#include <Sim800L.h>
#include <SoftwareSerial.h>

#define RX  10
#define TX  11

Sim800L GSM(RX, TX);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  GSM.begin(4800);
}

void loop() 
{
  float pulse = analogRead(A0);
  Serial.println(pulse);
  if (pulse < 40)
  {
    GSM.sendSms("+989386045537", (GSM.getLongitude() + ", " + GSM.getLatitude()).c_str());
    Serial.println("SMS Sent!");
  }
  delay(1000);
}
