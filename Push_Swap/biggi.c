/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:51:41 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/19 14:58:45 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_node **a, t_node **b, int chunks, int total_size)
{
	int		i;
	int		iter;
	int		max_ind;
	int		tmp_size;
	int		chunk_size;
	t_node *tmpa;

	tmpa = *a;
	chunk_size = total_size / chunks;
	i = 0;
	while (tmpa->next != NULL)
	{
		tmp_size = ft_stacksize(*a);
		max_ind = (total_size / chunks) * ++i;
		iter = -1;
		while (++iter < tmp_size)
		{
			if (tmpa->index < max_ind)
				push_stack_b(a, b, max_ind, chunk_size);
			else
				rotate_a(a, 'a');
		}
	}
	push_stack_a(a, b);
}

void	push_stack_b(t_node **a, t_node **b, int max_ind, int chunk_size)
{
	t_node *tmpb;

	tmpb = *b;
	push_b(a, b, 'b');
	if (chunk_size > 20)
	{
		if (tmpb->index < (max_ind - (chunk_size / 2)))
			rotate_a(b, 'b');
	}
}

void	push_stack_a(t_node **a, t_node **b)
{
	t_node *tmpb;

	tmpb = *b;
	while (tmpb->next != NULL)
	{
		if (ft_stacksize(*b) == 1)
			push_b(b, a, 'a');
		else if (mtp(b, ft_stacksize(*b) - 2) < mtp(b, ft_stacksize(*b) - 1))
		{
			push_node(b, ft_stacksize(*b) - 2, 'b');
			push_b(b, a, 'a');
			push_node(b, ft_stacksize(*b), 'b');
			push_b(b, a, 'a');
			swap_a(a, 'a');
		}
		else
		{
			push_node(b, ft_stacksize(*b) - 1, 'b');
			push_b(b, a, 'a');
		}
	}
}

void	push_node(t_node **stack, int index, char stackchr)
{
	int	pos;

	pos = find_node(stack, index);
	if (pos == -1)
		return ;
	while (pos != 0)
	{
		if (pos < ft_stacksize(*stack) / 2)
			rotate_a(stack, stackchr);
		else
			rrotate_a(stack, stackchr);
		pos = find_node(stack, index);
	}
}

int	mtp(t_node **stack, int index)
{
	int	mtp;

	if (find_node(stack, index) < ft_stacksize(*stack) / 2)
		mtp = find_node(stack, index);
	else
		mtp = ft_stacksize(*stack) - find_node(stack, index);
	return (mtp);
}

int	find_node(t_node **stack, int index)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (-1);
}

void	pos_stack(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}
