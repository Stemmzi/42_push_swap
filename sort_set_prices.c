/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_set_prices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:44:38 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/06 18:48:13 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_all_null(t_list **stack_b)
{
	t_list	*head;

	head = *stack_b;
	while (head != NULL)
	{
		head->r_both = 0;
		head->r_a = 0;
		head->r_b = 0;
		head = head->next;
	}
}

void	set_r_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		len;

	head = *stack_b;
	len = get_list_len(stack_a);
	while (head != NULL)
	{
		if ((head->target_pos + 1) * 2 <= len + 1)
			head->r_a = head->target_pos;
		else
			head->r_a = (len - head->target_pos) * -1;
		head = head->next;
	}
}

void	set_r_b(t_list **stack_b)
{
	t_list	*head;
	int		len;

	head = *stack_b;
	len = get_list_len(stack_b);
	while (head != NULL)
	{
		if (head->index * 2 <= len + 1)
			head->r_b = head->index - 1;
		else
			head->r_b = (len - head->index + 1) * -1;
		head = head->next;
	}
}

static void	set_r_both_equal(t_list *head)
{
	int		smaller;

	if (head->r_a > 0 && head->r_b > 0)
	{
		smaller = ft_smaller_nbr(head->r_a, head->r_b);
		head->r_both = smaller;
		head->r_a = head->r_a - smaller;
		head->r_b = head->r_b - smaller;
	}
	else if (head->r_a < 0 && head->r_b < 0)
	{
		if (head->r_a > head->r_b)
		{
			head->r_both = head->r_a;
			head->r_b = head->r_b + (head->r_a * -1);
			head->r_a = head->r_a + (head->r_a * -1);
		}
		else
		{
			head->r_both = head->r_b;
			head->r_a = head->r_a + (head->r_b * -1);
			head->r_b = head->r_b + (head->r_b * -1);
		}
	}
}

void	set_r_both(t_list **stack_b)
{
	t_list	*head;

	head = *stack_b;
	while (head != NULL)
	{
		if (head->r_a > 0 && head->r_b > 0)
			set_r_both_equal(head);
		else if ((head->r_a < 0 && head->r_b < 0))
			set_r_both_equal(head);
		else if (head->r_a > 0 && head->r_b <= 0)
			head->r_both = 0;
		else if (head->r_a <= 0 && head->r_b > 0)
			head->r_both = 0;
		head = head->next;
	}
}
