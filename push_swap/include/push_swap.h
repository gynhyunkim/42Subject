/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:09 by gkim              #+#    #+#             */
/*   Updated: 2021/11/09 20:47:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

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

t_node		*init_node(int data);
void		add_back(t_node *node, t_stack *stack);
void		add_front(t_node *node, t_stack *stack);
t_node		*pop(t_node *node, t_stack *stack);
void		swap(t_obj *o, int key);
void		push(t_obj *o, int key);
int			rotate(t_obj *o, int key);
void		reverse_rotate(t_obj *o, int key);
t_obj		*init_stack();
void		sort(t_obj *o, int key);
void		arr_quick_sort(int *a, int p, int r);
void		a_to_b(t_obj *o, int *sorted, int l, int r);
void		b_to_a(t_obj *o, int *sorted, int l, int r);
int			insert_array(char *num, int *arr, int size);
int			isSorted(t_stack *s);
void		three_sort(t_obj *o, int key);
void		five_param(t_obj *o, int *sorted);
long long	ps_atoi(const char *s, char *err_flag);
int			cmd_parsing(t_stack *cmd);
void		free_stack(t_obj *o);

# endif
