/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:22:59 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/06 12:58:52 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_digit_in_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkarg(char *argv)
{
	while (*argv)
	{
		if (*argv > 13 && *argv != ' ')
			return (0);
		argv++;
	}
	return (1);
}

char	*ft_concat_argv(char *strfullargv, char *tmp, char *argv)
{
	int	i;

	i = 0;
	if (ft_checkarg(argv) == 1)
	{
		free(strfullargv);
		ft_atol_not_digit_error();
	}
	tmp = ft_strdupandfree(strfullargv);
	if (tmp == NULL)
		return (NULL);
	strfullargv = ft_strjoin(tmp, argv);
	if (strfullargv == NULL)
		return (NULL);
	free(tmp);
	tmp = ft_strdupandfree(strfullargv);
	if (tmp == NULL)
		return (NULL);
	strfullargv = ft_strjoin(tmp, " ");
	if (strfullargv == NULL)
		return (NULL);
	free(tmp);
	return (strfullargv);
}

char	*ft_strfullargv(int argc, char **argv)
{
	int			i;
	static char	*strfullargv = NULL;
	static char	*tmp = NULL;

	i = 1;
	if (argv[i][0] == '\0' || ft_digit_in_argv(argv[i]) == 0)
		ft_badarg_error(NULL);
	strfullargv = ft_clean_malloc(argv[1], ft_strlen(argv[1]));
	if (!strfullargv)
		return (NULL);
	strfullargv = ft_strcpy(strfullargv, argv[1]);
	tmp = ft_strdupandfree(strfullargv);
	if (tmp == NULL)
		return (NULL);
	strfullargv = ft_strjoin(tmp, " ");
	free(tmp);
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || ft_digit_in_argv(argv[i]) == 0)
			ft_badarg_error(strfullargv);
		strfullargv = ft_concat_argv(strfullargv, tmp, argv[i]);
		if (strfullargv == NULL)
			return (NULL);
	}
	return (strfullargv);
}
