#include <stdio.h>
#include <i2c_gpio_api.h>

int fd_light;

int main(void)
{
    float light_value = 0.0;
    int a_data[2];
    int i, value;

    fd_light = I2C_LIGHT_config(LIGHT_I2C_ADDR);


    while (1)
    {
        light_value = I2C_LIGHT_BRIGHT(fd_light);

        printf("LIGHT : %.1f\n", (float)light_value);
        delay(1000);
    }

    return 0;
}
