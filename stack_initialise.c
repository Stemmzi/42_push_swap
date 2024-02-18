/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:04:59 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/17 22:42:32 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(t_list **stack_a, int argc, char *argv[])
{
	int		count;
	t_list	*temp;

	count = 1;
	while (count < argc)
	{
		temp = nodenew(ft_atoi(argv[count]));
		nodeadd_back(stack_a, temp);
		count++;
	}
	return (1);
}
