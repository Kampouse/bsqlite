#include "fcntl.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#define BUFFER 4096


int	ft_find_next(char *str, char next)
{
	int value;
	value = 0;
	while(*str != next && *str != '\0')
	{
		str++;
		value++;
	}
	return (value + 1);
}

int jump_lenght(char *buffer)
{
	//height == lenght - 1 cause you dont want to be in void;
	// wdith  == lenhgt + 1 you want to count '\n;
	// the height can be the lenght...;
	// there also a + 1 of the start or it wont run;
	int jump;
	jump = 0;
	while( *buffer != '\0' && *buffer != '\n')
	{
	buffer++;
	jump++;
	}
if( *(buffer) == '\n')
return (jump + 1);
return 0;
}

int main(void)
{
	char 	*buffer;
	char 	*start;
	int		counter;
	int		size;
	int 	file_size;
	file_size = 0;
	counter= 0;
	size = BUFFER;
	buffer = (char *)malloc(sizeof(char) * file_size + 1);
	int file = open("map",O_RDONLY);

	while(size  == BUFFER)
	{
	file_size += read(file,buffer,BUFFER);
	size = read(file,buffer,BUFFER);
	size++;
	}
	start = buffer;
	printf( "%d\n",jump_lenght(buffer));
	printf( "%d",ft_find_next((buffer + jump_lenght(buffer)),'o'));
}
