#define FORWARD 1
#define REVERSE 0

#define MOTOR_L 1
#define MOTOR_R 0

#define PWM_A 5
#define PWM_B 6
#define DIR_A 7
#define DIR_B 8

#define SENSOR_L 10
#define SENSOR_R 9

#define MINIMUM_SPEED_L 140
#define MAXIMUM_SPEED_L 170

#define MINIMUM_SPEED_R 120
#define MAXIMUM_SPEED_R 170

int turn = 0;

unsigned speed_motor_l = MINIMUM_SPEED_L;
unsigned speed_motor_r = MINIMUM_SPEED_R;

int sensor_counter_l = 0;
int sensor_counter_r = 0;

bool sensor_state_l = false;
bool sensor_state_r = false;

void setupMotor(void);
void driveMotor(byte, byte, byte);
void stopMotor(byte);

void setup(void) {
  setupMotor();

  delay(500);

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  if(digitalRead(SENSOR_L))
    sensor_state_l = true;
  if(digitalRead(SENSOR_R))
    sensor_state_r = true;
}

void loop(void) {
  driveMotor(MOTOR_L, FORWARD, speed_motor_l);
  driveMotor(MOTOR_R, FORWARD, speed_motor_r);

  if(turn >= 10) {
    if(sensor_counter_l > sensor_counter_r) {
      if(speed_motor_r < MAXIMUM_SPEED_R)
        speed_motor_r++;
      else if(speed_motor_l > MINIMUM_SPEED_L)
        speed_motor_l--;
    } else if(sensor_counter_l < sensor_counter_r) {
      if(speed_motor_l < MAXIMUM_SPEED_L)
        speed_motor_l++;
      else if(speed_motor_r > MINIMUM_SPEED_R)
        speed_motor_r--;
    }

    turn = sensor_counter_l = sensor_counter_r = 0;
  }

  if(digitalRead(SENSOR_L) != sensor_state_l) {
    sensor_counter_l++;
    sensor_state_l = !sensor_state_l;
  }
  if(digitalRead(SENSOR_R) != sensor_state_r) {
    sensor_counter_r++;
    sensor_state_r = !sensor_state_r;
  }

  turn++;
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