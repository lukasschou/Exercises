int incomingByte = 0;

void setup() {
  Serial.begin(9600);

  // sets the pins 2-6 as an output
  for (int i = 2; i <= 6; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // send data only when you recive data
  if (Serial.available() > 0){
    incomingByte = Serial.read();  //read the incoming byte from the Arduino

    // the characters a to e turns on a 5 different LEDs
    switch(incomingByte){
      case 97:
        digitalWrite(6, HIGH);
        break;
      case 98:
        digitalWrite(5, HIGH);
        break;
      case 99:
        digitalWrite(4, HIGH);
        break;
      case 100:
        digitalWrite(3, HIGH);
        break;
      case 101:
        digitalWrite(2, HIGH);
        break;
    }

    // every other character turns of all the LEDs
    if ((incomingByte > 40 && incomingByte < 91) || (incomingByte > 101 && incomingByte < 123)){
      for (int i = 2; i <= 6; i++){
          digitalWrite(i, LOW);
        }
    }
  }
}
