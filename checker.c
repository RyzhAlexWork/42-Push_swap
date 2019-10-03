
#include "push_swap.h"
#include <stdio.h>

int main(void)
{
	char *line;
	int fd;
	int i;

	i = 2;
	printf("%d\n", ft_atoi("       ", &i));
	fd = open("../author", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
