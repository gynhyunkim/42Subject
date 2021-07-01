/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:09 by gkim              #+#    #+#             */
/*   Updated: 2021/06/17 20:39:07 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	int		size;
}				t_stack;

typedef struct	s_obj
{
	t_stack	*stack[2];
	t_stack	*cmd;
}				t_obj;

t_node  *init_node(int data);
void	add_back(t_node *node, t_stack *stack);
void	add_front(t_node *node, t_stack *stack);
t_node	*pop(t_node *node, t_stack *stack);
void    swap(t_obj *o, int key);
void	push(t_obj *o, int key);
int		rotate(t_obj *o, int key);
void	reverse_rotate(t_obj *o, int key);
t_obj	*init_stack();
void	quick_sort_stack(t_obj *o, int p, int r, int **sorted);
void	sort(t_obj *o, int key);

# endif
