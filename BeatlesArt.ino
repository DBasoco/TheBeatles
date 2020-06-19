#include <WiFiServer.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <WiFi.h>

// Motor A,D

int enAD = 10; // motors A&D will run the same way
int in1 = 9;
int in2 = 8;


// Motor B,C

int enBC = 5; // motors B&C will run the same way
int in3 = 6;
int in4 = 7;


// WiFi initialize
unsigned char topspin = 200;
char getstr;


//time delay and clock vs. counter

long randDelay;
long randDirec;


//motor speed

long randSpeedAD;
long randSpeedBC;

bool song;



// here I set up the pins as outputs
void setup() {
  Serial.begin(9600);
  
  pinMode(enAD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enBC, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  stop();
  song = true;

  digitalWrite(enAD, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(enBC, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  randomSeed(analogRead(0));

}

// have the vinyls spin

void spin() {
  while (getstr != 'S') {
    randDelay = random(5000, 25000);
    randDirec = random(0, 4);
    
    randSpeedAD = random(50, 256);
    randSpeedBC = random(50, 256);
    
    if (randDirec = 0) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (randDirec = 1) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (randDirec = 2) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (randDirec = 3) { 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    analogWrite(enAD, randSpeedAD);
    analogWrite(enBC, randSpeedBC);


    delay(randDelay);
  }
}

void stop() {
  digitalWrite(enAD, LOW);
  digitalWrite(enBC, LOW);

  song = !song;
}

// have the music play

void music() {
  song = true;  
  play();
}


void next(){
  
}


void previous() {
  
}


void pause() {
  
}


void play() {
  
}


void loop() {
  getstr = Serial.read();
  switch(getstr) {
    case 's': spin(); break;
    case 'm': music(); break;
    case 'c': music(); spin(); break;
    case 'S': stop(); break;
  }
}
