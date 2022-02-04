#include <stdio.h>
#include <wiringPi.h>

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

        if (pre_sw_state == 0 && cur_sw_state == 1)  // 0에서 1이 되는 조건 (상승엣지)
        {
            if (led_state == 0)
            {
                digitalWrite(pinLed, HIGH);
                led_state = 1;
            }
            else 
            {
                digitalWrite(pinLed, LOW);
                led_state = 0;
            }
        }

        if (pre_sw_state1 == 1 && cur_sw_state1 == 0)  // 1에서 0이 되는 조건 (하강엣지)
        {
            if (led_state1 == 0)
            {
                digitalWrite(pinLed1, HIGH);
                led_state1 = 1;
            }
            else 
            {
                digitalWrite(pinLed1, LOW);
                led_state1 = 0;
            }
        }

        pre_sw_state = cur_sw_state;
        pre_sw_state1 = cur_sw_state1;
    }
    return 0;
}

