/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:27:37 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:27:39 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate_r(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate_a(stack_a);
	ft_revrotate_b(stack_b);
}
