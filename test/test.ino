#include <Ultrasonic.h>
#include <Servo.h>

const int ServoPin = 2;
const int UltrasonicTrigPin = 3;
const int UltrasonicEchoPin = 4;

const int ENA = 11;
const int IN1 = 12;
const int IN2 = 13;
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10;

Servo servo_controller = Servo();
Ultrasonic ultrasonic_controller = Ultrasonic(UltrasonicTrigPin, UltrasonicEchoPin);


void setup() {
  // put your setup code here, to run once:
  servo_controller.attach(2);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 250);
  analogWrite(ENB, 250);

  Serial.begin(9600);
}

void loop() {
  int x = Serial.read();

  // forward
  if (x == '1'){
    servo_controller.write(90);
    delay(300);
    int d = ultrasonic_controller.read();
    if (d > 20){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
  }

  // reverse 
  if (x == '2'){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(500);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // stop
  if (x == '3'){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // turn left
  if (x == '4'){
    servo_controller.write(135);
    delay(300);
    int d = ultrasonic_controller.read();
    if (d > 20){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    servo_controller.write(90);
  }

  // turn right
  if (x == '5'){
    servo_controller.write(45);
    delay(300);
    int d = ultrasonic_controller.read();
    if (d >20){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    servo_controller.write(90);
  }
  
}
