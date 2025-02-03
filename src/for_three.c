/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:49:43 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/13 11:10:39 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_for_three_high_first(t_stack **stack_a, t_stack *lastnode)
{
	if ((*stack_a)->next->nbr > lastnode->nbr)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
		return ;
	}
	else
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		return ;
	}
}
void	ft_for_three(t_stack **stack_a, t_stack *lastnode)
{
		if (ft_stacksize(*stack_a) != 3)
			return;
		if (ft_good_order(*stack_a) == 1)
			return ;
		if ((*stack_a)->nbr > (*stack_a)->next->nbr && ((*stack_a)->nbr < lastnode->nbr))
		{
			swap_a(stack_a);
			return ;
		}
		if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr > lastnode->nbr)
		{
			reverse_rotate_a(stack_a);
			return ;
		}
		if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > lastnode->nbr)
		{
			ft_for_three_high_first(stack_a, lastnode);
			return ;
		}
		if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr < lastnode->nbr)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
			return ;
		}
}
