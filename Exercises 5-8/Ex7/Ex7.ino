int redpin = 2; // select the pin for the red LED
int greenpin = 3; // select the pin for the green LED
int bluepin = 4; // select the pin for the  blue LED
int red;
int green;
int blue;

void setup() {
  pinMode(redpin, OUTPUT); //Set pins as output
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
if (Serial.available() > 0){  // send data only when you recive data
  red = Serial.parseInt(); 
  green = Serial.parseInt();
  blue = Serial.parseInt();
  Serial.parseInt();  //To compromise for an extra null
}
  analogWrite(redpin, red);  //Send data to pins
  analogWrite(greenpin, green);
  analogWrite(bluepin, blue);
}





