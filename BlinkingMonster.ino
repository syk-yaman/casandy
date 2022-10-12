#include <Servo.h>

Servo myservo; 

//PIR variables
int sensor = 2; //PID is connected to pin 2          
int PIRstate = LOW; //Detection state 
            
//Servo variables
int servoPos = 0; //Angle position

//Main logic variables
int personDetected = 0;
int personIsGone = 0;
int candyIsShown = 0;

void setup() {
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
  myservo.attach(9); //Servo is connected to pin 9
}

void loop(){
  //Read PIR state
  int val = digitalRead(sensor);   
  if (val == HIGH) {          
    if (PIRstate == LOW) {
      Serial.println("1"); 
      PIRstate = HIGH;  
      personDetected = 1;
      Serial.println("personDetected"); 
      personIsGone = 0;
    }
  } 
  else {
      if (PIRstate == HIGH){
        Serial.println("0");
        PIRstate = LOW;  
        personDetected = 0;
        personIsGone = 1;
        Serial.println("personIsGone");
    }
  }

if(personDetected == 1){
  moveServoToHideCandy();
  delay(5000); 
  personDetected = 0;
  personIsGone = 0;
}

if(personIsGone == 1){
  moveServoToShowCandy();
  delay(100); 

  personDetected = 0;
  personIsGone = 0;
}
}

void moveServoToShowCandy(){
  for (servoPos = 0; servoPos <= 140; servoPos += 1)
      {
          myservo.write(servoPos);             
          delay(1);                     
      }
    Serial.println("moveServoToShowCandy");
    candyIsShown = 1;
 
}

void moveServoToHideCandy(){
   for (servoPos = 140; servoPos >= 0; servoPos -= 1) 
       {
          myservo.write(servoPos);           
          delay(1);                  
       }
    Serial.println("moveServoToHideCandy");
    candyIsShown = 0;
  
}
