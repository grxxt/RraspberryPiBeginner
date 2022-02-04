#include <stdio.h>
#include <wiringPi.h>
#define LED 21   // 해당 핀에 LED연결

int main(void)
{
	int i;
	printf("Raspberry Pi - LED Blink\n");
	wiringPiSetupGpio();
	pinMode(LED, OUTPUT);
	
	//while(1)
	for (i=0; i<5; i++)
	{
		printf("Raspberry Pi - LED Blink (%d)\n", i+1);
		digitalWrite(LED, 0x80);
		delay(500);
		digitalWrite(LED, 0x00);
		delay(500);
	}
	
	return 0;
}

