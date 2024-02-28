/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:54:05 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/28 19:45:08 by sgeiger          ###   ########.fr       */
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

int	get_smallest_price(t_list **stack_b)
{
	t_list	*head;
	int		value;
	int		index;

	head = *stack_b;
	value = head->price;
	index = 1;
	while (head != NULL)
	{
		if (head->price < value)
		{
			value = head->price;
			index = head->index;
		}
		head = head->next;
	}
	return (index);
}
