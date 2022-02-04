#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#define LED21 21   // 해당 핀에 LED연결
#define LED20 20

int main(void)
{
	int i;
	printf("Raspberry Pi - LED Blink\n");
	wiringPiSetupGpio();
	pinMode(LED20, OUTPUT);
	pinMode(LED21, OUTPUT);
	
	//while(1)
	for (i=0; i<5; i++)
	{
		//printf("Raspberry Pi - LED Blink (%d)\n", i+1);
		digitalWrite(LED20, HIGH);
		digitalWrite(LED21, HIGH);
		delay(500);
		digitalWrite(LED20, LOW);
		digitalWrite(LED21, LOW);
		delay(500);
	}
	
	return 0;
}


