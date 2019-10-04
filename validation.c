
#include "push_swap.h"
#include <stdio.h>

int 	*ft_checkrep(int *array, int i) // Проверка на повторы
{
	int j;

	j = 0;
	while (j + 2 < i && array[j] != array[j + 1])
		j++;
	if (i > 1 && array[j] == array[j + 1])
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int 	ft_checkzero(int argc, char **argv, int i, int j) // Проверяет, 0 это 0 или ошибка
{
	while (j <= i && ft_isdigit(argv[argc][j]) != 1)
		j++;
	while (argv[argc][j] == '0' && ft_isdigit(argv[argc][j + 1]) == 1)
		j++;
	if (argv[argc][j] != '0')
		return (-1);
	return (0);
}

int		ft_getnum(int argc, char **argv, t_list **l_num) // Создает список всех чисел
{
	int i;
	int j;
	int num;

	i = 0;
	while (argv[argc][i] != '\0')
	{
		j = i;
		while (argv[argc][i] != '\0' && ft_isdigit(argv[argc][i]) != 1) // Проверка, есть ли числа дальше
			i++;
		if (argv[argc][i] == '\0')
			return (0);
		i = j;
		num = ft_atoi(argv[argc], &i);
		if (num == 0 && (ft_checkzero(argc, argv, i, j)) == -1) // Проверка, число ошибочное или 0
			return (-1);
		if (((*l_num) = ft_new_list(num, l_num)) == NULL) // Создаём лист под число
			return (-1);
	}
}

int		ft_validation2(int argc, char **argv)
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

int		ft_validation(int argc, char **argv, t_list **l_num)
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
			if (ft_getnum(i, argv, l_num) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
