/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:59:45 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 12:56:31 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <sys/types.h>
#include <sys/wait.h>

void	ft_special_case(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	t_stack	*lastnode;

	stack_b = NULL;
	lastnode = ft_stacklast(*stack_a);
	if (size == 2)
	{
		swap_a(stack_a);
		return ;
	}
	if (size == 3)
	{
		ft_for_three(stack_a, lastnode);
		return ;
	}
	if (size == 4 || size == 5 || size == 6)
	{
		ft_for_five(stack_a, &stack_b);
		return ;
	}
}
