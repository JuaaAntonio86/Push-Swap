
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2 || argv[1] == 0)
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
	checker(&a, &b);
	if (argv[0] == 0)
		ft_freesp(argv);
	ft_freelst(&a);
	ft_freelst(&b);
}

void checker(t_node **a, t_node **b)
{
	 char *line;
	
	line = get_next_line(0);
	while (str != NULL)
	{
		checkstdin(line);
		line = get_next_line(0);
	}
	if (ft_sortedstack(a)
		ft_printf("OK");
	else
		ft_printf("KO"):
}

bool checkstdin(char *str)
{
	if (!strncmp(str, "pb\n", 4))
		push_b(a, b, 'b');
	else if (!strncmp(str, "pa\n", 4))
		push_b(b, a, str[1]);
	else if (!strncmp(str, "sa\n", 4))
		swap_a(str[1]);
	else if (!strncmp(str, "sa\n", 4))
		swap_a(str[1]);
	else if (!strncmp(str, "rb\n", 4))
		push_b(b, a, str[1]);
	else if (!strncmp(str, "rrb\n", 5))
		push_b(b, a, str[1]);
	else if 





		return (0);
	return (1);




}
