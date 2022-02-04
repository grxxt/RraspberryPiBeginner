#include <stdio.h>
#include <wiringPi.h>

const int pinSwitch = 6;
const int pinSwitch1 = 5;
const int pinLed = 21;
const int pinLed1 = 20;
int ledstatus = 0;
int ledstatus1 = 0;

int main(void)
{
    wiringPiSetupGpio();
    
    pinMode(pinSwitch, INPUT);
    pinMode(pinSwitch1, INPUT);
    pinMode(pinLed, OUTPUT);
    pinMode(pinLed1, OUTPUT);
    
    while (1)
    {
        if (digitalRead(pinSwitch) == HIGH)
        {
            if ((ledstatus == 0)) {
                digitalWrite(pinLed, HIGH);
                delay(500);
                ledstatus = 1;
            }
            else {
                digitalWrite(pinLed, LOW);
                delay(500);
                ledstatus = 0;
            }
        }
        if (digitalRead(pinSwitch1) == HIGH)
        {
            if ((ledstatus1 == 0)) {
                digitalWrite(pinLed1, HIGH);
                delay(500);
                ledstatus1 = 1;
            }
            else {
                digitalWrite(pinLed1, LOW);
                delay(500);
                ledstatus1 = 0;
            }
        }
    }
    
    return 0;
}

