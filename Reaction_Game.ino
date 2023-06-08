#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

AsyncDelay delay_count;
int rightbutton = 5;
int leftbutton = 4;
volatile int count = 0;
volatile int rightstate = 0;
volatile int leftstate = 0;
float X, Y, Z, totalAccel;
float midi[127];
int A_four = 440;
int red = (255,0,0);
int blue = (0,0,255);
int green = (0,255,0);
volatile int level = 1;
volatile int score = 1;

void right () {
  rightstate = 1;
  

  }
void left (){
  leftstate = 1;
}
void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void setup() {
CircuitPlayground.begin();
attachInterrupt(digitalPinToInterrupt(rightbutton), right, CHANGE);
attachInterrupt(digitalPinToInterrupt(leftbutton), left, CHANGE);
Serial.begin(9600);
generateMIDI();
delay_count.start(500, AsyncDelay::MILLIS);
}

void loop() {
  CircuitPlayground.playTone(440.00, 250);
  delay(1000);
for (int i=0; i<3; i++) {
  level=i+1;
  for (int i=0; i<4; i++) {
    Serial.println(score);
long rand = random(0,3);
switch (rand) {
  case 0:
  CircuitPlayground.setPixelColor(0,255,0,0);
  CircuitPlayground.setPixelColor(1,255,0,0);
  CircuitPlayground.setPixelColor(2,255,0,0);
  CircuitPlayground.setPixelColor(3,255,0,0);
  CircuitPlayground.setPixelColor(4,255,0,0);
  CircuitPlayground.setPixelColor(5,255,0,0);
  CircuitPlayground.setPixelColor(6,255,0,0);
  CircuitPlayground.setPixelColor(7,255,0,0);
  CircuitPlayground.setPixelColor(8,255,0,0);
  CircuitPlayground.setPixelColor(9,255,0,0);
  delay(500/level);
  CircuitPlayground.clearPixels();
  delay(500/level);
  break;
  
  case 1:
  CircuitPlayground.setPixelColor(0,0,255,0);
  CircuitPlayground.setPixelColor(1,0,255,0);
  CircuitPlayground.setPixelColor(2,0,255,0);
  CircuitPlayground.setPixelColor(3,0,255,0);
  CircuitPlayground.setPixelColor(4,0,255,0);
  CircuitPlayground.setPixelColor(5,0,255,0);
  CircuitPlayground.setPixelColor(6,0,255,0);
  CircuitPlayground.setPixelColor(7,0,255,0);
  CircuitPlayground.setPixelColor(8,0,255,0);
  CircuitPlayground.setPixelColor(9,0,255,0);
  delay(500/level);
  CircuitPlayground.clearPixels();
  delay(500/level);
  break;

  case 2:
  CircuitPlayground.setPixelColor(0,0,0,255);
  CircuitPlayground.setPixelColor(1,0,0,255);
  CircuitPlayground.setPixelColor(2,0,0,255);
  CircuitPlayground.setPixelColor(3,0,0,255);
  CircuitPlayground.setPixelColor(4,0,0,255);
  CircuitPlayground.setPixelColor(5,0,0,255);
  CircuitPlayground.setPixelColor(6,0,0,255);
  CircuitPlayground.setPixelColor(7,0,0,255);
  CircuitPlayground.setPixelColor(8,0,0,255);
  CircuitPlayground.setPixelColor(9,0,0,255);
  delay(500/level);
  CircuitPlayground.clearPixels();
  delay(500/level);
  break;

}
X = 0;
  Y = 0;
  Z = 0;
  for (int i=0; i<10; i++) {
    X += CircuitPlayground.motionX();
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }
  X /= 10;
  Y /= 10;
  Z /= 10;

  totalAccel = sqrt(X*X + Y*Y + Z*Z);

delay_count.repeat();
if (rand ==2 && leftstate ==1) {

  score=score + 1;
leftstate=0;
  CircuitPlayground.clearPixels();
}
if (rand == 1 && rightstate == 1) {

 score=score + 1;
rightstate=0;
  CircuitPlayground.clearPixels();

}
if (rand == 0 && totalAccel >= 15) {

score=score + 1;
  CircuitPlayground.clearPixels();

}


delay(3000);
  }
  level= level+1;
} 

Serial.println(score);
if (score ==1) {
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score == 2)  {
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==3) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==4) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==5) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==6) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==7) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score ==8) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score == 9) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score == 10) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score == 11) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}
if (score == 12) {
CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
  CircuitPlayground.playTone(midi[64], 200);
  delay(100);
  CircuitPlayground.playTone(midi[127], 200);
  delay(100);
}

delay(10000);
score=0;
}


