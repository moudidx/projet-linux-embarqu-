import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11,GPIO.OUT)
n=0
while(n<10):
	GPIO.output(11,1)
	time.sleep(0.5)
	GPIO.output(11,0)
	time.sleep(0.5)
	n=n+1
print("finish")	

