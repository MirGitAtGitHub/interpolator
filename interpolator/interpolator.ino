#include <Servo.h>

Servo interPolateServo;
//Initialize the max amount of steps
float stepList[250];
//Here you will set the steps to take
int steps = 249;
//Here you will set the start and end points
int startPoint = 0;
int endPoint = 180;
void setup() {
  interPolateServo.attach(3);
  interPolateServo.write(startPoint);
  delay(1000);
  /*Calling the Interpolate function with the parameters being a) start point b) end point and c) the amount of steps fetched
  from the steps variable*/
  Interpolate(startPoint,endPoint,steps);
  //Begin interpolation result printing to serial
  Serial.begin(9600);
  //Run through the steps and print them to serial
  for (int i = 0; i < steps + 1; i++) {
    Serial.println(stepList[i]);
    interPolateServo.write(stepList[i]);
  }
}
void loop() {}
//Create the Interpolate function
void Interpolate(float startPoint,float endPoint,int steps) {
  //This variable will count down as long as there are steps to go through
  int stepCounter = steps;
  //This variable gives each step an unique index to use
  int stepIndex = 0;
  //Set the start point as the first step taken
  float currentStep = startPoint;
  stepList[stepIndex] = currentStep;
  //Calculate the distance between the start and end point
  float distance = endPoint - startPoint;
  //Repeat the following for all the given steps
  while (stepCounter > 0) {
    stepIndex += 1;
    //Calculate the individual step
    currentStep += distance / steps;
    //Set the step to the step list
    stepList[stepIndex] = currentStep;
    //Step done, decrease by one loop, starts over
    stepCounter -= 1;
  }
}
