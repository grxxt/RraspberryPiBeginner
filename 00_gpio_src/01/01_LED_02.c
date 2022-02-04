// LED 2개를 이용해서 1초 간격으로 반전 ON/OFF 하는 예제
#include <stdio.h>
#include <wiringPi.h>

const int pinLed1 = 21;     // LED가 연결된 21번 핀(BCM Mode)
const int pinLed2 = 20;     // LED가 연결된 20번 핀(BCM Mode)

int main(void)
{
    wiringPiSetupGpio();

    pinMode(pinLed1, OUTPUT);
    pinMode(pinLed2, OUTPUT);

    while (1)
    {
        digitalWrite(pinLed1, HIGH);  // LED1 Pin HIGH
        digitalWrite(pinLed2, LOW);   // LED2 Pin LOW
        delay(1000);
        digitalWrite(pinLed1, LOW);   // LED1 Pin LOW
        digitalWrite(pinLed2, HIGH);  // LED2 Pin HIGH
        delay(1000);
    }
    
    return 0;
}