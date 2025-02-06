/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:16 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 13:04:19 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_create_number(char *str, long nbr, int sign)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			// ft_puterror_fd("Error\n", YELLOW);
			// write(2, "Erro1\n", 6);
			return (-2147483650);
		}
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	nbr *= sign;
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		// ft_puterror_fd("Error\n", YELLOW);
		write(2, "Error\n", 6);
		return (-2147483650);
	}
	return ((int) nbr);
}

long	ft_ref_atol(char *str, long sign)
{
	if ((*str < '0' && *str > '9'))
	{
		ft_atol_not_digit_error();
		return (-2147483650);
	}
	else if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '\0')
		{
			// ft_puterror_fd("Error\n", YELLOW);
			write(2, "Error\n", 6);
			return (-2147483650);
		}
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	ft_ref_atol(str, sign);
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
