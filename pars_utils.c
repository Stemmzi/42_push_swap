/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:26:41 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/12 18:34:24 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**is_arg_valid_argc2(t_list **a, int argc, char *argv[])
{
	char	**args;
	int		startpos;
	int		count;

	startpos = 1;
	count = 0;
	args = ft_split(argv[1], ' ');
	while (args[count])
		count++;
	if (count == 0)
		return (args);
	argc = count;
	startpos = 0;
	if (!is_numeric(argc, args, startpos))
		return (args);
	if (!is_int(argc, args, startpos))
		return (args);
	if (!is_unique(argc, args, startpos))
		return (args);
	create_stacks(a, -argc, args);
	free_args(args, argc);
	return (NULL);
}

void	is_arg_valid(t_list **a, t_list **b, int argc, char *argv[])
{
	char	**args;
	int		startpos;

	startpos = 1;
	if (argc == 2)
	{
		args = is_arg_valid_argc2(a, argc, argv);
		if (args != NULL)
		{
			while (args[argc])
				argc++;
			free_args(args, argc);
			ft_error("Error", a, b);
		}
	}
	else
	{
		if (!is_numeric(argc, argv, startpos))
			ft_error("Error", a, b);
		if (!is_int(argc, argv, startpos))
			ft_error("Error", a, b);
		if (!is_unique(argc, argv, startpos))
			ft_error("Error", a, b);
		create_stacks(a, argc, argv);
	}
}
