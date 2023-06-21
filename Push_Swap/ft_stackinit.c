/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:24:38 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 17:28:47 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initlist(t_node **root, int valu, int indx)
{
	t_node	*node;
	t_node	*tmp;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		ft_error(1, root);
	node->value = valu;
	node -> index = indx;
	node->next = NULL;
	if (*root == NULL)
	{
		*root = node;
		node->prev = NULL;
	}
	else
	{
		tmp = *root;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	ft_checkvalues(root);
}

void	ft_checkvalues(t_node **root)
{
	t_node	*first;
	t_node	*sec;

	first = *root;
	while (first != NULL)
	{
		sec = *root;
		while (sec != NULL)
		{
			if (first -> value == sec -> value && (sec != first))
				ft_error(1, root);
			sec = sec -> next;
		}
	first = first -> next;
	}
}

void	ft_error(int type, t_node **a)
{
	if (type == 1)
		write(2, "Error\n", 6);
	ft_freelst(a);
	exit(type);
}

void	*ft_freearg(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
	return (NULL);
}

void	ft_freelst(t_node **stack)
{
	t_node	*tmp;
	t_node	*curr;

	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr -> next;
		free (tmp);
	}
}
