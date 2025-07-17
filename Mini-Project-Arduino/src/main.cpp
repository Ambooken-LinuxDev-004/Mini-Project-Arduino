#include <Arduino.h>
#include <Servo.h>

// Motor Driver Pins
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define ENA 6   // PWM
#define ENB 5  // PWM

// Ultrasonic Sensor Pins
//#define TRIG 11
//#define ECHO 12

// IR sensor pins
const int leftIR = 4;
const int rightIR = 2;

// Servo Pin
//#define SERVO_PIN 3
//Servo scanServo;

int motorSpeedl = 71; // Speed range: 0–255
int motorSpeedr = 71;


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //pinMode(TRIG, OUTPUT);
  //pinMode(ECHO, INPUT);

  //scanServo.attach(SERVO_PIN);
  //scanServo.write(120); // Center position

  // IR sensor inputs
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  Serial.begin(9600);
}

/*
int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  long distance = duration * 0.034 / 2; // in cm
  return distance;
}

void scanForBestDirection(long &leftDist, long &rightDist) {
  scanServo.write(80);  // Look left
  delay(1000);
  leftDist = getDistance();
  Serial.print("Left Distance: ");
  Serial.println(leftDist);

  scanServo.write(160);   // Look right
  delay(1000);
  rightDist = getDistance();
  Serial.print("Right Distance: ");
  Serial.println(rightDist);

  scanServo.write(120);   // Reset to center
}*/

void forward() {
  Serial.println("Moving Forward");
  analogWrite(ENA, motorSpeedl);
  analogWrite(ENB, motorSpeedr);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

/*void back() {
  Serial.println("Reversing");
  analogWrite(ENA, motorSpeedl);
  analogWrite(ENB, motorSpeedr);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}*/

void turnRight() {
  Serial.println("Turning Right");
  analogWrite(ENA, motorSpeedl);
  analogWrite(ENB, motorSpeedr);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  Serial.println("Turning Left");
  analogWrite(ENA, motorSpeedl);
  analogWrite(ENB, motorSpeedr);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stop() {
  Serial.println("Stopping");
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
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
    forward();
    //stopMotors();
    delay(200);
  }
  else if (leftSensor == 1 && rightSensor == 0) {
    // Right sensor on white - turn left
    turnLeft();
    delay(200);
  }
  else if (leftSensor == 0 && rightSensor == 1) {
    // Left sensor on white - turn right
    turnRight();
    delay(200);
  }
  else {
    // Both on white - stop or move forward (depends on design)
    stop();
    delay(1000);
    //moveForward();
  }


  
  /*
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 40 || distance == 0) {
    forward();
  } else {
    stop();
    delay(200);
    // back();
    delay(50);

    // Scan left and right, then decide
    long leftDist, rightDist;
    scanForBestDirection(leftDist, rightDist);

    if (rightDist > leftDist) {
      turnLeft();
    } else {
      turnRight();
    }
    delay(250);
  }*/
}








