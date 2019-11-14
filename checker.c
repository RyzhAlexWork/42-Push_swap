
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list	*l_num;
	int		fd;
	int		i;

	i = 2;
	if (ft_validation(argc, argv, &l_num) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	fd = open(1, O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
