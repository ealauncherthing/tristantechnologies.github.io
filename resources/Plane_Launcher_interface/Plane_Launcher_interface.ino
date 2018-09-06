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

//Feature Creep...:D
String userInput = "";
int lSpeed = 0;
int lTime = 5000;
int lAngle = 0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  Serial.begin(9600);
  Serial.println("Paper_Plane Launcher v1 - Tristan Technologies");
}

void loop() {

  Serial.println("\nCommand:\nlaunch\nspeed\nangle\n");
  while (userInput == "")
  {
    userInput = Serial.readString();
    //Serial.println(userInput);
    if (userInput == "launch")
    {
      Serial.println("launching...");
      //Rev up engine
      analogWrite(motorA,lSpeed);
      analogWrite(motorB,lSpeed);
      delay(lTime);
      Serial.println("launch end");
    }
    else if (userInput == "angle")
    {
      userInput = Serial.readString();
      Serial.println("Specify Angle");
      while (userInput == "")
      {
        userInput = Serial.readString();
        if (userInput != "")
        {
          //set Servo to
        
          delay(500);
          Serial.println(userInput.toInt());
        }
      }
    }
    else if (userInput == "speed")
    {
      userInput = Serial.readString();
      Serial.println("Specify Speed");
      while (userInput == "")
      {
        userInput = Serial.readString();
        if (userInput != "")
        {
          //set Speed to userInput
          lSpeed = userInput.toInt();

          analogWrite(motorA, lSpeed);
          analogWrite(motorB, lSpeed);
          delay(500);
          Serial.print("Set speed to ");
          Serial.println(lSpeed);

          analogWrite(motorA, 0);
          analogWrite(motorB, 0);
        }
      }
    }
  }
  userInput = "";
}
