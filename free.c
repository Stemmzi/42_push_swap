/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:36:38 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 22:52:26 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

void	free_args(char	**ptr, int k)
{
	int	count;

	count = 0;
	while (count < k)
	{
		free(ptr[count]);
		count++;
	}
	free(ptr);
}

void	ft_error(char *str, t_list **stack_a, t_list **stack_b)
{
	ft_printf("%s\n", str);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(0);
}
