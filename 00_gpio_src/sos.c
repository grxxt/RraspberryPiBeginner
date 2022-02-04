#include <stdio.h>
#include <wiringPi.h>

const int pinLed1 = 20;

int main(void)
{
    int i;
    wiringPiSetupGpio();

    pinMode(pinLed1, OUTPUT);

    while (1)
    {
        for (i=0; i<3; i++) {
            digitalWrite(pinLed1, HIGH);
            delay(300);
            digitalWrite(pinLed1, LOW);
            delay(300);
        }
        //delay(1000);
        for (i=0; i<3; i++) {
            digitalWrite(pinLed1, HIGH);
            delay(1000);
            digitalWrite(pinLed1, LOW);
            delay(1000);
        }  
    }
    
    return 0;
}