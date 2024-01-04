int redpin = 2; // select the pin for the red LED
int greenpin = 3; // select the pin for the green LED
int bluepin = 4; // select the pin for the  blue LED
float red;
int green;
int blue;
float val;
float voltage;
float x = 255./133.4; 

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

  val = analogRead(A0);
  voltage = 3.3/667*val;

  // Split up the rainbow in 5 parts, one for each decline and incline for a color
  if (0 <= val && val < 133.4){ // red LED decline
    red = 255-x*val;
    blue = 255;
  }
  if (133.4 <= val && val < 133.4*2){ // green LED incline
    green = (val-133.4)*2;
    blue = 255;
  }
  if (133.4*2 < val && val < 133.4*3){  // blue LED decline
    blue = 255-x*(val-133.4*2);
    green = 255;
  }
  if (133.4*3 < val && val < 133.4*4){  // red LED incline
    red = (val-133.4*3)*2;
    green = 255;
  }
  if (133.4*4 < val && val < 133.4*5){  // green LED decline
    green = 255-x*(val-133.4*4);
  }

  // limits the green LED to 255, because it shuts of if over 255
  if (green > 255){
    green = 255;
  }
  
  Serial.print(val);
  Serial.print(" ");
  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.println(blue);

  analogWrite(redpin, red);  //Send data to pins
  analogWrite(greenpin, green);
  analogWrite(bluepin, blue);
}