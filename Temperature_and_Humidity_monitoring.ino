

#include "thingProperties.h"
#include "DHT.h"
#define DHTpin 2 // D4 on the nodemcu ESP8266
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
int val;
int pul;
int PulseSensorpin = A0; //Pulse Sensor Pin Connected at A0 Pin
int LED_3 = D0;
int LED_2 = D1;
int H = 80;

void setup() {
  pinMode(LED_3,OUTPUT); //--> Set LED_3 PIN as Output.
  pinMode(LED_2,OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(10); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
     float hm= dht.readHumidity();
    Serial.print("Humidity ");
    Serial.println(hm);
    float temp=dht.readTemperature();
      Serial.print("Temperature ");
    Serial.println(temp);
    val = analogRead(PulseSensorpin);
    pul=val/10;
    if(pul > H){ //--> If the signal is above "550"(Threshold), then "turn-on" Arduino's on-Board LED.
      digitalWrite(LED_3,HIGH);
  } else {
      digitalWrite(LED_3,LOW); //--> Else, the sigal must be below "550", so "turn-off" this LED.
  }
    if(pul < H){ //--> If the signal is above "550"(Threshold), then "turn-on" Arduino's on-Board LED.
      digitalWrite(LED_2,HIGH);
  } else {
      digitalWrite(LED_2,LOW); //--> Else, the sigal must be below "550", so "turn-off" this LED.
  }
    Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
    Serial.println(pul); // Start Printing on Pulse sensor value on LCD
    heartpulse=pul;
    humidity=hm;
    temperature=temp;
    message="Temperature = " + String (temperature)+"  Humidity = " + String(humidity)+" Heart Rate Pulse = " + String(heartpulse);
  
}


/*
  Since Temperture is READ_WRITE variable, onTempertureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTempertureChange()  {
  // Add your code here to act upon Temperture change
}

/*
  Since Humiduty is READ_WRITE variable, onHumidutyChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidutyChange()  {
  // Add your code here to act upon Humiduty change
}

/*
  Since Massage is READ_WRITE variable, onMassageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMassageChange()  {
  // Add your code here to act upon Massage change
}

/*
  Since Heartpulse is READ_WRITE variable, onHeartpulseChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHeartpulseChange()  {
  // Add your code here to act upon Heartpulse change
}


/*
  Since Humidity is READ_WRITE variable, onHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidityChange()  {
  // Add your code here to act upon Humidity change
}

/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}

/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}

void dht_sensor_getdata()
  {
    float hm= dht.readHumidity();
    Serial.print("Humidity ");
    Serial.println(hm);
    float temp=dht.readTemperature();
      Serial.print("Temperature ");
    Serial.println(temp);
    val = analogRead(PulseSensorpin);
    pul=val/10;
    if(pul > H){ //--> If the signal is above "550"(Threshold), then "turn-on" Arduino's on-Board LED.
      digitalWrite(LED_3,HIGH);
  } else {
      digitalWrite(LED_3,LOW); //--> Else, the sigal must be below "550", so "turn-off" this LED.
  }
      if(pul < H){ //--> If the signal is above "550"(Threshold), then "turn-on" Arduino's on-Board LED.
      digitalWrite(LED_2,HIGH);
  } else {
      digitalWrite(LED_2,LOW); //--> Else, the sigal must be below "550", so "turn-off" this LED.
  }
    Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
    Serial.println(pul); // Start Printing on Pulse sensor value on LCD
    heartpulse=pul;
    humidity=hm;
    temperature=temp;
    message="Temperature = " + String (temperature)+"  Humidity = " + String(humidity)+" Heart Rate Pulse = " + String(heartpulse);
  }
