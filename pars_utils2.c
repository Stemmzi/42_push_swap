/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:46:53 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/07 00:44:30 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(int argc, char *argv[], int count)
{
	int		c;

	c = 0;
	while (count < argc)
	{
		if (argv[count][c] == '\0')
			return (0);
		if (argv[count][c] == '-' || argv[count][c] == '+')
			if (!ft_isdigit(argv[count][c + 1]))
				return (0);
		c++;
		while (argv[count][c] != '\0' && ft_isdigit(argv[count][c]))
			c++;
		if (argv[count][c] != '\0')
			return (0);
		count++;
		c = 0;
	}
	return (1);
}

static int	has_sign(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11)
		return (0);
	if (len < 11)
		return (1);
	if (str[0] == '-')
	{
		if (len == 11)
		{
			if (ft_strcmp(str, "-2147483648") > 0)
				return (0);
		}
	}
	else if (str[0] == '+')
	{
		if (len == 11)
		{
			if (ft_strcmp(str, "+2147483647") > 0)
				return (0);
		}
	}
	return (1);
}

int	is_int(int argc, char *argv[], int count)
{
	while (count < argc)
	{
		if (argv[count][0] == '-' || argv[count][0] == '+')
		{
			if (has_sign(argv[count]) == 0)
				return (0);
			count++;
		}
		else if (ft_strlen(argv[count]) > 10)
			return (0);
		else if (ft_strlen(argv[count]) == 10)
		{
			if (ft_strcmp(argv[count], "2147483647") > 0)
				return (0);
			count++;
		}
		else
			count++;
	}
	return (1);
}

int	is_unique(int argc, char *argv[], int count)
{
	int	j;
	int	countsign;
	int	jsign;

	while (count < argc - 1)
	{
		j = count + 1;
		while (j < argc)
		{
			countsign = (argv[count][0] == '-' || argv[count][0] == '+');
			jsign = (argv[j][0] == '-' || argv[j][0] == '+');
			if (countsign || jsign)
			{
				if (ft_atoi(argv[count]) == ft_atoi(argv[j]))
					return (0);
			}
			else if (ft_strcmp(argv[count], argv[j]) == 0)
				return (0);
			j++;
		}
		count++;
	}
	return (1);
}
