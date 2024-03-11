/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:26:41 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 18:43:31 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_arg_valid_argc2(t_list **stack_a, int argc, char *argv[])
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
		ft_error("Error");
	argc = count;
	startpos = 0;
	if (!is_numeric(argc, args, startpos))
		ft_error("Error");
	if (!is_int(argc, args, startpos))
		ft_error("Error");
	if (!is_unique(argc, args, startpos))
		ft_error("Error");
	create_stacks(stack_a, -argc, args);
}

void	is_arg_valid(t_list **stack_a, int argc, char *argv[])
{
	int		startpos;

	startpos = 1;
	if (argc == 2)
		is_arg_valid_argc2(stack_a, argc, argv);
	else
	{
		if (!is_numeric(argc, argv, startpos))
			ft_error("Error");
		if (!is_int(argc, argv, startpos))
			ft_error("Error");
		if (!is_unique(argc, argv, startpos))
			ft_error("Error");
		create_stacks(stack_a, argc, argv);
	}
}
