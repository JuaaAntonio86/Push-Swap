/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:34:34 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/14 17:40:43 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_bigsort(t_node **a, t_node **b)
{
	t_node *tmpa;
	t_node *tmpb;

	while (ft_stacksize(*a) != 0)
	{
	push_b(a, b, 'b');
	tmpa = *a;
	if ( tmpa != NULL && ft_stacksize(*a) > 1)
		ft_bubblesortnext(b, tmpa -> value, tmpa -> index, 'b');
	}
	while (ft_stacksize(*b) != 0)
	{
		tmpb = *b;
	int lowest = INT_MIN;
		while(tmpb != NULL)
		{
			if(tmpb -> value > lowest)
				lowest = tmpb -> value;
		tmpb = tmpb -> next;	
		}
		ft_bubblesort(b, lowest, 'b');
		push_b(b, a, 'a');
	}
}

int ft_findlowest(t_node **root)
{
	int lowest;
	t_node *tmp;
	
	lowest = INT_MAX;
	tmp = *root;
	while(tmp != NULL)
	{
		if(tmp -> value <= lowest)
			lowest = tmp -> value;
	tmp = tmp -> next;
	}
	return (lowest);
}

void ft_bubblesortnext(t_node **root, int val, int indexp, char stack)
{
	t_node *tmp;
	int cont;
	int nexthigh;

	cont = 0;
	tmp = *root;
	nexthigh = ft_findnexthigh(root, val);
	while (tmp -> value != nexthigh && tmp -> next != NULL && (tmp -> index >= indexp - 12 && tmp -> index <= indexp + 12))
	{
		cont++;
		tmp = tmp -> next;
	}
	tmp = *root;
	if (tmp -> value == nexthigh || (tmp -> index >= indexp - 15 && tmp -> index <= indexp + 15))
			return;
	if (cont > ft_stacksize(*root) / 2 && cont > ft_stacksize(*root) - 10)
		rrotate_a(root, stack);
	else if (cont < 10)  
		rotate_a(root, stack);
	ft_bubblesortnext(root, val, indexp, stack);
}

int ft_findnexthigh(t_node **root, int val)
{
	int lowest = INT_MIN;
	int high = INT_MAX;
	t_node *tmp;
	
	tmp = *root;
	while(tmp != NULL)
	{
		if(tmp -> value >= lowest && tmp -> value < val)
			lowest = tmp -> value;
		else if(tmp -> value <= high)
			high = tmp -> value;
	tmp = tmp -> next;
	}
	if (val < high)
		lowest = high;
	return (lowest);
}
