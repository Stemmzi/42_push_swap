/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:37 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/27 18:13:05 by sgeiger          ###   ########.fr       */
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
	else if (args == 4)
		sort_four(stack_a, stack_b);
	else if (args == 5)
		sort_five(stack_a, stack_b);
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

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*four;
	int		count;

	count = 0;
	push_b(stack_a, stack_b);
	four = *stack_b;
	sort_three(stack_a);
	while (four->value > (*stack_a)->value && count < 3)
	{
		rotate_a(stack_a);
		count++;
	}
	push_a(stack_a, stack_b);
	while (count > 0)
	{
		revrotate_a(stack_a);
		count--;
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*five;
	int		count;

	count = 0;
	push_b(stack_a, stack_b);
	five = *stack_b;
	sort_four(stack_a, stack_b);
	while (five->value > (*stack_a)->value && count < 4)
	{
		rotate_a(stack_a);
		count++;
	}
	push_a(stack_a, stack_b);
	while (count > 0)
	{
		revrotate_a(stack_a);
		count--;
	}
}

//TODO
// void	sort_big(t_list **stack_a, t_list **stack_b)
// {

// }
