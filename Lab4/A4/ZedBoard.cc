#include "ZedBoard.h"

ZedBoard::ZedBoard()
{
	fd = open( "/dev/mem", O_RDWR);
	ptr = (char *) mmap(
			NULL, 
			gpio_size, 
			PROT_READ | PROT_WRITE, 
			MAP_SHARED, 
			fd, 
			gpio_address);

}

ZedBoard::~ZedBoard()
{
	munmap(ptr, gpio_size);
	close(fd);
}

int ZedBoard::CheckMap()
{
	if(this->ptr == MAP_FAILED)
	{
		perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");
		return -1;
	}
	else return 1;
}

void ZedBoard::RegisterWrite(int offset, int value)
{
	* (int *) (this->ptr + offset) = value;
}

int ZedBoard::RegisterRead(int offset)
{
	return * (int *) (this->ptr + offset);
}
