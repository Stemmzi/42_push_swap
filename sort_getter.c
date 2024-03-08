/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:54:05 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/08 16:59:03 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_len(t_list **stack)
{
	t_list	*head;
	int		len;

	head = *stack;
	len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return (len);
}

static int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	max = 0;
	head = *stack;
	while (head != NULL)
	{
		if ((head)->value > max)
			max = (head)->value;
		head = (head)->next;
	}
	return (max);
}

int	get_median(t_list **stack)
{
	t_list	*head;
	int		median;
	int		len;
	int		min;

	head = *stack;
	len = get_list_len(stack) + 3;
	if (len % 2 != 0)
		len += 1;
	len /= 2;
	min = 0;
	while (len > 0)
	{
		median = get_max(stack);
		while (head != NULL)
		{
			if (head->value < median && head->value > min)
				median = head->value;
			head = head->next;
		}
		min = median;
		head = *stack;
		len--;
	}
	return (median);
}

int	get_smallest_value(t_list **stack)
{
	t_list	*head;
	int		value;
	int		index;

	head = *stack;
	value = head->value;
	index = 1;
	while (head != NULL)
	{
		if (head->value < value)
		{
			value = head->value;
			index = head->index;
		}
		head = head->next;
	}
	return (index);
}

int	get_cheapest_element(t_list **stack_b)
{
	t_list	*head;
	int		val;
	int		index;

	head = *stack_b;
	val = ft_abs(head->r_both) + ft_abs(head->r_a) + ft_abs(head->r_b);
	index = 1;
	while (head != NULL)
	{
		if (ft_abs(head->r_both) + ft_abs(head->r_a) + ft_abs(head->r_b) < val)
		{
			val = ft_abs(head->r_both) + ft_abs(head->r_a) + ft_abs(head->r_b);
			index = head->index;
		}
		head = head->next;
	}
	return (index);
}
