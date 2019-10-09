bool isFirstTurn = true;

void setup() {

  // Pins de direção
  // 12 -> A
  pinMode(12, OUTPUT);
  // 13 -> B
  pinMode(13, OUTPUT);

  // Pins de velocidade
  // 3 -> A
  pinMode(3, OUTPUT);
  // 11 -> B
  pinMode(11, OUTPUT);

  digitalWrite(3, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  analogWrite(3, 75);
  delay(200);
  analogWrite(3, 0);
  delay(200);
  analogWrite(11, 75);
  delay(200);
  analogWrite(11, 0);
  delay(500);
  if(isFirstTurn) {
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    isFirstTurn = false;
  } else {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    isFirstTurn = true;
  }
}