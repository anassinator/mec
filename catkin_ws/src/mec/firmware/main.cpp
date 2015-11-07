#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <mec/Command.h>
//#include "motor.h"

#define LED_PIN 13
#define IN1_PIN 3
#define IN2_PIN 5
#define IN3_PIN 6
#define IN4_PIN 9

ros::NodeHandle nh;

void commandCallback( const mec::Command& msg){
  if(msg.data > 0){

  }
  //digital()
}
ros::Subscriber<mec::Command> commandSub("/controls",&commandCallback);

void setup() {
  pinMode(LED_PIN,OUTPUT);
  pinMode(IN1_PIN,OUTPUT);
  pinMode(IN2_PIN,OUTPUT);
  pinMode(IN3_PIN,OUTPUT);
  pinMode(IN4_PIN,OUTPUT);

  nh.initNode();
  nh.subscribe(commandSub);

}

void loop() {
  nh.spinOnce();
  digitalWrite(LED_PIN,!digitalRead(LED_PIN));
}
