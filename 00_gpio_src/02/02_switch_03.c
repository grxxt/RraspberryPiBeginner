// SWITCH와 LED를 이용해서 SWITCH를 한 번 누르면 해당 번호의 LED가 켜지고 
// 손은 떼면 LED가 꺼지는 예제
#include <stdio.h>
#include <wiringPi.h>

const int pinSwitchArr[2] = {6, 5};
const int pinLedArr[2] = {21, 20};

int main(void)
{
    wiringPiSetupGpio();         // 핀 번호를 BCM Mode로 설정
    
    int i;
    
    for (i=0; i<2; i++) 
    {
        pinMode(pinSwitchArr[i], INPUT);  // SWITCH 1~2 핀을 입력모드로 설정
        pinMode(pinLedArr[i], OUTPUT);    // LED 1~2 핀을 출력모드로 설정
    }

    while (1)
    {
        for (i=0; i<2; i++)
        {
            if (digitalRead(pinSwitchArr[i]))       // 임의의 스위치를 누를 경우
                digitalWrite(pinLedArr[i], HIGH);
            else                                    // 누르지 않은 경우
                digitalWrite(pinLedArr[i], LOW);
        }
    }
    
    return 0;
}