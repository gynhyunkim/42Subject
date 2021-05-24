/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:09 by gkim              #+#    #+#             */
/*   Updated: 2021/05/24 17:10:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
}				t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*last;
	int		size;
}				t_stack;

typedef struct	s_obj
{
	t_stack	*stack[2];
	t_stack	*cmd;
}				t_obj;

t_list  *init_node(int data);
void	add_back(t_list *node, t_stack *stack);
void	add_front(t_list *node, t_stack *stack);
t_list	*pop(t_list *node);
void    swap(t_obj *o, int key);
void	push(t_obj *o, int key);
void	rotate(t_obj *o, int key);
void	reverse_rotate(t_obj *o, int key);
t_obj	*init_stack();


# endif
