/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:10:38 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 22:49:40 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a != NULL || temp_b != NULL)
	{
		if (temp_a == NULL)
			printf("-");
		else
		{
			printf("%d", temp_a->value);
			temp_a = temp_a->next;
		}
		if (temp_b == NULL)
			printf(" -\n");
		else
		{
			printf(" - %d\n", temp_b->value);
			temp_b = temp_b->next;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	is_arg_valid(stack_a, stack_b, argc, argv);
	if (!is_sorted(stack_a))
		sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
