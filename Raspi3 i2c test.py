import smbus
import time

# for RPI version 1, use .bus = smbus.SMBus(0).
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeNumber(value):
	bus.write_byte(address, value)
	return -1

def readNumber():
	number = bus.read_byte(address)
	return number

while True:
	
	writeNumber(var)
	print "RPI: Hi Arduino, I sent you ", var
	# sleep one second
	time.sleep(1)

	number = readNumber()
	print "Arduino: Hey RPI, I received a digit ", number
  #	time.sleep(1)
	print
