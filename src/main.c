/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:55:42 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/22 15:20:58 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	ft_tab_in_stack(t_stack **stack_a, char **tab)
{
	int		i;

	i = 0;
	if (ft_atol(tab[i]) == -2147483650)
	{
		ft_freeall(tab, ft_countarg(tab));
		exit(EXIT_FAILURE);
	}
	*stack_a = ft_newstack((int)ft_atol(tab[i]));
	if(!*stack_a )
	{
		ft_freeall(tab, ft_countarg(tab));
		ft_clearstack(stack_a);
		exit(EXIT_FAILURE);
	}
	while (tab[++i] != NULL)
	{
		if (ft_atol(tab[i]) == -2147483650)
		{
			ft_freeall(tab, ft_countarg(tab));
			ft_clearstack(stack_a);
			exit(EXIT_FAILURE);
		}
		ft_stackadd_back(stack_a, ft_newstack((int)ft_atol(tab[i])));
		if (!*stack_a)
		{
			ft_freeall(tab, ft_countarg(tab));
			ft_clearstack(stack_a);
			exit(EXIT_FAILURE);
		}
	}
	ft_freeall(tab, ft_countarg(tab));
}

int	main(int argc, char **argv)
{
	char	*strfullargv;
	char	**tab;
	t_stack	*stack_a;

	if (argc <2)
		return (1);
	stack_a = NULL;
	strfullargv = ft_strfullargv(argc, argv);
	if (!strfullargv)
		exit(EXIT_FAILURE);
	tab = ft_split(strfullargv, ' ');
	if (!tab)
		exit(EXIT_FAILURE);
	free(strfullargv);
	ft_tab_in_stack(&stack_a, tab);
	if (ft_nodouble(stack_a) == 0)
	{
		ft_clearstack(&stack_a);
		exit(EXIT_FAILURE);
	}
	ft_go_pushswap(&stack_a);
	ft_clearstack(&stack_a);
	exit(EXIT_SUCCESS);
}
