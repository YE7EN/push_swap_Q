/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:21:14 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 13:01:15 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_max(t_stack	*stack)
{
	int	max_value;

	if (!stack)
		return (0);
	max_value = stack->nbr;
	while (stack)
	{
		if (max_value < stack->nbr)
			max_value = stack->nbr;
		stack = stack->next;
	}
	return (max_value);
}

int	ft_find_min(t_stack	*stack)
{
	int	min_value;

	if (!stack)
		return (0);
	min_value = stack->nbr;
	while (stack)
	{
		if (min_value > stack->nbr)
			min_value = stack->nbr;
		stack = stack->next;
	}
	return (min_value);
}

int	ft_good_order(t_stack	*stack)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->nbr < stack->nbr)
			{
				return (0);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	ft_go_pushswap(t_stack **stack_a)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (ft_good_order(*stack_a) == 1)
		return ;
	if (size <= 5)
	{
		ft_special_case(stack_a, size);
		return ;
	}
	if (size > 5)
	{
		ft_over_five(stack_a, size);
		return ;
	}
	swap_a(stack_a);
	return ;
}
