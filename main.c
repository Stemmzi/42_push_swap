/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:10:38 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 22:19:56 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	is_arg_valid(argc, argv);
	create_stacks(stack_a, argc, argv);
	temp = *stack_a;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
