#include "minitalk.h"

int main (int ac, char **av)
{
	while(1)
	{
		fprintf(stderr, ".");
		if (usleep(999999))
			if (errno != EINTR)
				exit(0);
	}
}