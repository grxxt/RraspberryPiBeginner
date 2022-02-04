// Interrup을 이용해 SWITCH를 누르면 해당 번호의 LED가 켜지고 다시 누르면 꺼지는 예제
#include <stdio.h>
#include <wiringPi.h>

const int pinSwitchArr[2] = {6, 5};     // SWITCH 6, 5번 핀
const int pinLedArr[2] = {21, 20};      // LED 21, 20번 핀

int ledFlag1 = 0;       // 인터럽트 함수에서 사용될 변수 정의
int ledFlag2 = 1;

// ------ Interrupt 서비스 루틴 정의 -------
void ledBlink1(void)  // SWITCH1에 사용될 인터럽트 함수 정의
{
    if (ledFlag1 == 0)
    {
        digitalWrite(pinLedArr[0], HIGH);
        ledFlag1 = 1;
    }
    else 
    {
        digitalWrite(pinLedArr[0], LOW);
        ledFlag1 = 0;
    }
}

void ledBlink2(void)  // SWITCH2에 사용될 인터럽트 함수 정의
{
    if (ledFlag2 == 0)
    {
        digitalWrite(pinLedArr[1], HIGH);
        ledFlag2 = 1;
    }
    else 
    {
        digitalWrite(pinLedArr[1], LOW);
        ledFlag2 = 0;
    }
}
// ----------------------------------------

int main(void)
{
    wiringPiSetupGpio();    // 핀 번호를 BCM Mode로 설정

    int i;
    for (i=0; i<2; i++)
    {
        pinMode(pinSwitchArr[i], INPUT);    // 입력모드
        pinMode(pinLedArr[i], OUTPUT);      // 츨력모드
    }

    // SWITCH1의 인터럽트 설정, RISING Mode, ledBlink1 함수 호출
    wiringPiISR(pinSwitchArr[0], INT_EDGE_RISING, ledBlink1);

    // SWITCH2의 인터럽트 설정, FALLING Mode, ledBlink2 함수 호출
    wiringPiISR(pinSwitchArr[1], INT_EDGE_FALLING, ledBlink2);

    while (1)
    {
        
    }
    
}