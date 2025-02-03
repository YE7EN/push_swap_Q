/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:05:27 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/31 09:43:46 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bestmove_for_five(t_stack **stack_a, t_stack **stack_b, int size)
{
		while (size > 3)
	{
		if ((*stack_a)->nbr == ft_find_max(*stack_a) || (*stack_a)->nbr == ft_find_max(*stack_a))
		{
			push_b(stack_a, stack_b);
			size--;
		}
		else if (ft_stacklast(*stack_a)->nbr == ft_find_max(*stack_a) || ft_stacklast(*stack_a)->nbr == ft_find_min(*stack_a))
		{
			reverse_rotate_a(stack_a);
			push_b(stack_a, stack_b);
			size --;
		}
		else
			rotate_a(stack_a);
	}
}
void	ft_for_five(t_stack	**stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	ft_bestmove_for_five(stack_a, stack_b, size);
	ft_for_three(stack_a, ft_stacklast(*stack_a));
	size = ft_stacksize(*stack_b);
	while (size > 0)
	{
		if ((*stack_b)->nbr == ft_find_max(*stack_b) && (*stack_b)->nbr > ft_find_max(*stack_b))
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else
		{
			push_a(stack_a, stack_b);
		}
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		{
			rotate_a(stack_a);
		}
		size--;
	}
	if ((*stack_a)->nbr == ft_find_max(*stack_a))
	{
		rotate_a(stack_a);
	}
	return ;

}