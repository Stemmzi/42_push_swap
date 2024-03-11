/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:38:11 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 18:43:13 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_b(t_list **stack_a, t_list **stack_b, t_list *head)
{
	int		both;

	both = head->r_both;
	while (both != 0)
	{
		if (both > 0)
		{
			rotate_rr(stack_a, stack_b);
			both--;
		}
		else if (both < 0)
		{
			revrotate_rrr(stack_a, stack_b);
			both++;
		}
	}
}

void	move_a(t_list **stack_a, t_list *head)
{
	int		a;

	a = head->r_a;
	while (a != 0)
	{
		if (a > 0)
		{
			rotate_a(stack_a);
			a--;
		}
		else if (head->r_a < 0)
		{
			revrotate_a(stack_a);
			a++;
		}
	}
}

void	move_b(t_list **stack_b, t_list *head)
{
	int		b;

	b = head->r_b;
	while (b != 0)
	{
		if (b > 0)
		{
			rotate_b(stack_b);
			b--;
		}
		else if (b < 0)
		{
			revrotate_b(stack_b);
			b++;
		}
	}
}
