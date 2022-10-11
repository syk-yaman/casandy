#include <Servo.h>

Servo myservo; 

//PIR logic
int sensor = 2; //Seson pin          
int state = LOW; //Detection state 
            

//Servo logic
int servoPos = 0; //Angle position

void setup() {
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
  myservo.attach(9); 
}

void loop(){
  int val = digitalRead(sensor);   
  if (val == HIGH) {          
    if (state == LOW) {
      Serial.println("1"); 
      state = HIGH;

      for (servoPos = 0; servoPos <= 180; servoPos += 1)
      {
        myservo.write(servoPos);             
        delay(1);                     
      }
      
    }
  } 
  else {
      if (state == HIGH){
        Serial.println("0");
        state = LOW; 

       for (servoPos = 180; servoPos >= 0; servoPos -= 1) 
       {
        myservo.write(servoPos);           
        delay(1);                  
       }
    }
  }
}
