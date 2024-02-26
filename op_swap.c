/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:21 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/26 17:17:11 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;

	head = *stack;
	next = head->next;
	head->next = next->next;
	next->next = head;
	*stack = next;
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
