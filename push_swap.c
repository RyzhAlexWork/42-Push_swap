#include "push_swap.h"
#include <stdio.h>

int main() {
	char *line;

	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
    return (0);
}