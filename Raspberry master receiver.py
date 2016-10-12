import smbus
import time
# for RPI version 1, use .bus = smbus.SMBus(0).
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeNumber(value):
	bus.write_byte(address, value)
	return -1

while True:	
	data = ""
	for i in range(0,5):
		data += chr(bus.read_byte(address))
	print data
	time.sleep(1)
