#define delay_val 1

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <pthread.h>

void* FND4_Display(void* arg);

//              {A, B, C, D, E, F, G, DP}
int fndPin[8] = {9, 11, 0, 5, 6, 13, 19, 26};
int fndDigit[4] = {17, 27, 22, 10};
const int pinPir = 24;

int fndData[10][8] ={ {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW},   // 0
					  { LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},      // 1
					  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},    // 2
					  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW},    // 3
					  { LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},    // 4
			     	  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW},    // 5
					  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},   // 6
					  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},      // 7
					  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 8
					  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW} }; // 9

int fndDataBit[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0XFE, 0xF6};
int fndDigitBit[4] = {0x07, 0x0B, 0x0D, 0x0E};
                   // 0111, 1011 , 1101, 1110
int main(void)
{
	
	int i;
	int cnt = 0;
	pthread_t t_id;

	//wiringPiSetup
	wiringPiSetupGpio();

    pinMode(pinPir, INPUT);
	
	// Pin 모드 설정
    for(i = 0; i < 4; i++)
	{
		pinMode(fndDigit[i], OUTPUT);  // 입출력 모드 설정  (핀번호, 모드)
	}

	for(i = 0; i < 8; i++)
	{
		pinMode(fndPin[i], OUTPUT);  // 입출력 모드 설정  (핀번호, 모드)
	}

	if (pthread_create(&t_id, NULL, FND4_Display, (void*)&cnt) != 0)
	{
		printf("pthread_create() error!\n");
		return -1;
	}
	
	while(1)
    {   
		// FND4_Display(cnt);
        if (!digitalRead(pinPir))
        {
            printf("Detected %d\n", cnt+1);
		    cnt++;
		    delay(1000);
        }
    }
    
	return 0;
}

void* FND4_Display(void* arg)
{
	int i, j;
	int num_arr[4];
	int* num = (int*)arg;
	while (1)
	{
		num_arr[0] = *num / 1000;
		num_arr[1] = (*num%1000) / 100;
		num_arr[2] = (*num%100) / 10;
		num_arr[3] = *num % 10;

		for(j = 0; j < 4; j++)
		{   
			// digit 변경
			for(i = 0; i < 4; i++)
			{
				digitalWrite(fndDigit[i], fndDigitBit[j]&(0x08>>i));
			}
			// 데이터 변경
			for(i = 0; i < 8; i++)
			{
				digitalWrite(fndPin[i], fndDataBit[num_arr[j]]&(0x80>>i));
			}
			delay(delay_val);
		}
	}

	return NULL;
}