#include <stdio.h>
#include <wiringPi.h>

const int pinLed = 21;  // LED가 연결된 21번 핀(BCM Mode)

int main(void)
{
    wiringPiSetupGpio(); // 핀 번호를 BCM Mode로 설정

    pinMode(pinLed, OUTPUT);  // LED 핀을 출력모드로 설정

    while (1)
    {
        digitalWrite(pinLed, HIGH);  // LED 핀의 상태를 HIGH로 변경
        delay(1000);                 // 1000msec(1초) 지연
        digitalWrite(pinLed, LOW);   // LED 핀의 상태를 LOW로 변경
        delay(1000);                 // 1000msec(1초) 지연
    }
    
    return 0;
}