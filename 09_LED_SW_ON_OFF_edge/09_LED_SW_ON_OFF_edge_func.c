#include <stdio.h>
#include <wiringPi.h>

void edge_sw_led_rising(int* pre_sw_state, int* cur_sw_state, int* led_state, int pin);
void edge_sw_led_falling(int* pre_sw_state, int* cur_sw_state, int* led_state, int pin);

const int pinSwitch = 6;
const int pinLed = 21;
const int pinSwitch1 = 5;
const int pinLed1 = 20;

int main(void)
{
    int led_state = 0, led_state1 = 0;
    int pre_sw_state = 0, pre_sw_state1 = 0;
    int cur_sw_state = 0, cur_sw_state1 = 0;

    wiringPiSetupGpio();
    
    pinMode(pinSwitch, INPUT);
    pinMode(pinSwitch1, INPUT);
    pinMode(pinLed, OUTPUT);
    pinMode(pinLed1, OUTPUT);

    while (1)
    {
        cur_sw_state = digitalRead(pinSwitch);
        cur_sw_state1 = digitalRead(pinSwitch1);

        edge_sw_led_rising(&pre_sw_state, &cur_sw_state, &led_state, pinLed);
        edge_sw_led_falling(&pre_sw_state1, &cur_sw_state1, &led_state1, pinLed1);

        pre_sw_state = cur_sw_state;
        pre_sw_state1 = cur_sw_state1;
    }
    return 0;
}

void edge_sw_led_rising(int* pre_sw_state, int* cur_sw_state, int* led_state, int pin)
{
    if (*pre_sw_state == 0 && *cur_sw_state == 1)  // 0에서 1이 되는 조건 (상승엣지)
    {
        if (*led_state == 0)
        {
            digitalWrite(pin, HIGH);
            *led_state = 1;
        }
        else 
        {
            digitalWrite(pin, LOW);
            *led_state = 0;
        }
    }
}

void edge_sw_led_falling(int* pre_sw_state, int* cur_sw_state, int* led_state, int pin)
{
    if (*pre_sw_state == 1 && *cur_sw_state == 0)  // 0에서 1이 되는 조건 (상승엣지)
    {
        if (*led_state == 0)
        {
            digitalWrite(pin, HIGH);
            *led_state = 1;
        }
        else 
        {
            digitalWrite(pin, LOW);
            *led_state = 0;
        }
    }
}