/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggi2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:39:09 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/26 16:58:37 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

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

void	ft_smallsort(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (((tmp->value) > (tmp->next->value))
		&& ((tmp->value) > (tmp->next->next->value)))
	{
		rotate_a(a, 'a');
		tmp = *a;
	}
	if ((tmp->next->value) > (tmp->next->next->value))
	{
		rrotate_a(a, 'a');
		tmp = *a;
	}
	if ((tmp -> value) > (tmp -> next -> value))
	{
		swap_a(a, 'a');
		tmp = *a;
	}
}

bool	ft_sortedstack(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (tmp == NULL)
		return (0);
	while (tmp -> next != NULL)
	{
		if ((tmp -> value) > (tmp -> next -> value))
			return (1);
	tmp = tmp -> next;
	}
	return (0);
}
