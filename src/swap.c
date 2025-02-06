/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:23:29 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 11:09:02 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	tmp2 = tmp2->next;
	tmp->next = tmp->next->next;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_b;
	tmp2 = *stack_b;
	tmp2 = tmp2->next;
	tmp->next = tmp->next->next;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	ft_printf("sb\n");
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	tmp2 = tmp2->next;
	tmp->next = tmp->next->next;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	tmp = *stack_b;
	tmp2 = *stack_b;
	tmp2 = tmp2->next;
	tmp->next = tmp->next->next;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	ft_printf("ss\n");
}
