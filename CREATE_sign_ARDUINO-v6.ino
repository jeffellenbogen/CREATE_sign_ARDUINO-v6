#include <elapsedMillis.h>

const int motorPin =  3;    // Motor Power pin
const int button1Pin = 12;  // pushbutton 1 pin
const int reedPin = 11; // reed switch on door
const int reedLEDPin = 13; // reed switch open LED indicator
const int E2ledPin = 4;  // 2nd "E" in CREATE LED Pin (green)

const int RGBRedledPin = 5;  // RGB Red pin
const int RGBBlueledPin = 6;  // RGB Blue pin
const int AledPin = 7;  // "A" in CREATE LED pin (blue)
const int RledPin = 8;  // "R" in CREATE LED pin (blue)
const int RGBGreenledPin = 9;  // RGB Green pin
const int motorSpeedHigh = 255; // speed of motor when the button is pressed
const int motorSpeedLow = 255; // speed of motor when door opens

int randomColorR, randomColorG, randomColorB;

elapsedMillis doorOpenTimer;

void setup()
{
  Serial.begin(9600);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(reedPin, INPUT);
  pinMode(reedLEDPin, OUTPUT);
  pinMode(E2ledPin, OUTPUT);
  pinMode(AledPin, OUTPUT);  
  pinMode(RledPin, OUTPUT);
  
  pinMode(motorPin, OUTPUT);
  pinMode(RGBRedledPin, OUTPUT);
  pinMode(RGBBlueledPin, OUTPUT);
  pinMode(RGBGreenledPin, OUTPUT);  
  randomColorR = random(255);
  randomColorG = random(255);
  randomColorB = random(255);  
}

void loop()
{
   while (digitalRead(reedPin) == HIGH) { // Door Reed Switch is OPEN

       if (doorOpenTimer > 0){
        analogWrite(motorPin, motorSpeedLow);
        digitalWrite(reedLEDPin, HIGH);
       }
       if (doorOpenTimer > 1000){
       digitalWrite(RledPin, HIGH);
       }
       if (doorOpenTimer > 2000){
       digitalWrite(AledPin, HIGH);
       }
       if (doorOpenTimer > 3000){
       digitalWrite(E2ledPin, HIGH);
       } 
       if (doorOpenTimer > 4000){
       analogWrite(RGBRedledPin, randomColorR); 
       analogWrite(RGBGreenledPin, randomColorG);     
       analogWrite(RGBBlueledPin, randomColorB);
       }
       if (doorOpenTimer > 5000){
       randomColorR = random(255);
       randomColorG = random(255);
       randomColorB = random(255);       
       digitalWrite(RledPin, LOW); 
       digitalWrite(AledPin, LOW);  
       digitalWrite(E2ledPin, LOW); 
       analogWrite(RGBRedledPin, 0); 
       analogWrite(RGBGreenledPin, 0);     
       analogWrite(RGBBlueledPin, 0);
       Serial.print("RED = ");
       Serial.print(randomColorR);
       Serial.print(" GREEN = ");
       Serial.print(randomColorG);
       Serial.print(" BLUE = ");
       Serial.println(randomColorB);       
       doorOpenTimer = 0;            
       }
   }
   doorOpenTimer = 0;
   analogWrite(motorPin, 0); // if Switch is CLOSED, turn off motors and LEDS
   digitalWrite(reedLEDPin, LOW);
   digitalWrite(RledPin, LOW); 
   digitalWrite(AledPin, LOW);  
   digitalWrite(E2ledPin, LOW);  
   analogWrite(RGBRedledPin, 0); 
   analogWrite(RGBGreenledPin, 0);     
   analogWrite(RGBBlueledPin, 0);     
   int button1State;  // variables to hold the pushbutton state

   button1State = digitalRead(button1Pin);

  
   if (button1State == LOW) { // Button Pressed!
    
    digitalWrite(E2ledPin, HIGH);
    digitalWrite(AledPin, HIGH);
    digitalWrite(RledPin, HIGH);     
    analogWrite(motorPin, motorSpeedHigh);

    analogWrite(RGBRedledPin, 255); 
    analogWrite(RGBGreenledPin, 99);     
    analogWrite(RGBBlueledPin, 71);
          
    delay(2000);

    analogWrite(RGBRedledPin, 127); 
    analogWrite(RGBGreenledPin, 255);     
    analogWrite(RGBBlueledPin, 0);
     
    delay(2000);
    
    analogWrite(RGBRedledPin, 154); 
    analogWrite(RGBGreenledPin, 205);     
    analogWrite(RGBBlueledPin, 50);
    
    delay(2000);

    analogWrite(RGBRedledPin, 0); 
    analogWrite(RGBGreenledPin, 255);     
    analogWrite(RGBBlueledPin, 127);
    delay(2000);

    analogWrite(RGBRedledPin, 124); 
    analogWrite(RGBGreenledPin, 252);     
    analogWrite(RGBBlueledPin, 0);
          
    delay(2000);

    analogWrite(RGBRedledPin, 210); 
    analogWrite(RGBGreenledPin, 105);     
    analogWrite(RGBBlueledPin, 30);
     
    delay(2000);
    
    analogWrite(RGBRedledPin, 218); 
    analogWrite(RGBGreenledPin, 112);     
    analogWrite(RGBBlueledPin, 214);
    
    delay(2000);

    analogWrite(RGBRedledPin, 135); 
    analogWrite(RGBGreenledPin, 206);     
    analogWrite(RGBBlueledPin, 250);
    delay(2000);

    //turn everything off
    digitalWrite(E2ledPin, LOW);
    digitalWrite(AledPin, LOW);
    digitalWrite(RledPin, LOW);    
    analogWrite(motorPin, 0);  
    analogWrite(RGBRedledPin, 0);
    analogWrite(RGBBlueledPin, 0);
    analogWrite(RGBGreenledPin, 0);          
  }
}
