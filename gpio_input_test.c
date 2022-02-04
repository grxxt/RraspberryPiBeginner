#include <stdio.h>
#include <wiringPi.h>
#define KEY 5		// 해당 핀에 SWITCH 연결

int main(void)
{
	int val;
	printf("Raspberry Pi - Key Input Test\n");
	wiringPiSetupGpio();	// 핀 번호를 BCM모드로 설정
	pinMode(KEY, INPUT);	// SWITCH 핀을 입력모드로 설정
	
	while(1)
	{
		val=digitalRead(KEY);
		if (val==LOW)
			printf("Button is pressed\n");
		delay(1000);
	}
	return 0;
}
