#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (ft_validation(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (0);
}