// digitalRead()함수를 이용해 물체가 감지 됐을 때 터미널 창에 “Detected” 문구를
// 출력하는 예제
#include <stdio.h>
#include <wiringPi.h>

const int pinPir = 24;

int main(void)
{
    wiringPiSetupGpio();

    pinMode(pinPir, INPUT);

    while (1)
    {
        if (!digitalRead(pinPir))
        {
            printf("Detected\n");
            delay(500);
        }
    }
    
    return 0;
}