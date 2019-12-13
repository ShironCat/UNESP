#include <XBee.h>
#include <SoftwareSerial.h>
#include <Ultrasonic.h>

#define BUFFER_SIZE 30

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
#define MAXIMUM_SPEED_L 255

#define MINIMUM_SPEED_R 140
#define MAXIMUM_SPEED_R 255

#define TRIG_PIN 3
#define ECHO_PIN 4

int turn = 0;

unsigned speed_motor_l = MINIMUM_SPEED_L;
unsigned speed_motor_r = MINIMUM_SPEED_R;

int sensor_counter_l = 0;
int sensor_counter_r = 0;

bool sensor_state_l = false;
bool sensor_state_r = false;

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();

Rx16Response rx16 = Rx16Response();

const String msg_template = "OBSTACULO: ";

String str_message;

char message[BUFFER_SIZE];

uint8_t payload[BUFFER_SIZE];

Tx16Request tx = Tx16Request(0x0, payload, sizeof(payload));
SoftwareSerial sSerial = SoftwareSerial(2, 3);

uint8_t *data;
uint8_t length;

unsigned long mark;

long delay_time;

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

int distance;

void setupMotor(void);
void driveMotor(byte, byte, byte);
void stopMotor(byte);
void clearBuffer(void);

void setup(void) {
  Serial.begin(9600);

  setupMotor();

  delay(500);

  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_R, INPUT);

  if(digitalRead(SENSOR_L))
    sensor_state_l = true;
  if(digitalRead(SENSOR_R))
    sensor_state_r = true;
  
  clearBuffer();

  randomSeed(analogRead(0));
}

void loop(void) {
  distance = ultrasonic.read();
  if(ultrasonic.read() > 20) {
    driveMotor(MOTOR_L, FORWARD, speed_motor_l);
    driveMotor(MOTOR_R, FORWARD, speed_motor_r);
    delay(50);
    stopMotor(MOTOR_L);
    stopMotor(MOTOR_R);

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
  } else {
    stopMotor(MOTOR_L);
    stopMotor(MOTOR_R);
    
    delay(2500);

    distance = ultrasonic.read();

    str_message = msg_template;

    str_message.concat(distance);

    str_message.toCharArray(message, BUFFER_SIZE);

    for(int i = 0; i < BUFFER_SIZE; i++)
      payload[i] = message[i];
    
    tx.setPayloadLength(sizeof(payload));
    tx.setPayload(payload);

    xbee.send(tx);
    delay_time=random(800, 1000);
    mark=millis();
    
    clearBuffer();

    sensor_counter_l = sensor_counter_r = 0;
    
    sensor_state_l = sensor_state_r = false;

    if(digitalRead(SENSOR_L))
      sensor_state_l = true;
    if(digitalRead(SENSOR_R))
      sensor_state_r = true;
    
    if(random(0, 2)) {
      while(sensor_counter_l < 25) {
        driveMotor(MOTOR_L, REVERSE, speed_motor_l);
        delay(10);
        stopMotor(MOTOR_L);
        if(digitalRead(SENSOR_L) != sensor_state_l) {
          sensor_counter_l++;
          sensor_state_l = !sensor_state_l;
        }
      }
    } else {
      while(sensor_counter_r < 25) {
        driveMotor(MOTOR_R, REVERSE, speed_motor_r);
        delay(10);
        stopMotor(MOTOR_R);
        if(digitalRead(SENSOR_R) != sensor_state_r) {
          sensor_counter_r++;
          sensor_state_r = !sensor_state_r;
        }
      }
    }

    sensor_counter_l = sensor_counter_r = 0;
    
    sensor_state_l = sensor_state_r = false;

    if(digitalRead(SENSOR_L))
      sensor_state_l = true;
    if(digitalRead(SENSOR_R))
      sensor_state_r = true;
    
    delay(2500);
  }
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

void clearBuffer(void) {
  for(int i = 0; i < BUFFER_SIZE; i++) {
    payload[i] = 0;
    message[i] = '\0';
  }
  str_message = "";
}