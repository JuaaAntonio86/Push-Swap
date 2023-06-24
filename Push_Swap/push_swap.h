/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:44:16 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 19:10:20 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include "MyLibft/libft.h"

typedef struct t_node
{
	int				value;
	int				index;
	int				pos;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

char	**ft_splitarg(char const *s, char c);
void	*ft_freesp(char **m);
void	ft_initlist(t_node **root, int valu, int indx);
int		ft_checkarg(char **argv);
void	ft_checkvalues(t_node **root);
int		checkstr(char *str);

//////////////MOVEMENTS FUNCT////////////

void	swap_a(t_node **root, char id);
void	rotate_a(t_node **root, char id);
void	rrotate_a(t_node **root, char id);
void	push_b(t_node **root_a, t_node **root_b, char id);

///////////////SORTING FT//////////////////

bool	ft_sortedstack(t_node **a);
void	ft_sortstack(t_node **a, t_node **b);
int		ft_stacksize(t_node *a);
void	ft_smallsort(t_node **a);
void	ft_sort5(t_node **a, t_node **b);
void	ft_bubblesort(t_node **a, int value, char stack);
void	ft_indexupdate(t_node **root);
void	ft_bigsort(t_node **a, t_node **b);
void	ft_biggestsort(t_node **a, t_node **b, int *array);
int		ft_findlowest(t_node **root);
void	ft_bubblesortnext(t_node **a, int value, char stack);
int		ft_findnexthigh(t_node **root, int value);
int		ft_cost(t_node **a, t_node **b);

////////////Biggi Sorting///////////////////////

void	sort_big(t_node **a, t_node **b, int chunks, int i);
void	push_stack_b(t_node **a, t_node **b, int max_ind, int chunk_size);
void	push_stack_a(t_node **a, t_node **b);
void	push_node(t_node **stack, int index, char stackchr);
int		mtp(t_node **stack, int index);
int		find_node(t_node **stack, int index);
void	pos_stack(t_node **stack);

//////////////FREE FUNCTIONS//////////////

void	ft_freelst(t_node **stack);
void	*ft_freearg(char **m);
void	ft_error(int type, t_node **a);

////////////////BONUS/////////////////

void checker(t_node **a, t_node **b);
bool checkstdin(char *str, t_node **a, t_node **b);

#endif
