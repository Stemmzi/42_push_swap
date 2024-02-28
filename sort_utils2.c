/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:14:55 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/28 23:52:23 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list **stack_a, t_list **stack_b)
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

static int	price_a(t_list **stack_a, int value)
{
	t_list	*head;
	t_list	*prev;
	int		count;

	head = *stack_a;
	prev = nodelast(*stack_a);
	count = 0;
	while (head != NULL)
	{
		if (value < head->value && value > prev->value)
			return (count);
		count++;
		prev = head;
		head = head->next;
	}
	count = 0;
	head = *stack_a;
	while (head != NULL)
	{
		if (head->value < prev->value)
			return (count);
		count++;
		prev = head;
		head = head->next;
	}
	return (0);
}

void	price_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*pos;
	int		len;
	int		count;

	pos = *stack_b;
	index_stack(stack_a, stack_b);
	while (pos != NULL)
	{
		count = 0;
		len = get_list_len(stack_b);
		if (pos->index <= len / 2)
			count = (pos->index - 1);
		else if (pos->index > len / 2)
			count = len - pos->index + 1;
		count += price_a(stack_a, pos->value);
		pos->price = count;
		pos = pos->next;
	}
}

void	sort_element(t_list **stack_a, t_list **stack_b, int index)
{
	int	len;
	int	a;
	int	value;

	len = get_list_len(stack_b) / 2;
	while ((*stack_b)->index != index)
	{
		if (index < len)
			rotate_b(stack_b);
		else
			revrotate_b(stack_b);
	}
	value = (*stack_b)->value;
	a = price_a(stack_a, value);
	while (a > 0)
	{
		rotate_a(stack_a);
		a--;
	}
	push_a(stack_a, stack_b);
}
