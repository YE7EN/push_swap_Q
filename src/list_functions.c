/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:12:14 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/30 12:26:54 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return NULL;
	while (stack->next)
		stack = stack->next;
	return (stack);
}


/*
t_stack	*ft_stacklast(t_stack *stack)
{
	int	size;

	size = ft_stacksize(stack);
	while (size - 1 > 0)
	{
		stack = stack->next;
		size --;
	}
	return (stack);
}
*/


int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack *ft_newstack(long number)
{
	t_stack	*newstack;

	newstack = NULL;
	newstack = malloc(sizeof(t_stack));
	if (!newstack)
		return (NULL);
	newstack->nbr = number;
	newstack->next = NULL;
	newstack->bestmove = 0;
	newstack->proxi = 0;
	return (newstack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void ft_clearstack(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = NULL;
	if (!stack_a)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
	stack_a = NULL;
}
