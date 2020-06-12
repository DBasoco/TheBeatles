// Motor A,D

int enAD = 10; // motors A&D will run the same way
int in1 = 9;
int in2 = 8


// Motor B,C

int enBC = 5; // motors B&C will run the same way
int in3 = 6;
int in4 = 7;


// I need some kind of input for wifi control here, still looking for how to do that



// here I set up the pins as outputs
void setup() {
  pinMode(enAD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enBC, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
