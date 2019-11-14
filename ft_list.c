
#include "push_swap.h"

t_list	*ft_new_list(int num, t_list **l_num)
{
	t_list	*l_num_new;

	if ((l_num_new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	l_num_new->value = num;
	l_num_new->order = 0;
	l_num_new->flag = 0;
	l_num_new->next = NULL;
	l_num_new->prev = *l_num;
	if (*l_num)
		(*l_num)->next = l_num_new;
	(*l_num) = NULL;
	return (l_num_new);
}

void	ft_clear_list(t_list **l_num)
{
	t_list	*tmp;

	while ((*l_num)->prev != NULL)
		(*l_num) = (*l_num)->prev;
	while (*l_num != NULL)
	{
		tmp = (*l_num)->next;
		free(*l_num);
		*l_num = tmp;
	}
}
