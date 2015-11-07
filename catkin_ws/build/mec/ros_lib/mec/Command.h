#ifndef _ROS_mec_Command_h
#define _ROS_mec_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mec
{

  class Command : public ros::Msg
  {
    public:
      int16_t left_velocity;
      int16_t right_velocity;
      int16_t servo;

    Command():
      left_velocity(0),
      right_velocity(0),
      servo(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_velocity;
      u_left_velocity.real = this->left_velocity;
      *(outbuffer + offset + 0) = (u_left_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_velocity.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_velocity);
      union {
        int16_t real;
        uint16_t base;
      } u_right_velocity;
      u_right_velocity.real = this->right_velocity;
      *(outbuffer + offset + 0) = (u_right_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_velocity.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_velocity);
      union {
        int16_t real;
        uint16_t base;
      } u_servo;
      u_servo.real = this->servo;
      *(outbuffer + offset + 0) = (u_servo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->servo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_velocity;
      u_left_velocity.base = 0;
      u_left_velocity.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_velocity.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_velocity = u_left_velocity.real;
      offset += sizeof(this->left_velocity);
      union {
        int16_t real;
        uint16_t base;
      } u_right_velocity;
      u_right_velocity.base = 0;
      u_right_velocity.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_velocity.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_velocity = u_right_velocity.real;
      offset += sizeof(this->right_velocity);
      union {
        int16_t real;
        uint16_t base;
      } u_servo;
      u_servo.base = 0;
      u_servo.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->servo = u_servo.real;
      offset += sizeof(this->servo);
     return offset;
    }

    const char * getType(){ return "mec/Command"; };
    const char * getMD5(){ return "f00f0f23b9dfa3fe2d5dd6397990edae"; };

  };

}
#endif