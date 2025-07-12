#include <Arduino.h>

// Right-Side Wheels

int motor1pin1_right_forward = 7;
int motor1pin2_right_backward = 8;

// Left-Side Wheels

int motor2pin1_left_forward = 9;
int motor2pin2_left_backward = 10;

// Enable-Pins

//int enA = 6;
//int enB = 5;

// Motor(Wheel) Speed
//int speedLeft = 200;
//int speedRight = 200;

void turnLeft() {
    // Right-Wheels-Moving-Forward
    digitalWrite(motor1pin1_right_forward, LOW);
    digitalWrite(motor1pin2_right_backward, HIGH);
    Serial.println("Turning Left...");
}

void turnRight() {
    // Left-Wheels-Moving-Forward
    digitalWrite(motor2pin1_left_forward, HIGH);
    digitalWrite(motor2pin2_left_backward, LOW);
    Serial.println("Turning Right...");
}

void movingForward() {
  digitalWrite(motor1pin1_right_forward, LOW);
  digitalWrite(motor1pin2_right_backward, HIGH);
  //analogWrite(enA, speedRight);
  delay(120);
  digitalWrite(motor1pin1_right_forward, LOW);
  digitalWrite(motor1pin2_right_backward, LOW);
  delay(2);
  digitalWrite(motor2pin1_left_forward, HIGH);
  digitalWrite(motor2pin2_left_backward, LOW);
  delay(120);
  digitalWrite(motor2pin1_left_forward, LOW);
  digitalWrite(motor2pin2_left_backward, LOW);
  delay(2);
  //analogWrite(enB, speedLeft);
  Serial.println("Moving Forward...");
}

void stop() {
    // Stopping
    digitalWrite(motor1pin1_right_forward, LOW);
    digitalWrite(motor1pin2_right_backward, LOW);
    digitalWrite(motor2pin1_left_forward, LOW);
    digitalWrite(motor2pin2_left_backward, LOW);
    Serial.println("Stopping...");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1_right_forward, OUTPUT);
  pinMode(motor1pin2_right_backward, OUTPUT);
  pinMode(motor2pin1_left_forward, OUTPUT);
  pinMode(motor2pin2_left_backward, OUTPUT);
  //pinMode(enA, OUTPUT);
  //pinMode(enB, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Right-Wheels-Moving-Forward
  //digitalWrite(motor1pin1_right_forward, LOW);
  //digitalWrite(motor1pin2_right_backward, HIGH);
  // Left-Wheels-Moving-Forward
  //digitalWrite(motor2pin1_left_forward, HIGH);
  //digitalWrite(motor2pin2_left_backward, LOW);
  //Serial.println("Moving Forward...");

  //Moving-Forward
  movingForward();
  delay(3000);

  // Stopping
  stop();
  delay(3000);

  // Turning-Left
  turnLeft();
  delay(3000);

  // Both-Wheels-Stop
  //digitalWrite(motor1pin1_right_forward, LOW);
  //digitalWrite(motor1pin2_right_backward, LOW);
  //digitalWrite(motor2pin1_left_forward, LOW);
  //digitalWrite(motor2pin2_left_backward, LOW);
  //Serial.println("Temporary Stopping...");

  // Stopping
  stop();
  delay(3000);

  // Right-Wheels-Moving-Backward
  //digitalWrite(motor1pin1_right_forward, HIGH);
  //digitalWrite(motor1pin2_right_backward, LOW);
  // Left-Wheels-Moving-Backward
  //digitalWrite(motor2pin1_left_forward, LOW);
  //digitalWrite(motor2pin2_left_backward, HIGH);
  //Serial.println("Moving Backward...");

  // Turning-Right
  turnRight();
  delay(3000);

  //digitalWrite(motor1pin1_right_forward, LOW);
  //digitalWrite(motor1pin2_right_backward, LOW);
  //digitalWrite(motor2pin1_left_forward, LOW);
  //digitalWrite(motor2pin2_left_backward, LOW);
  //Serial.println("Temporary Stopping...");

  // Stopping
  stop();
  delay(3000);
}




