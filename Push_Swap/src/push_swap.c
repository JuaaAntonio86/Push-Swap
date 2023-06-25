/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:18:23 by juan-anm          #+#    #+#             */
/*   Updated: 2023/06/21 19:16:17 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2 || argv[1] == 0)
		ft_error(0, &a);
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

/*int	ft_checkarg(char **argv)
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
			if (sign > 0 && (argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (1);
		i++;	
		}
		if (argv[j][i] != 0 || sign > 1 || argv[j][i - 1] == '-' || argv[j][i - 1] == '+')
			return (1);
	j++;
	}
	return (0);
}*/
int	ft_checkarg(char **argv)
{
	int	j;

	j = 1;
	while (argv[j] != NULL)
	{
		if (checkstr(argv[j]) != 0)
			return (1);
	j++;
	}
	return (0);
}

int checkstr(char *str)
{
	int	i;
	int	neg;

	neg = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		neg = 0;
		i++;
	}
	if (str[i] == '\0' && neg == 0)
		return (0);
	else 
		return (1);
}
