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

//Feature creep
int launchCode = 0;
int lAngle = 0;
int lSpeed = 0;

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
    lAngle = 0;
    lSpeed = 255;
    launchCode = 1;
  }
  else if(stateB)
  {
    //button2 pressed action
    lAngle = 90;
    lSpeed = 255;
    launchCode = 1;
  }
  else if(stateC)
  {
    //button3 pressed action
    lAngle = 179;
    lSpeed = 255;
    launchCode = 1;
  }
  else
  {
    lAngle = 0;
    lSpeed = 0;
    launchCode = 0;
  }

  if(launchCode == 1)
  {
    myservo.write(lAngle);
    delay(500);

    //Rev up motor(might want to change speed)
    analogWrite(motorA,lSpeed);
    analogWrite(motorB,lSpeed);

    //Waiting for launch
    Serial.write("Launching...");
    delay(5000);
    Serial.write("launch end");
    launchCode = 0;
  }

  
}
