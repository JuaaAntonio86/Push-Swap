/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:51:41 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 17:17:49 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	sort_big(t_node **a, t_node **b, int blocks, int i)
{
	int		iter;
	int		max_ind;
	int		tmp_size;
	int		block_size;
	t_node	*tmpa;

	tmpa = *a;
	block_size = ft_stacksize(*a) / blocks;
	while (tmpa != NULL)
	{
		tmp_size = ft_stacksize(*a);
		max_ind = ((ft_stacksize(*a) + ft_stacksize(*b)) / blocks) * ++i;
		iter = -1;
		while (++iter < tmp_size)
		{
			if (tmpa->index < max_ind)
				push_stack_b(a, b, max_ind, block_size);
			else
				rotate_a(a, 'a');
		tmpa = *a;
		}
	}
	push_stack_a(a, b);
}

void	push_stack_b(t_node **a, t_node **b, int max_ind, int chunk_size)
{
	t_node	*tmpb;

	push_b(a, b, 'b');
	tmpb = *b;
	if (chunk_size > 20)
	{
		if (tmpb->index < (max_ind - (chunk_size / 2)))
			rotate_a(b, 'b');
	}
}

void	push_stack_a(t_node **a, t_node **b)
{
	t_node	*tmpb;

	tmpb = *b;
	while (tmpb != NULL)
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
		tmpb = *b;
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
