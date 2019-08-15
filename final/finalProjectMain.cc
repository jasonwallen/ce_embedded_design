#include <fcntl.h> 
#include <unistd.h> 
#include <iostream> 
#include <sys/mman.h>
#include "RobotControl.h"

// Physical base address of GPIO  
const unsigned gpio_address = 0x400d0000;
 
// Length of memory-mapped IO window 
const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C;  // Offset for LED1 
const int gpio_led2_offset = 0x130;  // Offset for LED2 
const int gpio_led3_offset = 0x134;  // Offset for LED3 
const int gpio_led4_offset = 0x138;  // Offset for LED4 
const int gpio_led5_offset = 0x13C;  // Offset for LED5 
const int gpio_led6_offset = 0x140;  // Offset for LED6 
const int gpio_led7_offset = 0x144;  // Offset for LED7 
const int gpio_led8_offset = 0x148;  // Offset for LED8 

const int gpio_sw1_offset = 0x14C;  // Offset for Switch 1 
const int gpio_sw2_offset = 0x150;  // Offset for Switch 2 
const int gpio_sw3_offset = 0x154;  // Offset for Switch 3 
const int gpio_sw4_offset = 0x158;  // Offset for Switch 4 
const int gpio_sw5_offset = 0x15C;  // Offset for Switch 5 
const int gpio_sw6_offset = 0x160;  // Offset for Switch 6 
const int gpio_sw7_offset = 0x164;  // Offset for Switch 7 
const int gpio_sw8_offset = 0x168;  // Offset for Switch 8 

const int gpio_pbtnl_offset = 0x16C;  // Offset for left push button 
const int gpio_pbtnr_offset = 0x170;  // Offset for right push button 
const int gpio_pbtnu_offset = 0x174;  // Offset for up push button 
const int gpio_pbtnd_offset = 0x178;  // Offset for down push button 
const int gpio_pbtnc_offset = 0x17C;  // Offset for center push button 

//Writes values to a certain offset on the map
void RegisterWrite(char *ptr, unsigned offset, unsigned value) 
{ 
	* (volatile unsigned *) (ptr + offset) = value; 
} 

//Reads values from a certain place on the map
int RegisterRead(char *ptr, int offset) 
{ 
	return * (int *) (ptr + offset); 
} 

//Initializes the map
char *Initialize(int *fd) 
{ 
	*fd = open( "/dev/mem", O_RDWR); 
		return (char *) mmap( 
			NULL, 
			gpio_size, 
			PROT_READ | PROT_WRITE, 
			MAP_SHARED, 
			*fd, 
			gpio_address); 
} 

//Closes the map
void Finalize(char *ptr, int fd) 
{ 
	munmap(ptr, gpio_size); 
	close(fd); 
} 


int main() 
{ 
	// Initialize 
	int fd; 
	char *ptr = Initialize(&fd);
  	RobotControl base(13);
  	RobotControl bicep(10);
  	RobotControl elbow(11);
  	RobotControl wrist(12);
  	RobotControl gripper(0);

	std::cout << "The program has started\n";

	// Check error 
	if (ptr == (void *) -1) 
	{ 
		std::cerr << ("Mapping I/O memory failed - Did you run with 'sudo'?\n"); 
		return -1; 
	}
	
  //SWITCHES, SPEED
	//Wait for flipped switch
	int speed_min = 10;
	int speed = 0;
	std::cout << "Please flip a switch to determine speed\n";

	//Do nothing while no switch is flipped		
	while(RegisterRead(ptr, gpio_sw1_offset) == 0 && RegisterRead(ptr, gpio_sw2_offset) == 0 && RegisterRead(ptr, gpio_sw3_offset) == 0 && RegisterRead(ptr, gpio_sw4_offset) == 0 && RegisterRead(ptr, gpio_sw5_offset) == 0 && RegisterRead(ptr, gpio_sw6_offset) == 0 && RegisterRead(ptr, gpio_sw7_offset) == 0 && RegisterRead(ptr, gpio_sw8_offset) == 0){}
	
	//Set the speed and the LED
	std::cout << "Switch flipped\n";	
	if(RegisterRead(ptr, gpio_sw1_offset) == 1)
	{
		speed = 1;
		RegisterWrite(ptr, gpio_led1_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min);
		std::cout << "Speed is level " << speed << "\n";
	}
	else if(RegisterRead(ptr, gpio_sw2_offset))
	{
		speed = 2;
		RegisterWrite(ptr, gpio_led2_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 2);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw3_offset))
	{
		speed = 3;
		RegisterWrite(ptr, gpio_led3_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 4);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw4_offset))
	{
		speed = 4;
		RegisterWrite(ptr, gpio_led4_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 6);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw5_offset))
	{
		speed = 5;
		RegisterWrite(ptr, gpio_led5_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 8);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw6_offset))
	{
		speed = 6;
		RegisterWrite(ptr, gpio_led6_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 10);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw7_offset))
	{
		speed = 7;
		RegisterWrite(ptr, gpio_led7_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 12);
		std::cout << "Speed is level " << speed << '\n';
	}
	else if(RegisterRead(ptr, gpio_sw8_offset))
	{
		speed = 8;
		RegisterWrite(ptr, gpio_led8_offset, 255);
		//RegisterWrite(ptr, 0x100, speed_min + 14);
		std::cout << "Speed is level " << speed << '\n';
	}
	//BUTTONS, MOVEMENTS
	std::cout << "Please input moves (<= 100). When complete, press the center button.\n";	
	
	int moves[100];
	int i = 0;

	while(i < 100){
		//std::cout << "i: " << i << "\n";
		if(RegisterRead(ptr, gpio_pbtnl_offset) == 1)
		{
			moves[i] = 1;
			i++;
			sleep(.5);
		}
		else if (RegisterRead(ptr, gpio_pbtnr_offset) == 1)
		{
			moves[i] = 2;
			i++;
			sleep(.5);
		}
		else if (RegisterRead(ptr, gpio_pbtnu_offset) == 1)
		{
			moves[i] = 3;
			i++;
			sleep(.5);
		}
		else if (RegisterRead(ptr, gpio_pbtnd_offset) == 1)
		{
			moves[i] = 4;
			i++;
			sleep(.5);
		}
		else if(RegisterRead(ptr, gpio_pbtnc_offset) == 1)
		{
			for(int k = i; k < 100; k++)
			{
				moves[k] = 0;
			}			
			break;
		}
	}
		
	std::cout << "Moves are registered \n";
	
	// needed? int bedtime = 160/speed + 1;	
	for(int i = 0; i < 5; i++)
	{
	std::cout << moves[i] << ", ";	
    	if(moves[i] == 1)
    	{
      		base.GenerateLeftPWM(160, speed);
      		bicep.GenerateLeftPWM(45, speed);
      		elbow.GenerateLeftPWM(135, speed);
      		wrist.GenerateLeftPWM(160, speed);
      		gripper.GenerateLeftPWM(20, speed);
    	}
    	else if(moves[i] == 2)
    	{
      		base.GenerateRightPWM(20, speed);
      		bicep.GenerateRightPWM(135, speed);
      		elbow.GenerateRightPWM(45, speed);
      		wrist.GenerateRightPWM(20, speed);
      		gripper.GenerateRightPWM(160, speed);
    	}
    	else if(moves[i] == 3)
    	{
      		base.GenerateUpPWM(90, speed);
      		bicep.GenerateUpPWM(90, speed);
      		elbow.GenerateUpPWM(90, speed);
      		wrist.GenerateUpPWM(90, speed);
      		gripper.GenerateUpPWM(90, speed);
    	}
    	else if(moves[i] == 4)
   	 {
      		base.GenerateDownPWM(90, speed);
      		bicep.GenerateDownPWM(45, speed);
      		elbow.GenerateDownPWM(45, speed);
      		wrist.GenerateDownPWM(45, speed);
      		gripper.GenerateDownPWM(45, speed);
    	}
    	else if(moves[i] == 0)
    		break;
    	else std::cout<< "Something went wrong! Invalid move option.\n";
		std::cout << "Move " << i << " submitted\n";
		// needed? sleep(bedtime);  
	}

	std::cout << "\nProgram end\n";
	
	//Turn off all LEDs
	RegisterWrite(ptr, gpio_led1_offset, 0);
	RegisterWrite(ptr, gpio_led2_offset, 0);
	RegisterWrite(ptr, gpio_led3_offset, 0);
	RegisterWrite(ptr, gpio_led4_offset, 0);
	RegisterWrite(ptr, gpio_led5_offset, 0);
	RegisterWrite(ptr, gpio_led6_offset, 0);
	RegisterWrite(ptr, gpio_led7_offset, 0);
	RegisterWrite(ptr, gpio_led8_offset, 0);

	// Done 
	Finalize(ptr, fd); 
	return 0; 
}
