#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define trigPin D0
#define echoPin D1
#define led D2

char auth[] = "NV8no5EA3F0bgzZzlpD49_gJffENoRGF";                      //authentication key
char ssid[] = "No internet";                                          // Name of your network (HotSpot or Router name)
char pass[] = "ranjanyadav";                                         // Corresponding Password

void setup() 
         {
    Serial.begin(9600);
     Blynk.begin(auth, ssid, pass);
       pinMode(trigPin, OUTPUT); 
         pinMode(echoPin, INPUT); 
           pinMode(led, OUTPUT);
            Blynk.notify("LET'S START THE JOURNEY");
          }


long duration;
long distance;
int pointindex;
long lon;
long lat;
void loop() 
    {
            digitalWrite(trigPin, LOW);
              delayMicroseconds(2); 
           
                        digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
                          delayMicroseconds(10);
                            digitalWrite(trigPin, LOW);
                               duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microsec
                                 distance= duration*0.034/2;// Calculating the distance


                if( distance<=50&& distance>=30)
                { Blynk.virtualWrite(V0,255);
                }
                else
                {
                  Blynk.virtualWrite(V0,0);
                }

                 if( distance<30&& distance>=10)
                { Blynk.virtualWrite(V1,255);
                }
                else
                {
                  Blynk.virtualWrite(V1,0);
                }

                
                 if( distance<10&& distance>=0)
                { Blynk.virtualWrite(V2,255);
                 Blynk.notify("OBSTACLE IS VERY NEAR, PLEASE PAY ATTENTION ");
                }
                else
                {
                  Blynk.virtualWrite(V2,0);
                }

            Blynk.virtualWrite(V4,distance);
            Blynk.virtualWrite(V3,distance);
            delay(20);
            Blynk.run();
            Blynk.virtualWrite(V5,pointindex,lat,lon);
           
     }

