#define FORWARD 0
#define REVERSE 1

#define MOTOR_A 0
#define MOTOR_B 1

#define PWM_A 5
#define PWM_B 6
#define DIR_A 7
#define DIR_B 8

#define SENSOR_LEFT A0
#define SENSOR_RIGHT A1

void setupMotor(void);
void driveMotor(byte, byte, byte);
void stopMotor(byte);
void setupSensor(void);

void setup() {
    setupMotor();

    setupSensor();
}

void loop() {
    if(analogRead(SENSOR_RIGHT) > 300)
        stopMotor(MOTOR_A);
    else
        driveMotor(MOTOR_A, REVERSE, 120);
    
    if(analogRead(SENSOR_LEFT) > 300)
        stopMotor(MOTOR_B);
    else
        driveMotor(MOTOR_B, REVERSE, 120);
    
    delay(10);
}

void setupMotor(void) {
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);

  digitalWrite(PWM_A, LOW);
  digitalWrite(PWM_B, LOW);
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
}

void driveMotor(byte motor, byte direction, byte speed) {
  switch(motor) {
    case 0:
      digitalWrite(DIR_A, direction);
      analogWrite(PWM_A, speed);
      break;
    case 1:
      digitalWrite(DIR_B, direction);
      analogWrite(PWM_B, speed);
      break;
    default:
      Serial.println("ERROR: Undefined motor value.");
  }
}

void stopMotor(byte motor) {
  driveMotor(motor, 0, 0);
}

void setupSensor(void) {
    pinMode(SENSOR_LEFT, INPUT);
    pinMode(SENSOR_RIGHT, INPUT);
}