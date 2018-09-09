//This code will only work if launching motors are connected to pin 6 and 5
//Servo connected to pin 11
//Open Serial to issue command

#include <Servo.h>

//DC motor pin
int motorA = 6;
int motorB = 5;

//Servo declaration
Servo myservo;

//Feature Creep...:D
String userInput = "";
int lSpeed = 0;
int lTime = 5000;
int lAngle = 0;
double powerPercent = 0;

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  
  Serial.begin(9600);

  myservo.attach(11);
  
  Serial.println("Missile Launcher Control Interface v1 - Tristan Technologies");
}

void loop() {
  while (1) {
    Serial.println("\nEnter Configuration Parameters:\nLaunch\nSpeed\nAngle\n");
    while (userInput == "")
    {
      userInput = Serial.readString();

      if (userInput == "launch")
      {
        launch();
      }
      else if (userInput == "angle")
      {
        changeAngle();
      }
      else if (userInput == "speed")
      {
        changeSpeed();
      }
    }
    userInput = "";
  }
}

void launch(void)
{
  Serial.println("launch start");

  //rev up motor
  analogWrite(motorA, lSpeed);
  analogWrite(motorB, lSpeed);

  delay(lTime);

  analogWrite(motorA, 0);
  analogWrite(motorB, 0);

  Serial.println("launch end");
}

void changeSpeed(void)
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
      Serial.print("Speed changed to: ");
      Serial.println(lSpeed);
    }
  }
}

void changeAngle(void)
{
  userInput = Serial.readString();
  Serial.println("Specify Angle (-90 to 89)");

  while (userInput == "")
  {
    userInput = Serial.readString();

    if (userInput != "")
    {
      //set Anglet to userInput
      lAngle = userInput.toInt();
      lAngle += 90;
      myservo.write(lAngle);
      Serial.print("Set angle to: ");
      Serial.println(lAngle);
    }
  }
}

