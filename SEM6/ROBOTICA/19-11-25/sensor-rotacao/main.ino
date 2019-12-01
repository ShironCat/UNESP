#define FORWARD 0
#define REVERSE 1

#define MOTOR_A 0
#define MOTOR_B 1

#define PWM_A 5
#define PWM_B 6
#define DIR_A 7
#define DIR_B 8

#define SENSOR_L 10
#define SENSOR_R 9

int command = 0;

int counter_left = 0;
int counter_right = 0;

bool sensor_state_l = false;
bool sensor_state_r = false;

void setupMotor(void);
void driveMotor(byte, byte, byte);
void stopMotor(byte);

void setup(void) {
  Serial.begin(9600);

  setupMotor();

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  if(digitalRead(SENSOR_L))
    sensor_state_l = true;
  if(digitalRead(SENSOR_R))
    sensor_state_r = true;

  delay(1000);
}

void loop(void) {
  command = Serial.read();

  if(command == 'z')
    counter_left = counter_right = 0;

  if(command == 'l') {
    driveMotor(MOTOR_B, FORWARD, 200);
  } else if(command != 10) {
    stopMotor(MOTOR_B);
  }
  if(command == 'r') {
    driveMotor(MOTOR_A, FORWARD, 200);
  } else if(command != 10) {
    stopMotor(MOTOR_A);
  }

  if(digitalRead(SENSOR_L) != sensor_state_l) {
    counter_left++;
    sensor_state_l = !sensor_state_l;
  }
  if(digitalRead(SENSOR_R) != sensor_state_r) {
    counter_right++;
    sensor_state_r = !sensor_state_r;
  }
  
  Serial.print("Sensor esquerdo: ");
  Serial.println(counter_left);
  Serial.print("Sensor direito: ");
  Serial.println(counter_right);
  Serial.println();
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