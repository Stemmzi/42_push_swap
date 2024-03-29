/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:04:59 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/08 17:48:43 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(t_list **stack_a, int argc, char *argv[])
{
	int		count;
	t_list	*temp;

	count = 1;
	if (argc < 0)
	{
		argc = argc * -1;
		count = 0;
	}
	while (count < argc)
	{
		temp = nodenew(ft_atoi(argv[count]));
		nodeadd_back(stack_a, temp);
		count++;
	}
	return (1);
}

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (temp == NULL)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
