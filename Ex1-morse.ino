int unit = 200; // length of a unit of lenght given in ms
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
}

void loop() {
  Morse('L');
  delay(2*unit); // delay between each character
  Morse('U');
  delay(2*unit);
  Morse('K');
  delay(2*unit); // delay between each character
  Morse('A');
  delay(2*unit);
  Morse('S');
  delay(6*unit); // delay between each word

  for(int i = 0; i < 10; i++){
    Morse('S');
    delay(2*unit); // delay between each character
    Morse('O');
    delay(2*unit);
    Morse('S');
    delay(6*unit); // delay between each word
  }
}

// make a dot in morse code (1 unit of length)
void dot(){
  digitalWrite(2, HIGH);  
  delay(unit);                      
  digitalWrite(2, LOW);   
  delay(unit);   
}

// make a dash in morse code (3 units of length)
void dash(){
  digitalWrite(2, HIGH);  
  delay(3*unit);                      
  digitalWrite(2, LOW);   
  delay(unit);   
}

// A case for each morse character
// Each character has a determinted
// number of dots and dashes in a paticular order
void Morse(char character) {
switch (character) {
  case 'A':
    dot();
    dash();                                       
    break;
  case 'B':
    dash();
    dot();
    dot();
    dot();
    break;
  case 'C':
    dash();
    dot();
    dash();
    dot();
    break;
  case 'D':
    dash();
    dot();
    dot();
    break;
  case 'E':
    dot();
    break;
  case 'F':
    dot();
    dot();
    dash();
    dot();
    break;
  case 'G':
    dash();
    dash();
    dot();
    break;
   case 'H':
    dot();
    dot();
    dot();
    dot();
    break;
  case 'I':
    dot();
    dot();
    break;
  case 'J':
    dot();
    dash();
    dash();
    dash();
    break;
  case 'K':
    dash();
    dot();
    dash();
    break;
  case 'L':
    dot();
    dash();
    dot();
    dot();
    break;
  case 'M':
    dash();
    dash();
    break;
  case 'N':
    dash();
    dot();
    break;
  case 'O':
    dash();
    dash();
    dash();
    break;
  case 'P':
    dot();
    dash();
    dash();
    dot();
    break;
  case 'Q':
    dash();
    dash();
    dot();
    dash();
    break;
  case 'R':
    dot();
    dash();
    dot();
    break;
  case 'S':
    dot();
    dot();
    dot();
    break;
  case 'T':
    dash();
    break;
  case 'U':
    dot();
    dot();
    dash();
    break;
  case 'V':
    dot();
    dot();
    dot();
    dash();
    break;
  case 'W':
    dot();
    dash();
    dash();
    break;
  case 'X':
    dash();
    dot();
    dot();
    dash();
    break;
  case 'Y':
    dash();
    dot();
    dash();
    dash();
    break;
  case 'Z':
    dash();
    dash();
    dot();
    dot();
    break;
  case '1':
    dot();
    dash();
    dash();
    dash();
    dash();
    break;
  case '2':
    dot();
    dot();
    dash();
    dash();
    dash();
    break;
  case '3':
    dot();
    dot();
    dot();
    dash();
    dash();
    break;
  case '4':
    dot();
    dot();
    dot();
    dot();
    dash();
    break;
  case '5':
    dot();
    dot();
    dot();
    dot();
    dot();
    break;
  case '6':
    dash();
    dot();
    dot();
    dot();
    dot();
    break;
  case '7':
    dash();
    dash();
    dot();
    dot();
    dot();
    break;
  case '8':
    dash();
    dash();
    dash();
    dot();
    dot();
    break;
  case '9':
    dash();
    dash();
    dash();
    dash();
    dot();
    break;
  case '0':
    dash();
    dash();
    dash();
    dash();
    dash();
    break;
}
}