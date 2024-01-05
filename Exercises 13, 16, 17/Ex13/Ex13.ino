bool Button;
int I = 0;
int x = 0;
int counter_s = 0;
int counter_f = 0;
int dance = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (counter_s < 10) { // stop playing the game after 10 succeses
    // Sets the speed
    I += 1;
    if (I == 10000 - (counter_s * 750)) {
      x += 1;
      if (x == 5) {
        x = 0;
      }
      I = 0;
    }

    digitalWrite(9 + x, HIGH);
    Button = digitalRead(2);

    if (x != 2 && Button == 0) {
      counter_f += 1;
      Serial.println("Miss");
      Serial.print("You have ");
      Serial.print(counter_f);
      Serial.println(" misses");
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      delay(2000);
    } else if (x == 2 && Button == 0) {
      counter_s += 1;
      Serial.println("Succes");
      Serial.print("you have ");
      Serial.print(counter_s);
      Serial.println(" succeses");
      for (int i = 0; i <= 7; i++) {
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        delay(200);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        delay(200);
      }
      x = 0;
      I = 0;
    }

    if (counter_s == 8 && dance == 0) {
      for (int i = 0; i <= 14; i++) {
        int ran = random(9, 14);
        digitalWrite(ran, HIGH);
        delay(100);
        digitalWrite(ran, LOW);
        delay(100);
      }
      dance = 1;
      delay(500);
    }

    digitalWrite(9 + x, LOW);

    if (counter_s == 10) {
      Serial.println("GAME OVER");
      Serial.print("You ended the game with ");
      Serial.print(counter_s);
      Serial.print(" succeses and ");
      Serial.print(counter_f);
      Serial.println(" misses");
    }
  }
}