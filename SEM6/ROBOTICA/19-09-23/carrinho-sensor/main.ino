#define FORWARD 0
#define REVERSE 1

#define MOTOR_A 0
#define MOTOR_B 1

#define PWMA 5
#define PWMB 6
#define DIRA 7
#define DIRB 8

void setupMotor(void);
void driveMotor(byte, byte, byte);
void stopMotor(byte);

void setup() {
  Serial.begin(115200);

  setupMotor();

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  delay(10);
  String message = String(analogRead(A0)) + ", " + String(analogRead(A1));
  Serial.println(message);
}

void setupMotor(void) {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

void driveMotor(byte motor, byte direction, byte speed) {
  switch(motor) {
    case 0:
      digitalWrite(DIRA, direction);
      analogWrite(PWMA, speed);
      break;
    case 1:
      digitalWrite(DIRB, direction);
      analogWrite(PWMB, speed);
      break;
    default:
      Serial.println("ERROR: Undefined motor value.");
  }
}

void stopMotor(byte motor) {
  driveMotor(motor, 0, 0);
}