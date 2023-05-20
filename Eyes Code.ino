#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include "moods.h"

#define Ancho 128
#define Alto 64
#define OLED_RESET -1

int value = 0;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int infinite = 1;

Adafruit_SH1106 display(OLED_RESET);


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Wire.begin();
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  
  display.display();
  
  display.clearDisplay();
  display.display();
}

void loop() {
 
  while (infinite == 1){
    ultrasonic();
    if(distance >=20){
      eyesCenter(); //CENTRO
      if(distance <=25) {break;}
      delay(3000);

      if(distance <=25) {break;}
      eyesBlink(); //PARPADEO
      if(distance <=25) {break;}
      delay(90);
      
      if(distance <=25) {break;}
      eyesCenter(); //CENTRO
      if(distance <=25) {break;}
      delay(4000);

      if(distance <=25) {break;}
      eyesRight(); //DERECHA
      if(distance <=25) {break;}
      eyesRightCome();
      if(distance <=25) {break;}
      delay(3000);

      if(distance <=25) {break;}
      eyesLeft(); //IZQUIERDA
      if(distance <=25) {break;}
      eyesLeftCome();
      if(distance <=25) {break;}
      delay(3000);
    }
    else{
      eyesBack();
      delay(3000);
    }
  }
}

void ultrasonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034)/(2);
  Serial.println(distance);
}

void eyesCenter(){
  display.clearDisplay(); 
  display.drawBitmap(16, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(79, 16, mood1, 32, 32, WHITE);
  display.display();
}

void eyesBlink(){
  display.clearDisplay(); 
  display.drawBitmap(16, 16, mood0, 32, 32, WHITE); 
  display.drawBitmap(79, 16, mood0, 32, 32, WHITE);
  display.display();
}

void eyesRight(){
  display.clearDisplay(); 
  display.drawBitmap(18, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(81, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(400);  

  display.clearDisplay(); 
  display.drawBitmap(20, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(83, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(1000);
}

void eyesRightCome(){
  display.clearDisplay(); 
  display.drawBitmap(18, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(81, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(400);
      
  display.clearDisplay(); 
  display.drawBitmap(16, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(79, 16, mood1, 32, 32, WHITE);
  display.display();
}

void eyesLeft(){
  display.clearDisplay(); 
  display.drawBitmap(14, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(77, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(400);  

  display.clearDisplay(); 
  display.drawBitmap(12, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(75, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(1000);
}

void eyesLeftCome(){
  display.clearDisplay(); 
  display.drawBitmap(14, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(77, 16, mood1, 32, 32, WHITE);
  display.display();
  delay(400);

  display.clearDisplay(); 
  display.drawBitmap(16, 16, mood1, 32, 32, WHITE); 
  display.drawBitmap(79, 16, mood1, 32, 32, WHITE);
  display.display();
}

void eyesBack(){
  display.clearDisplay(); 
  display.drawBitmap(16, 16, mood2, 32, 32, WHITE); 
  display.drawBitmap(79, 16, mood2, 32, 32, WHITE);
  display.display();
}

/*
  for(value;value<=11;value++){
    display.clearDisplay();
    display.drawBitmap(20, 16, EyesAnimation[value], 32, 32, WHITE); 
    display.drawBitmap(75, 16, EyesAnimation[value], 32, 32, WHITE);
    display.display();
    Serial.println(value);
    delay(2000);    
  }
*/  