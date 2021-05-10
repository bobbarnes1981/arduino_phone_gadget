char keys[] = {
  '#', '0', '*',
  '3', '2', '1',
  '6', '5', '4',
  '9', '8', '7',
  '9', '8', '7',
};

void setup() {
  Serial.begin(115200);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  int xOffset = 6;
  int yOffset = 2;
  for (int x = 0; x < 4; x++) {
    pinMode(x+xOffset, OUTPUT);
    digitalWrite(x+xOffset, 1);
    for (int y = 0; y < 4; y++) {
      int data = digitalRead(y+yOffset);
      int offset = y + (x * 3);
      if (data) {
        Serial.print(y);
        Serial.print(",");
        Serial.print(x);
        Serial.print(" ");
        Serial.print(offset);
        Serial.print(" ");
        Serial.print(keys[offset]);
        Serial.println();
      } else {
        
      }
    }
    digitalWrite(x+xOffset, 0);
    pinMode(x+xOffset, INPUT);
  }
  pinMode(11, OUTPUT);
  digitalWrite(11, 1);
  for (int y = 0; y < 4; y++) {
    int data = digitalRead(y+yOffset);
    if (data) {
      Serial.println("handset");
    }
  }
  digitalWrite(11, 0);
  pinMode(11, INPUT);

  pinMode(12, OUTPUT);
  digitalWrite(12, 1);
  for (int y = 0; y < 4; y++) {
    int data = digitalRead(y+yOffset);
    if (data) {
      Serial.println("redial");
    }
  }
  digitalWrite(12, 0);
  pinMode(12, INPUT);
}
