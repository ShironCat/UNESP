#include <XBee.h>
#include <SoftwareSerial.h>

#define BUFFER_SIZE 30

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();

Rx16Response rx16 = Rx16Response();

uint8_t payload[BUFFER_SIZE];

Tx16Request tx = Tx16Request(0x0, payload, sizeof(payload));
SoftwareSerial sSerial = SoftwareSerial(2, 3);

uint8_t *data;
uint8_t length;

unsigned long mark;

long delay_time;

char message[BUFFER_SIZE];

bool hasMessage = false;

unsigned int message_length = 0;

void clearBuffer() {
  for(int i = 0; i < BUFFER_SIZE; i++) {
    payload[i] = 0;
    message[i] = '\0';
  }
}

void setup() {
  Serial.begin(9600);
  sSerial.begin(9600);
  xbee.setSerial(sSerial);

  mark = millis();

  delay_time = random(800, 900);

  clearBuffer();
}

void loop() {
  message_length = Serial.readBytesUntil('\n', message, 30);

  if(message_length > 0)
    hasMessage = true;

  if(hasMessage) {
    if((millis() - mark) > delay_time) {
      for(int i = 0; i < message_length; i++)
        payload[i] = message[i];
      
      tx.setPayloadLength(sizeof(payload));
      tx.setPayload(payload);

      xbee.send(tx);
      delay_time=random(800, 1000);
      mark=millis();

      hasMessage = false;
      clearBuffer();
    }
  }

  xbee.readPacket();

  if(xbee.getResponse().isAvailable()) {
    if(xbee.getResponse().getApiId() == RX_16_RESPONSE) {
      xbee.getResponse().getRx16Response(rx16);
      data = rx16.getData();
      length = rx16.getDataLength();
      for(int i = 0; i < length; i++)
        Serial.print(char(data[i]));
      Serial.println();
    }
  }
}