#include "push_swap.h"

int main (int argc, char **argv)
{
	t_node *a;
	t_node *b;
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

	/////////////////////////////////////////////////
/*	t_node *temp = a;
	while(temp != NULL):q
	{	
		ft_printf("%i\n",temp->value);
		temp =	temp->next;
	}
	ft_printf("\n\n");
	rotate_a(&a);
	temp = a;
	while(temp != NULL)
	{	
		ft_printf("%i\n",temp->value);
		temp =	temp->next;
	}
	ft_printf("\n\n");
	swap_a(&a);
	temp = a;
	while(temp != NULL)
	{	
		ft_printf("%i\n",temp->value);
		temp =	temp->next;
	}
	ft_printf("\n\n");
	rrotate_a(&a);
	temp = a;
	while(temp != NULL)
	{	
		ft_printf("%i\n",temp->value);
		temp =	temp->next;
	}
	ft_printf("\n\n");
	push_b(&a, &b);
	push_b(&a, &b);
	temp = a;
	t_node *temp1 = b;
	while(temp != NULL)
	{	
		ft_printf("%i\n",temp->value);
		temp =	temp->next;
	}
	while(temp1 != NULL)
	{	
		ft_printf("b%i\n",temp1->value);
		temp1 =	temp1->next;
	}
	ft_printf("%ia", ft_stacksize(a));
	ft_printf("%ib\n", ft_stacksize(b));	
*/
	if (argv[0] == 0)
		ft_freesp(argv);
	ft_freelst(&a);
	ft_freelst(&b);
}


int ft_checkarg(char ** argv)
{
	int i;
	int j;
	int sign;

	j = 1;
	while (argv[j] != NULL)
	{
		sign = 0;
		i = 0;
		while ((argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][i] == ' ' || (argv[j][i] >= 9 
					&& argv[j][i] <= 13) || argv[j][i] == '-' || argv[j][i] == '+')
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
				sign++;
		i++;	
		}
	if (argv[j][i] != 0 || sign > 1)
		return(1);
	j++;
	}
	return (0);
}


