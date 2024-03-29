/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:32:04 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 22:48:59 by sgeiger          ###   ########.fr       */
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
	int				index;
	int				r_a;
	int				r_b;
	int				r_both;
	int				target_pos;
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
void	is_arg_valid(t_list **a, t_list **b, int argc, char *argv[]);

// Stack creation
int		create_stacks(t_list **stack_a, int argc, char *argv[]);
int		is_sorted(t_list **stack);
void	show_stacks(t_list **stack_a, t_list **stack_b);

// Free and error
void	free_stack(t_list **stack);
void	free_args(char	**ptr, int k);
void	ft_error(char *str, t_list **stack_a, t_list **stack_b);

// Swap operations
void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

// Push operations
void	push(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

// Rotate operations
void	rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

// Reverse rotate operations
void	revrotate(t_list **stack);
void	revrotate_a(t_list **stack_a);
void	revrotate_b(t_list **stack_b);
void	revrotate_rrr(t_list **stack_a, t_list **stack_b);

// Sort functions
void	sort_stacks(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_big(t_list **stack_a, t_list **stack_b);
void	sort_one_element(t_list **stack_a, t_list **stack_b, int index);

// Sort utils getter
int		get_list_len(t_list **stack);
int		get_median(t_list **stack);
int		get_smallest_value(t_list **stack);
int		get_cheapest_element(t_list **stack_b);

// Sort utils setter
void	price_stacks(t_list **stack_a, t_list **stack_b);
void	set_target_pos(t_list **stack_a, t_list *pos);
void	index_stacks(t_list **stack_a, t_list **stack_b);

// Pricing functions
void	set_all_null(t_list **stack_b);
void	set_r_a(t_list **stack_a, t_list **stack_b);
void	set_r_b(t_list **stack_b);
void	set_r_both(t_list **stack_b);

//Sort utils
int		ft_abs(int a);
int		ft_smaller_nbr(int a, int b);

// Sort move functions
void	move_a_b(t_list **stack_a, t_list **stack_b, t_list *head);
void	move_a(t_list **stack_a, t_list *head);
void	move_b(t_list **stack_b, t_list *head);

#endif