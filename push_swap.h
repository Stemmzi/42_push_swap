/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:32:04 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/27 17:55:21 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				value;
}	t_list;

// Node utils
t_list	*nodenew(int arg);
void	nodeadd_back(t_list **lst, t_list *new);
t_list	*nodelast(t_list *lst);
int		lstsize(t_list *lst);

// Input checker
int		is_numeric(int argc, char *argv[], int startpos);
int		is_int(int argc, char *argv[], int startpos);
int		is_unique(int argc, char *argv[], int startpos);
void	is_arg_valid(int argc, char *argv[]);

// Stack creation
int		create_stacks(t_list **stack_a, int argc, char *argv[]);
int		is_sorted(t_list **stack);

// Free and error
void	free_stack(t_list **stack);
void	ft_error(char *str);

// Swap operations
void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

// Push operations
void	push(t_list **stack_1, t_list **stack_2);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

// Rotate oeprations
void	rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

// Reverse rotate operations
void	revrotate(t_list **stack);
void	revrotate_a(t_list **stack_a);
void	revrotate_b(t_list **stack_b);
void	revrotate_rrr(t_list **stack_a, t_list **stack_b);

#endif