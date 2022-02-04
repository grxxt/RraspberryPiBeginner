#include <stdio.h>
#include <wiringPi.h>

void LED0_Toggle(void);
void LED1_Toggle(void);
void PIR_Detected(void);

const int pinSwitch = 6;
const int pinSwitch1 = 5;
const int pinLed = 21;
const int pinLed1 = 20;
const int pinPir = 24;
int ledstatus = 0;
int ledstatus1 = 0;
int cnt = 0;

int main(void)
{
    wiringPiSetupGpio();
    
    pinMode(pinSwitch, INPUT);
    pinMode(pinSwitch1, INPUT);
    pinMode(pinLed, OUTPUT);
    pinMode(pinLed1, OUTPUT);

    wiringPiISR(pinSwitch, INT_EDGE_RISING, LED0_Toggle);
    wiringPiISR(pinSwitch1, INT_EDGE_FALLING, LED1_Toggle);
    wiringPiISR(pinPir, INT_EDGE_FALLING, PIR_Detected);

    while (1)
    {
    
    }
    
    return 0;
}

void LED0_Toggle(void)
{
    printf("pushed...0\n");
    if ((ledstatus == 0)) 
    {
        digitalWrite(pinLed, HIGH);
        ledstatus = 1;
    }
    else 
    {
        digitalWrite(pinLed, LOW);
        ledstatus = 0;
    }
}

void LED1_Toggle(void)
{
    printf("pushed...1\n");
    if ((ledstatus1 == 0)) 
    {
        digitalWrite(pinLed1, HIGH);
        ledstatus1 = 1;
    }
    else 
    {
        digitalWrite(pinLed1, LOW);
        ledstatus1 = 0;
    }
}

void PIR_Detected(void)
{
    cnt++;
    printf("Detected... %d\n", cnt);
}
