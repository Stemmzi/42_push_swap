/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:56:47 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/21 22:01:39 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_list **stack)
{
	t_list	*last;
	t_list	*head;

	head = *stack;
	last = nodelast(head);
	while (head && head->next && head->next->next != NULL)
		head = head->next;
	last->next = *stack;
	*stack = last;
	head->next = NULL;
}

void	revrotate_a(t_list **stack_a)
{
	revrotate(stack_a);
	ft_printf("rra\n");
}

void	revrotate_b(t_list **stack_b)
{
	revrotate(stack_b);
	ft_printf("rrb\n");
}

void	revrotate_rrr(t_list **stack_a, t_list **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	ft_printf("rrr\n");
}
