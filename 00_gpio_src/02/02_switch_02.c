#include <stdio.h>
#include <wiringPi.h>

const int pinSwitchArr[2]={6,5};  // SWITCH가 연결된 6, 5번 핀을 배열로 정의

int main(void)
{
    wiringPiSetupGpio();    // BCM Mode로 설정

    int i;
    for (i=0; i<2; i++)
        pinMode(pinSwitchArr[i], INPUT);    // SWITCH 1~2핀 입력모드로  설정
    
    while (1)
    {
        for (i=0; i<2; i++)
        {
            if (digitalRead(pinSwitchArr[i]))       // 임의의 SWITCH를 누르면
            {
                printf("SWITCH[%d] Pushed\n", i);   // 해당하는 번호와 함께 출력
                delay(500);
            }
        }
    }
    
    return 0;
}