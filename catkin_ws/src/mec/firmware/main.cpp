#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <mec/Command.h>
#include <Servo.h>

#define LED_PIN 13
#define IN1_PIN 2
#define IN2_PIN 3
#define IN3_PIN 4
#define IN4_PIN 5
#define SERVO_PIN 6
#define COMMAND_TIMEOUT 500

unsigned long last_command = 0;
Servo servo;

ros::NodeHandle nh;

void stopMotors() {
    digitalWrite(IN1_PIN,LOW);
    digitalWrite(IN2_PIN,LOW);
    digitalWrite(IN3_PIN,LOW);
    digitalWrite(IN4_PIN,LOW);
}

void commandCallback( const mec::Command& msg){
  digitalWrite(LED_PIN,!digitalRead(LED_PIN));
  last_command = micros();
  digitalWrite(IN1_PIN,msg.left_velocity > 0);
  analogWrite(IN2_PIN,msg.left_velocity & 0xFF);
  digitalWrite(IN3_PIN,msg.right_velocity > 0);
  analogWrite(IN4_PIN,msg.right_velocity & 0xFF);
  servo.write(msg.servo);
}

ros::Subscriber<mec::Command> commandSub("/controls",&commandCallback);

void setup() {
  pinMode(LED_PIN,OUTPUT);
  pinMode(IN1_PIN,OUTPUT);
  pinMode(IN2_PIN,OUTPUT);
  pinMode(IN3_PIN,OUTPUT);
  pinMode(IN4_PIN,OUTPUT);

  servo.attach(SERVO_PIN);

  nh.initNode();
  nh.subscribe(commandSub);

}

void loop() {
  nh.spinOnce();
  if(last_command < micros() + COMMAND_TIMEOUT){
  }
}
