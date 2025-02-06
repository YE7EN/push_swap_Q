/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:04:08 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 13:00:53 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	tmp2 = ft_stacklast(*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_printf("ra\n");
	return ;
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stacksize(*stack_b) < 2)
		return ;
	tmp = *stack_b;
	tmp2 = ft_stacklast(*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_printf("rb\n");
	return ;
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = ft_stacklast(*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	tmp = *stack_b;
	tmp2 = ft_stacklast(*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_printf("rr\n");
	return ;
}
