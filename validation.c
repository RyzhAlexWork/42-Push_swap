#include "push_swap.h"

int ft_getnum(int argc, char **argv)
{
	int i;
	int j;
	int num;

	i = 0;
	while (argv[argc][i] != '\0')
	{
		j = i;
		num = ft_atoi(argv[argc] + i, &i);
		if (num == 0)
		{
			while (j <= i)
			{
				
			}
		}
	}
}

int ft_validation2(int argc, char **argv)
{
	int i;

	i = 0;
	while (ft_isdigit(argv[argc][i]) != 1 && argv[argc][i] != '\0') // Проверка на наличие цифр
		i++;
	if (argv[argc][i] == '\0')
		return (-1);
	i = 0;
	while (ft_isdigit(argv[argc][i]) || ft_isspace(argv[argc][i]) || // Проверка на отсутствие посторонних знаков
	argv[argc][i] == '-' || argv[argc][i] == '+')
		i++;
	if (argv[argc][i] != '\0')
		return (-1);
	return (0);
}

int ft_validation(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		return (-1);
	else
	{
		while (i < argc)
		{
			if (ft_validation2(i, argv) == -1)
				return (-1);
			ft_getnum(i, argv);
			i++;
		}
	}
	return (0);
}
