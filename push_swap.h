
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "GetNextLine/get_next_line.h"

typedef struct		s_list
{
	int				value;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		ft_validation(int argc, char **argv, t_list **l_num);
void	quicksort(int *numbers, int left, int right);
int		*ft_checkrep(int *array, int i);
t_list	*ft_new_list(int num, t_list **l_num);
void	ft_clear_list(t_list **l_num);

#endif
