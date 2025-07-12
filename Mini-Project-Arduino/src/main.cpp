#include <Arduino.h>
// IR sensor pins
const int leftIR = 12;
const int rightIR = 11;

// Motor driver pins
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 10;

void setup() {
  // IR sensor inputs
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  // Motor outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void moveForward() {
  //digitalWrite(IN1, HIGH);
  //digitalWrite(IN2, LOW);
  //digitalWrite(IN3, HIGH);
  //digitalWrite(IN4, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  //digitalWrite(IN1, LOW);
  //digitalWrite(IN2, HIGH);
  //digitalWrite(IN3, HIGH);
  //digitalWrite(IN4, LOW);

  //Right-Motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  //digitalWrite(IN1, HIGH);
  //digitalWrite(IN2, LOW);
  //digitalWrite(IN3, LOW);
  //digitalWrite(IN4, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  int leftSensor = digitalRead(leftIR);
  int rightSensor = digitalRead(rightIR);

  // Logic: Black line = 0, White = 1
  if (leftSensor == 1 && rightSensor == 1) {
    // Both sensors on black line - move forward
    //moveForward();
    stopMotors();
  }
  else if (leftSensor == 1 && rightSensor == 0) {
    // Right sensor on white - turn left
    turnRight();
  }
  else if (leftSensor == 0 && rightSensor == 1) {
    // Left sensor on white - turn right
    turnLeft();
  }
  else {
    // Both on white - stop or move forward (depends on design)
    //stopMotors();
    moveForward();
  }
}






