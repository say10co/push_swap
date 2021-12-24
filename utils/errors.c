/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:48:53 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/24 15:05:56 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (!s1)
		return (1);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (s1[index] - s2[index]);
	}
	return (s1[index] - s2[index]);
}

int	all_ints(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!j && args[i][j] == '-' && ft_isdigit(args[i][j + 1]))
				j++;
			if (!(ft_isdigit(args[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_(int sign, int len, char *s)
{
	if (len > 10)
		return (0);
	if (sign && len == 10 && ft_strcmp(s, "2147483647") > 0)
		return (0);
	if (!sign && len == 10 && ft_strcmp(s, "2147483648") > 0)
		return (0);
	return (1);
}

int	check_limits(char **args)
{
	int		len;
	int		i;
	int		sign;
	int		j;

	i = 0;
	while (args[i])
	{
		sign = 1;
		j = 0;
		len = ft_strlen(args[i]);
		if (args[i][0] == '-' || args[i][0] == '+')
		{
			if (args[i][0] == '-')
				sign = 0;
			len--;
			j++;
		}
		if (!check_(sign, len, &args[i][j]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char ***args, int *ac)
{	
	if (*ac == 2)
	{
		*args = ft_split((*args)[1], ' ');
		if (!*args)
		{
			free(*args);
			return (0);
		}
		*ac = check_double_count(*args, 1) + 1;
	}
	else
		*args += 1;
	if (!*args[0])
		return (0);
	if (all_ints(*args) && check_limits(*args) && check_double_count(*args, 1))
		return (1);
	write(1, "Error\n", 6);
	return (0);
}
