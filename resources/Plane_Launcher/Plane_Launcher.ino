#include <Servo.h>

//DC motor pin
int motorA = 6;
int motorB = 5;

//button input pin
int button1 = 8;
int button2 = 9;
int button3 = 10;

//button input state
int stateA;
int stateB;
int stateC;

//Servo declaration
Servo myservo;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  myservo.attach(11);
  myservo.write(90);

  Serial.begin(9600);
  Serial.println("PaperPlane Launcher v1 - Tristan Technologies");
}

void loop() {
  stateA = digitalRead(button1);
  stateB = digitalRead(button2);
  stateC = digitalRead(button3);

//For debug

  Serial.print(stateA);
  Serial.print(" ");
  Serial.print(stateB);
  Serial.print(" ");
  Serial.println(stateC);


  if(stateA)
  {
    //button1 pressed action

    //Servo movement
    myservo.write(0);
    delay(500);

    //Rev up motor(might want to change speed)
    analogWrite(motorA,255);
    analogWrite(motorB,255);

    //Waiting for launch
    Serial.write("Launching...");
    delay(5000);
    Serial.write("launch end");
  }
  else if(stateB)
  {
    //button2 pressed action
    
    //Servo movement
    myservo.write(90);
    delay(500);

    //Rev up motor(might want to change speed)
    analogWrite(motorA,255);
    analogWrite(motorB,255);

    //Waiting for launch
    Serial.write("Launching...");
    delay(5000);
    Serial.write("launch end");
  }
  else if(stateC)
  {
    //button3 pressed action
    
    //Servo movement
    myservo.write(179);
    delay(1000);

    //Rev up motor(might want to change speed)
    analogWrite(motorA,255);
    analogWrite(motorB,255);

    //Waiting for launch
    Serial.write("Launching...");
    delay(5000);
    Serial.write("launch end");
  }
  else
  {
    analogWrite(motorB,0);
    analogWrite(motorA,0);
  }

  
}
