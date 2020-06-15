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


// I need some kind of input for wifi control here, still looking for how to do that



// here I set up the pins as outputs
void setup() {
  pinMode(enAD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enBC, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //randomSEED(analogREAD(0)); // here there will be input for music to generate random seed value for each run of the loop 

}


void loop() {
  int xAxis = analogRead(A0);
  int yAxis = analogRead(A1);

  //yAxis control test, car drive

  if (yAxis < 470) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    motorSpeedAD = map(yAxis, 470, 0, 0, 255);
    motorSpeedBC = map(yAxis, 470, 0, 0, 255);
  }

  else if (yAxis > 550) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    motorSpeedAD = map(yAxis, 550, 1023, 0, 255);
    motorSpeedBC = map(yAxis, 550, 1023, 0, 255);
  }

  else {
    motorSpeedAD = 0;
    motorSpeedBC = 0;
  }

  //xAxis control test car drive
  
  if (xAxis < 470) {
    int xMapped = map(xAxis, 470, 0, 0, 255);

    motorSpeedAD = motorSpeedAD - xMapped;
    motorSpeedBC = motorSpeedBC + xMapped;

    if (motorSpeedAD < 0) {
      motorSpeedAD = 0;
    }
    if (motorSpeedBC > 255) {
      motorSpeedBC = 255;
    }
  }

  if (xAxis > 550) {
    int xMapped = map(xAxis, 550, 1023, 0, 255);

    motorSpeedAD = motorSpeedAD + xMapped;
    motorSpeedBC = motorSpeedBC - xMapped;

    if (motorSpeedAD > 255) {
      motorSpeedAD = 255;
    }
    if (motorSpeedBC < 0) {
      motorSpeedBC = 0;
    }
  }

  //magentic shearing observed at low output, prevent by shut off command

  if (motorSpeedAD < 70) {
    motorSpeedAD = 0;
  }
  if (motorSpeedBC < 70) {
    motorSpeedBC = 0;
  }

  //output speed sent to motors
  analogWrite(enAD, motorSpeedAD);
  analogWrite(enBC, motorSpeedBC);
}
