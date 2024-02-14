/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:26:41 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/14 00:45:15 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(int argc, char *argv[])
{
	int		count;
	int		c;

	count = 1;
	c = 0;
	while (count < argc)
	{
		if (argv[count][c] == '-' || argv[count][c] == '+')
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

static int	has_sign (char *str)
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

int	is_int(int argc, char *argv[])
{
	int	count;

	count = 1;
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

int	is_unique(int argc, char *argv[])
{
    int	count;
	int	j;

	count = 1;
    while (count < argc - 1)
	{
        j = count + 1;
        while (j < argc)
		{
            if (strcmp(argv[count], argv[j]) == 0)
                return (0);
            j++;
        }
        count++;
    }
    return (1);
}

int	is_arg_valid(int argc, char *argv[])
{
	printf("->1\n");
	if (!is_numeric(argc, argv))
		return (0);
	printf("->2\n");
	if (!is_int(argc, argv))
		return (0);
	printf("->3\n");
	if (!is_unique(argc, argv))
		return (0);
	printf("->4\n");
	return (1);
}
