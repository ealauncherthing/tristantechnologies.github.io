#include <Servo.h>

const int dly = 300;

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
double powerPercent;
int currentAngle, prevAngle;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  Serial.begin(9600);
  Serial.println("Kurznetsov Surface To A

  myservo.attach(11);
ir Missile Launcher Control Interface v1 - Tristan Technologies");
}

void loop() {

  Serial.println("\nEnter Configuration Parameters:\nLaunch\nSpeed\nAngle\n");
  while (userInput == "")
  {
    userInput = Serial.readString();
    Serial.println(userInput);
    if (userInput == "launch")
    {

      Serial.println ("Launch Parameters:\n");
      Serial.println ("Azimuthal Angle: ");
      Serial.println (lAngle);
      Serial.println ("\nDrive Power: ");
      Serial.println (powerPercent);


      // Serial.println ("\nConfirm Launch? <y/n>");
      //userInput = Serial.readString();

      Serial.println("Launch Committed, executing...");

      analogWrite(motorA, lSpeed);
      analogWrite(motorB, lSpeed);
      delay(lTime);
      analogWrite(motorA, 0);
      analogWrite(motorB, 0);
      Serial.println("launch end");

    }
    else if (userInput == "angle")
    {
      userInput = Serial.readString();
      Serial.println("Specify Angle (-90 to 89)");
      while (userInput == "")
      {
        userInput = Serial.readString();
        if (userInput != "")
        {
          lAngle = userInput.toInt();
          //set Servo to
          if (lAngle < -90 || lAngle > 89)
          {
            Serial.println("Error - Wrong Angle");
          }
          else
          {
            lAngle += 90;

            currentAngle = prevAngle; //Set Current angle = to previous stored angle

            if (lAngle > prevAngle) {

              while (currentAngle < lAngle)
                currentAngle = currentAngle + 5;
              myservo.write(currentAngle);
              delay(dly);
              lAngle = prevAngle;
            }
          else if (lAngle < prevAngle) {

            while (currentAngle > lAngle) {
              currentAngle = currentAngle - 5;
              myservo.write(currentAngle);
              delay(dly);
              lAngle = prevAngle;
            }
          }
        }
      }
    }
  }
  else if (userInput == "speed")
  {
    userInput = Serial.readString();
    Serial.println("Specify Speed In Percentage ");
    while (userInput == "")
    {
      userInput = Serial.readString();
      if (userInput != "")
      {
        //set Speed to userInput
        powerPercent = userInput.toInt();

        lSpeed = (powerPercent / 100) * 255;

        analogWrite(motorA, lSpeed);
        analogWrite(motorB, lSpeed);
        Serial.print("Set speed to ");
        Serial.println(powerPercent);
        Serial.print("% and ");
        Serial.print(lSpeed);
        Serial.println(" PWM\n");
        delay(1000);
        analogWrite(motorA, 0);
        analogWrite(motorB, 0);
      }
    }
  }
}
userInput = "";
}
