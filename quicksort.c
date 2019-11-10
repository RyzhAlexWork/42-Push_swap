
#include "push_swap.h"

int		ft_checksort(t_list *l_num)
{
	while (l_num->prev != NULL && (l_num->value > (l_num->prev)->value))
		l_num = l_num->prev;
	if (l_num->prev == NULL)
		exit (0);
	else
		return (1);
}

void	quicksort2(int *array, int *left, int *right, int pivot)
{
	while (*left < *right) // пока границы не сомкнутся
	{
		while ((array[*right] >= pivot) && (*left < *right))
			(*right)--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (*left != *right) // если границы не сомкнулись
		{
			array[*left] = array[*right]; // перемещаем элемент [right] на место разрешающего
			(*left)++; // сдвигаем левую границу вправо
		}
		while ((array[*left] <= pivot) && (*left < *right))
			(*left)++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (*left != *right) // если границы не сомкнулись
		{
			array[*right] = array[*left]; // перемещаем элемент [left] на место [right]
			(*right)--; // сдвигаем правую границу влево
		}
	}
}

void	quicksort(int *array, int left, int right)
{
	int	pivot; // разрешающий элемент
	int	l_hold; //левая граница
	int	r_hold; // правая граница

	l_hold = left;
	r_hold = right;
	pivot = array[left];
	quicksort2(array, &left, &right, pivot);
	array[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quicksort(array, left, pivot - 1);
	if (right > pivot)
		quicksort(array, pivot + 1, right);
}
