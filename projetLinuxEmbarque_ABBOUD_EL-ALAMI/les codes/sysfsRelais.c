int fd;
char buf[MAX_BUF]; 
int gpio = 4;

fd = open("/sys/class/gpio/export", O_WRONLY);

sprintf(buf, "%d", gpio); 

write(fd, buf, strlen(buf));

close(fd);
//set direction
sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);

fd = open(buf, O_WRONLY);

//Set out direction
write(fd, "out", 3); 
close(fd);
//set value of gpio

sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);

fd = open(buf, O_WRONLY);

// Set GPIO high status
write(fd, "1", 1); 
// Set GPIO low status 
write(fd, "0", 1); 
close(fd);
//unexport le gpio

fd = open("/sys/class/gpio/unexport", O_WRONLY);

sprintf(buf, "%d", gpio);

write(fd, buf, strlen(buf));

close(fd);

