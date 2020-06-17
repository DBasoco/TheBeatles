// Motor A,D

int enAD = 10; // motors A&D will run the same way
int in1 = 9;
int in2 = 8;


// Motor B,C

int enBC = 5; // motors B&C will run the same way
int in3 = 6;
int in4 = 7;

// Initialize motor speeds

int motorSpeedAD = 0;
int motorSpeedBC = 0;

// joystick input

int yAxis = A1;
int xAxis = A0;

int ypos = 512;
int xpos = 512;


// I need some kind of input for wifi control here, still looking for how to do that



// here I set up the pins as outputs
void setup() {
  pinMode(enAD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enBC, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(enAD, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(enBC, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  //randomSEED(analogREAD(0)); // here there will be input for music to generate random seed value for each run of the loop 

}


void loop() {
  ypos = analogRead(yAxis);
  xpos = analogRead(xAxis);

  if (ypos < 460) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    ypos = ypos - 460;
    ypos = ypos * -1;

    motorSpeedAD = map(ypos, 0, 460, 0, 255);
    motorSpeedBC = map(ypos, 0, 460, 0, 255);
  }
  else if (ypos > 564) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    motorSpeedAD = map(ypos, 564, 1023, 0, 255);
    motorSpeedBC = map(ypos, 564, 1023, 0, 255);
  }
  else {
    motorSpeedAD = 0;
    motorSpeedBC = 0;
  }


  if (xpos < 460) {
    xpos = xpos - 460;
    xpos = xpos * -1;

    xpos = map(xpos, 0, 460, 0, 255);

    motorSpeedAD = motorSpeedAD - xpos;
    motorSpeedBC = motorSpeedBC + xpos;

    if (motorSpeedAD < 0) motorSpeedAD = 0;
    if (motorSpeedBC > 255) motorSpeedBC = 255;
  }
  else if (xpos > 564) {
    xpos = map(xpos, 564, 1023, 0, 255);

    motorSpeedAD = motorSpeedAD + xpos;
    motorSpeedBC = motorSpeedBC - xpos;

    if (motorSpeedAD > 255) motorSpeedAD = 255;
    if (motorSpeedBC < 0) motorSpeedBC = 0;
  }

  analogWrite(enAD, motorSpeedAD);
  analogWrite(enBC, motorSpeedBC);


  
}
