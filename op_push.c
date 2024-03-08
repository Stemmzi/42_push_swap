/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:24 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/08 17:41:47 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*next;

	head = *stack_b;
	next = head->next;
	*stack_b = next;
	head->next = *stack_a;
	*stack_a = head;
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
