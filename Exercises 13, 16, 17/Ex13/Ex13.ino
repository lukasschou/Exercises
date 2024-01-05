bool Button;
int I = 0;  // counts the number of loops made
int x = 0;  // counts the LED that should be on
int counter_s = 0;  // count the number of succeses
int counter_f = 0;  // count the number of misses
int dance = 0;  // variable to make sure LED flash is only made ones

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
  if (counter_s < 10) {  // stop playing the game after 10 succeses
    // Sets the speed of the game (the speed of the LEDs)
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

    // button pressed on the wrong time
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
      delay(1000);
      // button pressed on the right time
    } else if (x == 2 && Button == 0) {
      counter_s += 1;
      Serial.println("Succes");
      Serial.print("you have ");
      Serial.print(counter_s);
      Serial.println(" succeses");
      // makes the LED flash 8 times
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
      // reset cycle
      x = 0;
      I = 0;
    }

    // LEDs flash randomly when 8 succeses have been made
    if (counter_s == 8 && dance == 0) {
      for (int i = 0; i <= 14; i++) {
        int ran = random(9, 14);  // random port between 9-13
        digitalWrite(ran, HIGH);
        delay(100);
        digitalWrite(ran, LOW);
        delay(100);
      }
      dance = 1;  // makes the random flash happend only ones
      delay(500);
    }

    digitalWrite(9 + x, LOW);  // turns the LED in the cycle off

    // end of game
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