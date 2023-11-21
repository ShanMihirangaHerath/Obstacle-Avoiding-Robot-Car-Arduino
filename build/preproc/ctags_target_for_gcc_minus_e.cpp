# 1 "C:\\Users\\Solo Coder\\Desktop\\test\\test.ino"
# 2 "C:\\Users\\Solo Coder\\Desktop\\test\\test.ino" 2
# 3 "C:\\Users\\Solo Coder\\Desktop\\test\\test.ino" 2

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

  pinMode(ENA, 0x1);
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);
  pinMode(IN3, 0x1);
  pinMode(IN4, 0x1);
  pinMode(ENB, 0x1);

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
      digitalWrite(IN1, 0x1);
      digitalWrite(IN2, 0x0);
      digitalWrite(IN3, 0x1);
      digitalWrite(IN4, 0x0);
    }
  }

  // reverse 
  if (x == '2'){
    digitalWrite(IN1, 0x0);
    digitalWrite(IN2, 0x1);
    digitalWrite(IN3, 0x0);
    digitalWrite(IN4, 0x1);
    delay(500);
    digitalWrite(IN1, 0x0);
    digitalWrite(IN2, 0x0);
    digitalWrite(IN3, 0x0);
    digitalWrite(IN4, 0x0);
  }

  // stop
  if (x == '3'){
    digitalWrite(IN1, 0x0);
    digitalWrite(IN2, 0x0);
    digitalWrite(IN3, 0x0);
    digitalWrite(IN4, 0x0);
  }

  // turn left
  if (x == '4'){
    servo_controller.write(135);
    delay(300);
    int d = ultrasonic_controller.read();
    if (d > 20){
      digitalWrite(IN1,0x0);
      digitalWrite(IN2,0x1);
      digitalWrite(IN3, 0x1);
      digitalWrite(IN4, 0x0);
      delay(500);
      digitalWrite(IN1,0x0);
      digitalWrite(IN2,0x0);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x0);
    }
    servo_controller.write(90);
  }

  // turn right
  if (x == '5'){
    servo_controller.write(45);
    delay(300);
    int d = ultrasonic_controller.read();
    if (d >20){
      digitalWrite(IN1,0x1);
      digitalWrite(IN2,0x0);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x1);
      delay(500);
      digitalWrite(IN1,0x0);
      digitalWrite(IN2,0x0);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x0);
    }
    servo_controller.write(90);
  }



}
