import RPi.GPIO	as GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)
p= GPIO.PWM(12,0.5) 
p.start(1)
p.ChangeFrequency(0.3)
p.ChangeDutyCycle(3.0)
p.stop()

