#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#define LED_CNT 2
int ledControl(int* gpio);

int main(int argc, char** argv)
{
	int gno[LED_CNT]={0}, i;
	
	if (argc < 3) {
		printf("Usage : %s GPIO_NO1 GPIO_NO2\n", argv[0]);
		return -1;
	}
	
	for (i=0; i<2; i++)
	{
		gno[i]=atoi(argv[i+1]);
	}
	
	wiringPiSetup();
	ledControl(gno);
		
	return 0;
	
}

int ledControl(int* gpio)
{
	int i, j;
	
	for (i=0; i<LED_CNT; i++)
	{
		pinMode(gpio[i], OUTPUT);
	}
	
	for (i=0; i<3; i++) {
		for (j=0; j<LED_CNT; j++)
		{
			digitalWrite(gpio[j], HIGH);
			//delay(1000);
			//digitalWrite(gpio[i+1], LOW);
			//delay(1000);
		}
		delay(1000);
		for (j=0; j<LED_CNT; j++)
		{
			digitalWrite(gpio[j], LOW);
		}
		delay(1000);
	}
	
	return 0;
}
