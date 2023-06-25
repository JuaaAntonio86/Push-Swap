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
	checker(&a, &b);
	if (argv[0] == 0)
		ft_freesp(argv);
	ft_freelst(&a);
	ft_freelst(&b);
	return (0);
}

void checker(t_node **a, t_node **b)
{
	 char *line;
	if (ft_sortedstack(a) == 1)
	{
	//	ft_sortstack(a, b);
		line = get_next_line(0);
		while (line != NULL)
		{
			if (checkstdin(line, a, b) == 1)
			{
				ft_freelst(b);	
				ft_error(1, a);
			}
			line = get_next_line(0);
		}
	}	
		if (!ft_sortedstack(a) && ft_stacksize(*b) == 0)
			ft_printf("OK");
		else
			ft_printf("KO");
}

bool checkstdin(char *str, t_node **a, t_node **b)
{
	if (!ft_strncmp(str, "pb\n", 4))
		push_b(a, b, 0);
	else if (!ft_strncmp(str, "pa\n", 4))
		push_b(b, a, 0);
	else if (!ft_strncmp(str, "sa\n", 4))
		swap_a(a, 0);
	else if (!ft_strncmp(str, "sb\n", 4))
		swap_a(b, 0);
	else if (!ft_strncmp(str, "rb\n", 4))
		rotate_a(b, 0);
	else if (!ft_strncmp(str, "ra\n", 4))
		rotate_a(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrotate_a(b, 0);
	else if (!ft_strncmp(str, "rra\n", 5))
		rrotate_a(a, 0);
	else 
		return (1);
	return (0);
}

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
