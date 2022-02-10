#include <stdio.h>
#include <i2c_gpio_api.h>

int fd_sht20;

// float I2C_SHT20_TEMP(int fd);
// float I2C_SHT20_HUMI(int fd);

int main(void)
{
    float temp = 0.0;
    float humi = 0.0;
    int i, value;

    fd_sht20 = I2C_SHT20_config(SHT20_I2C_ADDR);


    while (1)
    {
        temp = I2C_SHT20_TEMP(fd_sht20);
        humi = I2C_SHT20_HUMI(fd_sht20);
        
        printf("TEMP : %.1f\n", (float)temp);
        printf("HUMI : %.1f\n", (float)humi);
        delay(1000);
    }

    return 0;
}
