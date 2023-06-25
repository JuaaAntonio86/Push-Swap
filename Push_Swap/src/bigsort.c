/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:34:34 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 15:47:55 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"
/*
void ft_bigsort(t_node **a, t_node **b)
{
	t_node *tmpa;
	t_node *tmpb;

	while (ft_stacksize(*a) > 0)
	{
	push_b(a, b, 'b');
	tmpa = *a;
	tmpb = *b;
//		if (tmpa != NULL && ft_cost(a, b) == 1 && ft_stacksize(*a) > 1)
//			ft_bubblesortnext(a, tmpb -> value, 'a');	
		if (tmpa != NULL && ft_stacksize(*b) > 1)
			ft_bubblesortnext(b, tmpa -> value, 'b');
	}
	while (ft_stacksize(*b) != 0)
	{
		tmpb = *b;
		tmpa = *a;
		ft_bubblesort(b, ft_findlowest(b), 'b');
		push_b(b, a, 'a');
	}
}

int ft_cost(t_node **a, t_node **b)
{
	t_node *tmpa;
	t_node *tmpb;
	int conta;
	int nexthigh;
	int contb;

	conta = 0;
	contb = 0;
	tmpa = *a;
	tmpb = *b;
	nexthigh = ft_findnexthigh(a, tmpb -> value);
	while (tmpa -> value != nexthigh && tmpa -> next != NULL )
	{
		conta++;
		tmpa = tmpa -> next;
	}
	nexthigh = ft_findnexthigh(b, tmpb -> value);
	while (tmpb -> value != nexthigh && tmpb -> next != NULL )
	{
		contb++;
		tmpb = tmpb -> next;
	}
	if (conta > ft_stacksize(*a) / 2)
		conta = ft_stacksize(*a) - conta;
	if (contb > ft_stacksize(*b) / 2)
		contb = ft_stacksize(*b) - contb;
	if (conta < contb)
		return (1);
	else
		return (0);
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

void ft_bubblesortnext(t_node **root, int val, char stack)
{
	t_node *tmp;
	int cont;
	int nexthigh;

	cont = 0;
	tmp = *root;
	nexthigh = ft_findnexthigh(root, val);
	while (tmp -> value != nexthigh && tmp -> next != NULL )
	{
		cont++;
		tmp = tmp -> next;
	}
	tmp = *root;
	if (tmp -> value == nexthigh)
			return;
	if (cont > (ft_stacksize(*root) / 2 ))
		rrotate_a(root, stack);
	else
		rotate_a(root, stack);
	ft_bubblesortnext(root, val, stack);
}

int ft_findnexthigh(t_node **root, int val)
{
	 int lowest = INT_MIN;
	int high = INT_MIN;
	t_node *tmp;
	
	tmp = *root;
	while(tmp != NULL)
	{
		if(tmp -> value >= lowest && tmp -> value < val) 
			lowest = tmp -> value;
		else if(tmp -> value >= high)
			high = tmp -> value;
	tmp = tmp -> next;
	}
	if (val < high)
		lowest = high;
	return (lowest);
}
*/
