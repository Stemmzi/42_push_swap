/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:06:06 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/06 18:51:27 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = *stack_b;
	while (head != NULL)
	{
		set_target_pos(stack_a, head);
		head = head->next;
	}
	set_all_null(stack_b);
	set_r_b(stack_b);
	set_r_a(stack_a, stack_b);
	set_r_both(stack_b);
}

static int	set_target_pos_ib(t_list *head, t_list *prev, t_list *pos)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		if (pos->value < head->value && pos->value > prev->value)
		{
			pos->target_pos = count;
			return (1);
		}
		count++;
		prev = head;
		head = head->next;
	}
	return (0);
}

void	set_target_pos(t_list **stack_a, t_list *pos)
{
	t_list	*head;
	t_list	*prev;
	int		count;

	head = *stack_a;
	prev = nodelast(*stack_a);
	count = 0;
	if (!set_target_pos_ib(head, prev, pos))
	{
		while (head != NULL)
		{
			if (head->value < prev->value)
				pos->target_pos = count;
			count++;
			prev = head;
			head = head->next;
		}
	}
}

void	sort_one_element(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*head;

	head = *stack_b;
	while (head->index != index)
		head = head->next;
	move_a_b(stack_a, stack_b, head);
	move_a(stack_a, head);
	move_b(stack_b, head);
	push_a(stack_a, stack_b);
}
