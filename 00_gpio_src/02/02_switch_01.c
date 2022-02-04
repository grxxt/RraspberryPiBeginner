#include <stdio.h>
#include <wiringPi.h>

const int pinSwitch = 6;

int main(void)
{
    wiringPiSetupGpio();  // 핀 번호를 BCM Mode로 설정
    pinMode(pinSwitch, INPUT);  // SWITCH 핀을 입력모드로 설정

    while (1)
    {
        if (digitalRead(pinSwitch)) {
            printf("Pushed Switch\n");  // HIGH일 경우, "Pushed" 출력
            delay(500);
        }
    }
    
    return 0;
}