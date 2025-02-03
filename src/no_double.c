/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:45:21 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/14 13:01:10 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nodouble(t_stack *stack_a)
{
	t_stack *tmp;

	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (tmp->nbr == stack_a->nbr)
			{
				ft_puterror_fd("Error\n", YELLOW);
				//ft_puterror_fd(": double has been found.\n", YELLOW);
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
