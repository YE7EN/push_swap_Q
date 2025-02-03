/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:09:54 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/08 10:21:21 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
// void	ft_freeall(char **tab, int i)
// {
// 	while (i >= 0)
// 	{
// 		printf("\nfree : %d\n", i);
// 		free(tab[i]);
// 		i--;
// 	}
// 	free(tab);
// 	return;
// }

// int	ft_countarg(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 		i++;
// 	return (i);
// }

// int	main(int argc, char **argv)
// {
// 	char	*strfullargv = NULL;
// 	char	**tab;
// 	int		i;
// 	int		k;
// 	t_stack	*stack_a;
// 	t_stack	*tmp;

// 	k = 0;
// 	i = 0;
// 	stack_a = NULL;
// 	strfullargv = ft_strfullargv(argc, argv);
// 	if (!strfullargv)
// 		return (1);
// 	tab = ft_split(strfullargv, ' ');
// 	if (!tab)
// 		return (1);
// 	while (tab[i] != NULL)
// 	{
// 		if (i == 0)
// 		{
// 			stack_a = ft_newstack(ft_atol(tab[i]));
// 			if (!stack_a || stack_a->nbr == NULL)
// 			{
// 				printf("\nsalut cousin\n");
// 				free(strfullargv);
// 				ft_freeall(tab, ft_countarg(tab));
// 				ft_clearstack(&stack_a);
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		else
// 		{
// 			ft_stackadd_back(&stack_a, ft_newstack(ft_atol(tab[i])));
// 			if (!stack_a)
// 			{
// 				free(strfullargv);
// 				ft_freeall(tab, ft_countarg(tab) - i);
// 				ft_clearstack(&stack_a);
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	tmp = stack_a;
// 	if (ft_nodouble(tmp) == 1)
// 		printf("\nno double : ok\n");
// 	else if (ft_nodouble(tmp) == 0)
// 		printf("\nno double : ko\n");
// 	while (stack_a)
// 	{
// 		printf("- %d : %ld\n", k, (long)stack_a->nbr);
// 		stack_a = stack_a->next;
// 		k++;
// 	}
// 	stack_a = tmp;
// 	swap_a(&stack_a);
// 	while (stack_a)
// 	{
// 		printf("- %d : %ld\n", k, (long)(stack_a->nbr));
// 		stack_a = stack_a->next;
// 		k++;
// 	}
// 	ft_printf("- %s-\n", strfullargv);
// 	free(strfullargv);
// 	ft_clearstack(&tmp);
// 	return (0);
// }
// long	ft_create_number(char *str, long nbr, int sign)
// {
// 	while (*str)
// 	{
// 		if (*str < '0' || *str > '9')
// 		{
// 			ft_puterror_fd("Error\n: not a digit\n", YELLOW);

// 			return (-2147483650);
// 		}
// 		nbr = nbr * 10 + (*str - 48);
// 		str++;
// 	}
// 	nbr *= sign;
// 	if (nbr > 2147483647 || nbr < -2147483648)
// 	{
// 		ft_puterror_fd("Error\n: int_overflow\n", YELLOW);
// 		return (-2147483650);
// 	}
// 	return ((int) nbr);
// }

// long	ft_atol(char *str)
// {
// 	int		i;
// 	long	nbr;
// 	long	sign;

// 	i = 0;
// 	nbr = 0;
// 	sign = 1;
// 	if ((*str < '0' && *str > '9'))
// 	{
// 		ft_atol_not_digit_error();
// 		return (-2147483650);
// 	}
// 	else if (*str == '-' || *str == '+')
// 	{
// 		if (*(str + 1) == '\0')
// 		{
// 			ft_puterror_fd("Error\n: a sign without value\n", YELLOW);
// 			return (-2147483650);
// 		}
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (*str == '0')
// 		str++;
// 	while (str[i])
// 	{
// 		if (i > 12)
// 		{
// 			ft_atol_overflow_error();
// 			return (-2147483650);
// 		}
// 		i++;
// 	}
// 	nbr = ft_create_number(str, nbr, sign);
// 	return ((int) nbr);
// }

// int	main(void)
// {
// 	printf("%d", ft_atol(-20))
// }