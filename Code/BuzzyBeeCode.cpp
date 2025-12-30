#include <Wire.h>
#include "RTClib.h"


const int swtPinVib = A2;
const int swtPinLight = A1;
const int vibPin = 4;
bool vibOn = false;


// for the lights
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;


RTC_DS3231 rtc;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(swtPinVib,INPUT);
  pinMode(swtPinLight,INPUT);
  pinMode(vibPin, OUTPUT);
  
 
  // //Setup the clock
  // if(!rtc.begin()){
  //   Serial.println("Couldn't find RTC");
  //   while(1);
  // }
  // if(rtc.lostPower()){
  //   Serial.println("RTC lost power, setting time!");
  //   //Set time to compile time
  //   rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  // }
  //Set up RGB led
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


}
// void breathingPattern(){
  
// }
// void checkTime(){
//   DateTime now = rtc.now();
//   int curHour = now.hour();
//   int curMin = now.minute();


//   //For testing
//   Serial.print("Current time: ");
//   Serial.print(curHour);
//   Serial.print(":");
//   Serial.println(curMin);
// }
void breathing()
{ 
  Serial.println("Inhale");
  digitalWrite(vibPin, HIGH);
  
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(4000);

  Serial.println("Hold");
  digitalWrite(vibPin,LOW);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(7000);

  
  Serial.println("Exhale");
  digitalWrite(vibPin,HIGH);

  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(8000);
  
  
  
  Serial.println("Hold");
  digitalWrite(vibPin,LOW);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(1000);

}

void loop() {
  breathing();
}
