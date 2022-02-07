#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define PERIOD 100          // 주기
#define UNIT PERIOD/10      // 단위

const int pinLed0 = 20;
const int pinLed1 = 21;
const int pinSw0 = 5;
const int pinSw1 = 6;
int duty = 0;

void LED_DOWN(void);
void LED_UP(void);

int main(void)
{
    wiringPiSetupGpio();

    pinMode(pinSw0, INPUT);
    pinMode(pinSw1, INPUT);

    softPwmCreate(pinLed0, duty, PERIOD);
    softPwmCreate(pinLed1, duty, PERIOD);

    wiringPiISR(pinSw0, INT_EDGE_RISING, LED_DOWN);
    wiringPiISR(pinSw1, INT_EDGE_RISING, LED_UP);
    
    while (1)
    {
        
    }
    
    
    // delay를 이용한 PWM 제어
    // pinMode(pinLed0, OUTPUT);
    // pinMode(pinLed1, OUTPUT);
    // while (1)
    // {
    //     digitalWrite(pinLed, HIGH);
    //     digitalWrite(pinLed1, HIGH);
    //     delayMicroseconds(100);
    //     digitalWrite(pinLed, LOW);
    //     delayMicroseconds(500);
    //     digitalWrite(pinLed1, LOW);
    //     delayMicroseconds(400);
    // }
    
    return 0;
}

void LED_DOWN(void)
{
    if (duty >= 0)
        duty -= UNIT;
    else 
        duty = 0;
    softPwmWrite(pinLed0, duty);
    softPwmWrite(pinLed1, duty);
}

void LED_UP(void)
{
    if (duty <= PERIOD)
        duty += UNIT;
    else
        duty = 100;
    softPwmWrite(pinLed0, duty);
    softPwmWrite(pinLed1, duty);
}
