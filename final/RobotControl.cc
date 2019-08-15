#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "RobotControl.h" 

RobotControl::RobotControl(int number) 
{ 
	// GPIO device files will follow the format 
	// /sys/class/gpio/gpio<NR>/value 
	// <NR> has to be replaced with the actual device number passed as an 
	// argument to the class constructor. 
	char device_name[128]; 
	sprintf(device_name, "/sys/class/gpio/gpio%d/value", number); 
	
	// Open special device file and store file descriptor in class member. 

	fd2 = open(device_name, O_WRONLY);

	if (fd2 < 0)
	{
		std::cerr << "Cannot open " << device_name <<
		" - forgot sudo?  \n";
		exit(1);
	}
} 

RobotControl::~RobotControl() 
{ 
	// Close open file descriptor 
	close(fd2); 
} 

void RobotControl::GenerateUpPWM(int angle, int speed) 
{ 
  int period= 20000;
  int pulse = (int)(((angle / 100) + .6) * 1000);
	// Generate num_periods of the PWM signal 
	for (int i = 0; i < 50*speed; i++) 
	{ 
		// Write ASCII character "1" to raise pin to 1, starting the 
		// ON cycle, then wait duration of pulse. 
		write(fd2, "1", 1); 
		usleep(pulse); 
		// Write ASCII character "0" to lower pin to 0, starting the 
		// OFF cycle, then wait the rest of the period time. 
		write(fd2, "0", 1); 
		usleep(period - pulse); 
	}
}

void RobotControl::GenerateDownPWM(int angle, int speed) 
{ 
  int period= 20000;
  int pulse = (int)(((angle / 100) + .6) * 1000);
	// Generate num_periods of the PWM signal 
	for (int i = 0; i < 50*speed; i++) 
	{ 
		// Write ASCII character "1" to raise pin to 1, starting the 
		// ON cycle, then wait duration of pulse. 
		write(fd2, "1", 1); 
		usleep(pulse); 
		// Write ASCII character "0" to lower pin to 0, starting the 
		// OFF cycle, then wait the rest of the period time. 
		write(fd2, "0", 1); 
		usleep(period - pulse); 
	}
}

void RobotControl::GenerateRightPWM(int angle, int speed) 
{ 
  int period= 20000;
  int pulse = (int)(((angle / 100) + .6) * 1000);
	// Generate num_periods of the PWM signal 
	for (int i = 0; i < 50*speed; i++) 
	{ 
		// Write ASCII character "1" to raise pin to 1, starting the 
		// ON cycle, then wait duration of pulse. 
		write(fd2, "1", 1); 
		usleep(pulse); 
		// Write ASCII character "0" to lower pin to 0, starting the 
		// OFF cycle, then wait the rest of the period time. 
		write(fd2, "0", 1); 
		usleep(period - pulse); 
	}
}

void RobotControl::GenerateLeftPWM(int angle, int speed) 
{ 
  int period= 20000;
  int pulse = (int)(((angle / 100) + .6) * 1000);
	// Generate num_periods of the PWM signal 
	for (int i = 0; i < 50*speed; i++) 
	{ 
		// Write ASCII character "1" to raise pin to 1, starting the 
		// ON cycle, then wait duration of pulse. 
		write(fd2, "1", 1); 
		usleep(pulse); 
		// Write ASCII character "0" to lower pin to 0, starting the 
		// OFF cycle, then wait the rest of the period time. 
		write(fd2, "0", 1); 
		usleep(period - pulse); 
	}
}
