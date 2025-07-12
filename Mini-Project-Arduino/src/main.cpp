#include <Arduino.h>
//#include <Servo.h>

//Servo myservo;
int angle = 140;

// IR sensor pins
//const int leftIR = 12;
//const int rightIR = 11;

// Ultrasonic sensor pins
int trigPin = 11;
int echoPin = 12;


// Motor driver pins
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 10;

void setup() {
  // IR sensor inputs
  //pinMode(leftIR, INPUT);
  //pinMode(rightIR, INPUT);

  //myservo.attach(3);
  //myservo.write(angle);
  //delay(500);

  // Ultrasonic values
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  // Motor outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

long gettingDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Speed of sound: 343 m/s
  return distance;
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

/*
  for(angle=180; angle>=80; angle-=1){
    long distance = gettingDistance();
    if(distance > 20)
    {
      moveForward();
    }
    else
    {
      stopMotors();
    }
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    myservo.write(angle);
    delay(100);
  }
  for(angle=80; angle<=180; angle+=1){
    long distance = gettingDistance();
    if(distance > 20)
    {
      moveForward();
    }
    else
    {
      stopMotors();
    }
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    myservo.write(angle);
    delay(100);
  }
  */

  long distance = gettingDistance();
  if(distance > 20)
    {
      moveForward();
      Serial.println("Moving forward...");
    }
    else
    {
      stopMotors();
      Serial.println("Stopped...");
    }


  /*int leftSensor = digitalRead(leftIR);
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
  }*/
}






