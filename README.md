# Raspi3-Arduino-I2C

Setting up Raspberry Pi 3:

$ sudo apt-get update
$ sudo apt-get upgrade

Enable i2c communicaiton from raspberry configuration using command ($sudo raspi-config) and reboot the device.
Install the essential tools/drivers for i2c commnication.

$ sudo apt-get install -y python-smbus i2c-tools

After this step, check whether the packages are installed correctly using the command:

$ lsmod | grep i2c_

It should show two i2c_bcm2835 and i2c_dev enabled. 

After this you need to finish the hardware connection properly with a slave device. Generally there is no need to use any resistor if directly working with Arduino board, however a 4k7 ohm resistor (in pull-up mode) is recommended for connecting any other module. for Arduino, you need to upload a program along with address, however for any other module, the address is predefined.

The address can now be checked on raspberry pi 3 using following command:

$ sudo i2cdetect -y 1

This command will show the exact address defined for arduino.

