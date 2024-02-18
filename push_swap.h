/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:32:04 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/17 21:37:56 by sgeiger          ###   ########.fr       */
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
void	nodeadd_front(t_list **lst, t_list *new);
void	nodeadd_back(t_list **lst, t_list *new);

// Input checker
int		is_numeric(int argc, char *argv[], int startpos);
int		is_int(int argc, char *argv[], int startpos);
int		is_unique(int argc, char *argv[], int startpos);
int		is_arg_valid(int argc, char *argv[]);

#endif