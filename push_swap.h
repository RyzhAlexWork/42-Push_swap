
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

typedef struct		s_main
{
	int				mid;
	int				max;
	int				flag;
	int				next;
}					t_main;

int		ft_validation(int argc, char **argv, t_list **l_num);
void	quicksort(int *numbers, int left, int right);
int		*ft_checkrep(int *array, int i);
t_list	*ft_new_list(int num, t_list **l_num);
void	ft_clear_list(t_list **l_num);
int		ft_checksort(t_list *l_num);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_swap_s(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_rotate_r(t_list **stack_a, t_list **stack_b);
void	ft_revrotate_a(t_list **stack_a);
void	ft_revrotate_b(t_list **stack_b);
void	ft_revrotate_r(t_list **stack_a, t_list **stack_b);
t_main	*ft_crmain(int i);
void	ft_algorithm(t_list *stack_a, int i);
void	ft_algorithm2(t_list **stack_a, t_list **stack_b, t_main *l_main, int i);
void	ft_algorithm3(t_list **stack_a, t_list **stack_b, t_main *l_main);
int		ft_algorithm4(t_list **stack_a, t_list **stack_b, t_main *l_main);
int		ft_algorithm5(t_list **stack_a, t_list **stack_b, t_main *l_main);
void	special_case(t_list **stack_a, t_list **stack_b, int i, t_main *l_main);
void	case_for_three(t_list **stack_a, int i);
void	case_for_five(t_list **stack_a, t_list **stack_b, int i, t_main *l_main);
#endif
