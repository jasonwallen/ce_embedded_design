#include <fcntl.h> 
#include <unistd.h> 
#include <iostream> 
#include <sys/mman.h> 
#include <stdio.h>

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

/** 
 * Write a 4-byte value at the specified general-purpose I/O location. 
 * 
 * @param ptr
Base address returned by 'mmap'. 
 * @parem offset
Offset where device is mapped. 
 * @param value
Value to be written. 
 */ 
void RegisterWrite(char *ptr, int offset, int value) 
{ 
	* (int *) (ptr + offset) = value; 
} 

/** 
 * Read a 4-byte value from the specified general-purpose I/O location. 
 * 
 * @param ptr
Base address returned by 'mmap'. 
 * @param offset
Offset where device is mapped. 
 * @return
Value read. 
 */ 
int RegisterRead(char *ptr, int offset) 
{ 
	return * (int *) (ptr + offset); 
} 

/** 
 * Initialize general-purpose I/O 
 *  - Opens access to physical memory /dev/mem 
 *  - Maps memory at offset 'gpio_address' into virtual address space 
 * 
 * @param  fd
 *
File descriptor passed by reference, where the result 
 *
of function 'open' will be stored. 
 *
 * @return
 *
Address to virtual memory which is mapped to physical, 
 *
or MAP_FAILED on error. 
 */ 
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

/** 
 * Close general-purpose I/O. 
 * 
 * @param ptr
Virtual address where I/O was mapped. 
 * @param fd
File descriptor previously returned by 'open'. 
 */ 
void Finalize(char *ptr, int fd) 
{ 
	munmap(ptr, gpio_size); 
	close(fd); 
} 

/** 
 * Show lower 8 bits of integer value on LEDs 
 * 
 * @param ptr
Base address of I/O 
 * @param value
Value to show on LEDs 
 */ 
void SetLedNumber(char *ptr, int value) 
{ 
	RegisterWrite(ptr, gpio_led1_offset, value % 2); 
	RegisterWrite(ptr, gpio_led2_offset, (value / 2) % 2); 
	RegisterWrite(ptr, gpio_led3_offset, (value / 4) % 2); 
	RegisterWrite(ptr, gpio_led4_offset, (value / 8) % 2); 
	RegisterWrite(ptr, gpio_led5_offset, (value / 16) % 2); 
	RegisterWrite(ptr, gpio_led6_offset, (value / 32) % 2); 
	RegisterWrite(ptr, gpio_led7_offset, (value / 64) % 2); 
	RegisterWrite(ptr, gpio_led8_offset, (value / 128) % 2); 
}

int PushButtonGet(char *ptr){
	for(int i = 0; i < 5; i++)
	{
		if(RegisterRead(ptr, 0x16C + (4*i)))
			return i+1;
	}
	return 0;	
}

/** Set the state of the LED with the given index.
 *
 * @param ptr		Base address for general-purpose I/O
 * @param led_index	LED index between 0 and 7
 * @param state 	Turn on (1) or off (0)
 */
void SetLedState(char *ptr, int led_index, int state){
	
	int ledOffset;
	switch(led_index)
	{
		case 0:
			ledOffset = gpio_led1_offset;
			break;
		case 1:
			ledOffset = gpio_led2_offset;
			break;
		case 2:
			ledOffset = gpio_led3_offset;
			break;
		case 3:
			ledOffset = gpio_led4_offset;
			break;
		case 4:
			ledOffset = gpio_led5_offset;
			break;
		case 5:
			ledOffset = gpio_led6_offset;
			break;
		case 6:
			ledOffset = gpio_led7_offset;
			break;
		case 7:
			ledOffset = gpio_led8_offset;
			break;
		default:
			break;
	}

	RegisterWrite(ptr, ledOffset, state);
}

int main() 
{ 
	// Initialize 
	int fd; 
	char *ptr = Initialize(&fd); 
	
	// Check error 
	if (ptr == MAP_FAILED) 
	{ 
		perror("Mapping I/O memory failed - Did you run with 'sudo'?\n"); 
		return -1; 
	}
	
	int counter = 0;
	for(int i = 0; i < 8; i++)
	{
		int offset;
		switch(i){
			
			case 0:
				offset = gpio_sw1_offset;
				break;
			case 1:
				offset = gpio_sw2_offset;
				break;
			case 2:
				offset = gpio_sw3_offset;
				break;
			case 3:
				offset = gpio_sw4_offset;
				break;
			case 4:
				offset = gpio_sw5_offset;
				break;
			case 5:
				offset = gpio_sw6_offset;
				break;
			case 6:
				offset = gpio_sw7_offset;
				break;
			case 7:
				offset = gpio_sw8_offset;
				break;
			default:
				break;
		}
		counter += RegisterRead(ptr, offset) << i;
	} 
	int initialCount = counter;
	
	int currentState = 0;
	int previousState = 0;	
	while(true)
	{
		
		SetLedNumber(ptr, counter);
			
		currentState = PushButtonGet(ptr);
					
		if(currentState != previousState)
		{
			switch(currentState)
			{
				case 1:
					counter = counter << 1;
					break;
				case 2:
					counter = counter >> 1;
					break;
				case 3:
					counter++;
					break;
				case 4:
					counter--;
					break;
				case 5:
					counter = initialCount;
					break;
				default:
					break;
			}
			
			previousState = currentState;
		}
	}

	// Done 
	Finalize(ptr, fd); 
	return 0; 
}

