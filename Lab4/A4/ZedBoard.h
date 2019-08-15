#ifndef ZEDBOARD_H
#define ZEDBOARD_H

#include <fcntl.h> 
#include <unistd.h> 
#include <iostream> 
#include <sys/mman.h> 
#include <stdio.h>

class ZedBoard
{
	int fd;
	char *ptr;

	// Physical base address of GPIO 
	const unsigned gpio_address = 0x400d0000; 
	
	// Length of memory-mapped IO window 
	const unsigned gpio_size = 0xff; 

public:
	
	//Constructor
	ZedBoard();

	//Destructor
	~ZedBoard();
	
	int CheckMap();

	void RegisterWrite(int offset, int value);

	int RegisterRead(int offset);
	

};



#endif
