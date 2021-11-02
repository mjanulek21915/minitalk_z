#include "minitalk.h"
// #include <proc_internal.h>

unsigned long long get_size(void)
{
	size_t size;
	unsigned long long value;
	unsigned long long i;

	i = 1;
	size = sizeof(unsigned long);
	size = size * 8;
	while (size--)
	{
		i = i * 2;
	}
	i = i - 1;
	fprintf(stderr, "i : %llu\n", i);
	return (i);
}

int main (int ac, char **av)
{
	unsigned long long size;
	size = get_size();

	fprintf(stderr, "size : %llu\n", size);
	fprintf(stderr, "PID_MAX : %llu\n", PID_MAX);




// 	while(1)
// 	{
// 		fprintf(stderr, ".");
// 		if (usleep(999999))
// 			if (errno != EINTR)
// 				exit(0);
// 	}
}