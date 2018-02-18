#include <dht.h>

#define dht_apin A2 // Analog Pin sensor is connected to
dht DHT;

const int analogInPinX = A0;
const int analogInPinY = A1;
const int DIGIOUT =  7;

long sensorValueX = 0;
long sensorValueY = 0;
void setup() {
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(DIGIOUT, OUTPUT); 
 digitalWrite(DIGIOUT,HIGH); 
}

void loop() {
  
      DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.print("C  ");
  
  // read the analog in value:
  sensorValueX = analogRead(analogInPinX);  
  sensorValueY = analogRead(analogInPinY);  
  sensorValueX = sensorValueX*100/1023;
  sensorValueY = sensorValueY*100/1023;
  
  Serial.print("X = " );                       
  Serial.print(sensorValueX);
  Serial.print("%" );  
  Serial.print("\t Y = ");      
  Serial.print(sensorValueY);   
  Serial.println("%" ); 
  delay(1000);                     
}
