/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:42:22 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 12:55:51 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printstack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	sizeb;

	printf("/------------------/\nStack_a :\n");
	size = ft_stacksize(stack_a);
	if (size >= 0)
	{
		while (size > 0)
		{
			printf("     nbr:%ld         bestmove_value: %d\n", stack_a->nbr, stack_a->bestmove);
			stack_a = stack_a->next;
			size --;
		}
	}
	printf("/-------------------/\n\n");
	printf("/-------------------/\nStack_b :\n");
	sizeb = ft_stacksize(stack_b);
	if (sizeb >= 1)
	{
		while (sizeb > 0)
		{
			printf("     %ld         bestmove_value: %d\n\n", stack_b->nbr, stack_b->bestmove);
			stack_b = stack_b->next;
			sizeb --;
		}
	}
	else
		printf("nothing\n");
	printf("/-------------------/\n\n");
}
