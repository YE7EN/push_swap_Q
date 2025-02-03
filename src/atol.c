/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:16 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/14 13:00:37 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


long	ft_create_number(char *str, long nbr, int sign)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_puterror_fd("Error\n", YELLOW);
			//ft_puterror_fd(": not a digit\n", YELLOW);

			return (-2147483650);
		}
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	nbr *= sign;
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		ft_puterror_fd("Error\n", YELLOW);
		//ft_puterror_fd(": int_overflow\n", YELLOW);
		return (-2147483650);
	}
	return ((int) nbr);
}

long	ft_atol(char *str)
{
	int		i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if ((*str < '0' && *str > '9'))
	{
		ft_atol_not_digit_error();
		return (-2147483650);
	}
	else if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '\0')
		{
			ft_puterror_fd("Error\n", YELLOW);
			ft_puterror_fd(": a sign without value\n", YELLOW);
			return (-2147483650);
		}
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[i])
	{
		if (i > 12)
		{
			ft_atol_overflow_error();
			return (-2147483650);
		}
		i++;
	}
	nbr = ft_create_number(str, nbr, sign);
	return (nbr);
}
