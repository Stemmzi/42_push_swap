/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:14:55 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/06 18:50:06 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		index;

	temp_a = *stack_a;
	temp_b = *stack_b;
	index = 1;
	while (temp_a != NULL)
	{
		temp_a->index = index;
		index++;
		temp_a = temp_a->next;
	}
	index = 1;
	while (temp_b != NULL)
	{
		temp_b->index = index;
		index++;
		temp_b = temp_b->next;
	}
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	ft_smaller_nbr(int a, int b)
{
	if (a == b)
		return (b);
	if (a > b)
		return (b);
	return (a);
}
