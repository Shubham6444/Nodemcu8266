


#define BLYNK_TEMPLATE_ID "TMPL3Sjb0AyeS"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "Uj3a29-1t3DkvSB-y6-A9vuepA_J2rdb"



#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "node";
char pass[] = "87654321";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  if(value == 1){
    digitalWrite(D1, HIGH);
  }else{
   digitalWrite(D1, LOW);
  }
  }


BLYNK_WRITE(V1)
{
  int value = param.asInt();
  if(value == 1){
    digitalWrite(D2, HIGH);
  }else{
   digitalWrite(D2, LOW);
  }
  }


BLYNK_WRITE(V2)
{
  int value = param.asInt();
  if(value == 1){
    digitalWrite(D3, HIGH);
  }else{
   digitalWrite(D3, LOW);
  }
  }
  
void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
    
    
    
    
 
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();

}
