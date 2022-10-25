# Using an I2C sensor with renode and STM32F4 HAL

This Demo platformio project shows how to add an I2C controller and an I2C sensor to a STM32F4 discovery platform, and how to read data from the sensor from your C code.

 - As framework we are using the **STM32CUBE**, with the F4 HAL (Hardware Abstraction Layer).

 - The sensor used is the **SI7021** which is already modelled in renode.

 - As driver, we are using
https://github.com/belyalov/stm32-hal-libraries/blob/master/si7021.c
which uses the HAL to perform the I2C operations.

## Usage
The project is already configured for usage, it should be a matter of clicking the
upload icon in your IDE of choice.

You should see the USART2 analyzer with the measurements of humidity and
temperature every 2 seconds (approximate, as time in simulation is not the same as real time).

To change the values of the environment you can use the **setter** of the temperature and humidity **properties** of the sensor model:

```
i2c1.sensor_si7021 Temperature 10
i2c1.sensor_si7021 Humidity 10
```

A very simple script is provided, that increases temperature and humidity over a period of 25 seconds.

On the analyzer you should see the values "measured" by the sensor.

Keep in mind:
 - There can be some discrepancies, as some conversions are performed when
   setting (in the .cs model) and reading (in the driver), so some precision is lost.

 - The temperature in the analyzer is shown multiplied by 100 (done by the driver).

