bool estadoLED = false;
bool estadoBotao = false;

void setup() {
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(13, LOW);
}

void alternarLED() {
  if(estadoLED) {
    digitalWrite(13, LOW);
    estadoLED = false;
  } else {
    digitalWrite(13, HIGH);
    estadoLED = false;
  }
}

void lerBotao() {
  while(digitalRead(3)) {
    estadoBotao = true;
  }
  if(estadoBotao) {
    alternarLED();
    estadoBotao = false;
  }
}

void loop() {
  lerBotao();
}