/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:37 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/08 17:57:29 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	args;

	args = lstsize(*stack_a);
	if (args == 2)
		swap_a(stack_a);
	else if (args == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
}

void	sort_three(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && second->value < third->value)
		rotate_a(stack_a);
	else if (first->value > third->value && second->value > third->value)
		revrotate_a(stack_a);
	if (!is_sorted(stack_a))
	{
		revrotate_a(stack_a);
		swap_a(stack_a);
	}
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = get_median(stack_a);
	while ((*stack_a)->next->next->next != NULL)
	{
		push_b(stack_a, stack_b);
		if ((*stack_b)->value > median)
			rotate_b(stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		index_stacks(stack_a, stack_b);
		price_stacks(stack_a, stack_b);
		sort_one_element(stack_a, stack_b, get_cheapest_element(stack_b));
	}
	index_stacks(stack_a, stack_b);
	if (get_smallest_value(stack_a) * 2 > get_list_len(stack_a) + 1)
		while (!is_sorted(stack_a))
			revrotate_a(stack_a);
	else
		while (!is_sorted(stack_a))
			rotate_a(stack_a);
}
