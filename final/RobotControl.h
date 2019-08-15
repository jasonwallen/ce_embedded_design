#ifndef ROBOTCONTROL_H 
#define ROBOTCONTROL_H

class RobotControl 
{ 
	// File descriptor 
	int fd2; 

public: 
	/** 
	 * Class constructor. 
	 * 
	 * @param number 
	 *
	Port number for GPIO. 
	 */ 
	RobotControl(int number); 

	/** 
	 * Class destructor. 
	 */ 
	~RobotControl(); 

	/** 
	 * Generate a PWM signal, blocking the caller while the signal is being 
	 * generated. 
	 * 
	 * @param period 
	 *
	PWM period in microseconds. 
	 * 
	 * @param pulse 
	 *
	Duration of the pulse in microseconds. 
	 * 
	 * @param num_periods 
	 *
	Number of periods to generate. 
	 */ 	
  void GenerateUpPWM(int angle, int speed);
  void GenerateDownPWM(int angle, int speed);
 	void GenerateRightPWM(int angle, int speed);
  void GenerateLeftPWM(int angle, int speed); 
}; 

#endif
