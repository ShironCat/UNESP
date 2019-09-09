void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  for(int i = 0; i <= 255; i++) {
    delay(10);
    analogWrite(9, i);
  }
  for(int i = 255; i >= 0; i--) {
    delay(10);
    analogWrite(9, i);
  }
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}