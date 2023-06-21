/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:18:23 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:50 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		ft_error(1, &a);
	else if (argc == 2)
		argv = ft_splitarg(argv[1], 32);
	if (ft_checkarg(argv))
		ft_error(1, &a);
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_error(1, &a);
		ft_initlist(&a, ft_atol(argv[i]), 0);
		i++;
	}
	ft_sortstack(&a, &b);
	if (argv[0] == 0)
		ft_freesp(argv);
	ft_freelst(&a);
	ft_freelst(&b);
}

int	ft_checkarg(char **argv)
{
	int	i;
	int	j;
	int	sign;

	j = 1;
	while (argv[j] != NULL)
	{
		sign = 0;
		i = 0;
		while ((argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][i] == ' '
				|| (argv[j][i] >= 9 && argv[j][i] <= 13) || argv[j][i] == '-'
				|| argv[j][i] == '+')
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
				sign++;
		i++;
		}
		if (argv[j][i] != 0 || sign > 1)
			return (1);
	j++;
	}
	return (0);
}
