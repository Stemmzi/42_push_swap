/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:24 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/21 00:15:53 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*head;
	t_list	*next;

	head = *stack_2;
	next = head->next;
	*stack_2 = next;
	head->next = *stack_1;
	*stack_1 = head;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b != NULL)
	{
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a != NULL)
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
	}
}
