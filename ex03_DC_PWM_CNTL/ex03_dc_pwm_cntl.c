#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <softPwm.h>

#define PERIOD 100          // 주기
#define UNIT PERIOD/10      // 단위

const int pinEnable = 12;
const int pinPositive = 4;
const int pinNegative = 25;
const int pinSwitch0 = 5;
const int pinSwitch1 = 6;

int duty = 10;

void motorSpin(void);
void motorStop(void);
void DC_MOTOR_DN(void);
void DC_MOTOR_UP(void);

int main(void)
{
    wiringPiSetupGpio();

    softPwmCreate(pinEnable, duty, PERIOD);
    pinMode(pinPositive, OUTPUT);
    pinMode(pinNegative, OUTPUT);

    pinMode(pinSwitch0, INPUT);
    pinMode(pinSwitch1, INPUT);

    wiringPiISR(pinSwitch0, INT_EDGE_RISING, DC_MOTOR_DN);
    wiringPiISR(pinSwitch1, INT_EDGE_RISING, DC_MOTOR_UP);

    digitalWrite(pinPositive, HIGH);
    digitalWrite(pinNegative, LOW);

    while(1)
    {

    }

    return 0;
}

void DC_MOTOR_DN(void)
{
    if (duty > 0)
        duty -= UNIT;
    else    
        duty = 0;

    softPwmWrite(pinEnable, duty);
}

void DC_MOTOR_UP(void)
{
    if (duty <= PERIOD)
        duty += UNIT;
    else 
        duty = 10;
    softPwmWrite(pinEnable, duty);
}
