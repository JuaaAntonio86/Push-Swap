/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:50:22 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/19 14:55:40 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_node **root, char id)
{
  	t_node *one;
	t_node *two;
    t_node *tmp;

    one = *root;
    two = one->next;
	tmp = two->next;
	two->next = one;
	one->next = tmp;
	*root = two;
	pos_stack(root);
	ft_printf("s%c\n", id);
}

void rotate_a(t_node **root, char id)
{
	t_node *tmp;
	t_node *one;

	one = *root;
	tmp = *root;
	*root = one -> next;
	while(tmp -> next != NULL)
		tmp = tmp -> next;
	tmp->next = one;
	one -> next = NULL;	
	pos_stack(root);
	ft_printf("r%c\n", id);
}

void rrotate_a(t_node **root, char id)
{
	t_node *tmp;
	t_node *one;

	one = *root;
	tmp = *root;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = one;
	*root = tmp->next;
	tmp->next = NULL;
	pos_stack(root);
	ft_printf("rr%c\n", id);
}

void push_b(t_node **root_a, t_node **root_b, char id)
{
	t_node *a;
	t_node *b;
	t_node *tmp;

	a = *root_a;
	b = *root_b;
	tmp = a->next;
	if (b == NULL)
		a -> next = NULL;
	else
		a->next = b;
	*root_b = a;
	*root_a = tmp;
	pos_stack(root_a);
	pos_stack(root_b);
	ft_printf("p%c\n", id);
}
