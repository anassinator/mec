#include <Arduino.h>

#define LED_PIN 13
#define IN1_PIN 3
#define IN2_PIN 5
#define IN3_PIN 6
#define IN4_PIN 9

void setup() {
  pinMode(LED_PIN,OUTPUT);
  pinMode(IN1_PIN,OUTPUT);
  pinMode(IN2_PIN,OUTPUT);
  pinMode(IN3_PIN,OUTPUT);
  pinMode(IN4_PIN,OUTPUT);
}

void loop() {

  digitalWrite(LED_PIN,HIGH);
  digitalWrite(IN1_PIN,HIGH);
  for(int i = 0; i < 256; i++){
    analogWrite(IN2_PIN,i);
    delay(10);
  }

  digitalWrite(LED_PIN,HIGH);
  digitalWrite(IN2_PIN,HIGH);
  for(int i = 0; i < 256; i++){
    analogWrite(IN1_PIN,i);
    delay(10);
  }

  digitalWrite(LED_PIN,HIGH);
  digitalWrite(IN3_PIN,HIGH);
  for(int i = 0; i < 256; i++){
    analogWrite(IN4_PIN,i);
    delay(10);
  }

  digitalWrite(LED_PIN,HIGH);
  digitalWrite(IN4_PIN,HIGH);
  for(int i = 0; i < 256; i++){
    analogWrite(IN3_PIN,i);
    delay(10);
  }
}
