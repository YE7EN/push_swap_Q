/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:21:40 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:12 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = ft_stacklast(*stack_a);
	tmp->next = *stack_a;
	while ((*stack_a)->next != tmp)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = NULL;
	(*stack_a) = tmp;
	ft_printf("rra\n");
	return ;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*stack_b);
	tmp->next = *stack_b;
	while ((*stack_b)->next != tmp)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = NULL;
	(*stack_b) = tmp;
	ft_printf("rrb\n");
	return ;
}

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = ft_stacklast(*stack_a);
	tmp->next = *stack_a;
	while ((*stack_a)->next != tmp)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = NULL;
	(*stack_a) = tmp;
	tmp = ft_stacklast(*stack_b);
	tmp->next = *stack_b;
	while ((*stack_b)->next != tmp)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = NULL;
	(*stack_b) = tmp;
	ft_printf("rrr\n");
	return ;
}
