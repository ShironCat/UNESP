void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(A3, INPUT);
  pinMode(10, OUTPUT);
  digitalWrite(A5, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(10, HIGH);
}

void loop() {
  int valor = map(analogRead(A3), 0, 100, 0, 255);
  Serial.println(valor);
  analogWrite(10, valor);
}