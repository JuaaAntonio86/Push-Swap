#include "push_swap.h"

void ft_sortstack(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = *a;
	ft_indexupdate(a);
	if (ft_stacksize(*a) == 1 || !(ft_sortedstack(a)))
		return;
	else if (ft_stacksize(*a) == 2)
	{
		if ((tmp -> value) > (tmp -> next -> value))
			swap_a(a, 'a');
	}
	else if (ft_stacksize(*a) == 3)
	{
		ft_smallsort(a);
	}
	else if (ft_stacksize(*a) > 3 && ft_stacksize(*a) < 11)
	{
//	ft_sort5(a, b);
//	}
//	else if (ft_stacksize(*a) >= 11)
//	{
	sort_big(a, b, 3, ft_stacksize(*a));
	}
}

int	ft_stacksize(t_node *a)
{
	int	count;
	
	count = 0;
	while (a != NULL)
	{
		a = a -> next;
	count ++;
	}
	return (count);
}

void ft_indexupdate(t_node **a)
{
	t_node *tmp;
	int i;
	int min;
	int last;

	i = 0;
	last = INT_MIN;
	tmp = *a;
	while (i != ft_stacksize(*a))
	{
		min = INT_MAX;
		tmp = *a;
		while (tmp != NULL)
		{	
			if (tmp -> value < min && tmp -> value > last)
			{
				min = tmp -> value;
				tmp -> index = i;
			}
		tmp = tmp -> next;
		}
	last = min;	
	i++;
	}
pos_stack(a);
}

void ft_sort5(t_node **a, t_node **b)
{
	int lowest;
	t_node *tmp;

	while (ft_stacksize(*a) > 3)
	{
		tmp = *a;
		lowest = INT_MAX;
		while (tmp != NULL)
		{
			if (tmp -> value < lowest)
				lowest = tmp -> value;	
		tmp = tmp -> next;
		}
	ft_bubblesort(a, lowest, 'a');
	push_b(a, b, 'b');
	}
	ft_smallsort(a);
	while (ft_stacksize(*b) != 0)
		push_b(b, a, 'a');
}

void ft_bubblesort(t_node **root, int val, char stack)
{
	t_node *tmp;
	int cont;

	cont = 0;
	tmp = *root;
	while (tmp -> value != val )
	{
		cont++;
		tmp = tmp -> next;
	}
	tmp = *root;
	if (tmp -> value == val)
			return;
	if (cont > (ft_stacksize(*root) / 2 ))
		rrotate_a(root, stack);
	else 
		rotate_a(root, stack);
	ft_bubblesort(root, val, stack);
}

void ft_smallsort(t_node **a)
{
	t_node *tmp; 
		
	tmp	= *a;
	if (((tmp -> value) > (tmp -> next -> value)) && ((tmp -> value) > (tmp -> next -> next -> value)))  	{
		rotate_a(a, 'a');
		tmp = *a;
	}	
	if ((tmp -> next -> value) > (tmp -> next -> next ->  value))
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

bool ft_sortedstack(t_node **a)
{
	t_node *tmp;

	tmp = *a;
	while ( tmp -> next != NULL)
	{
		if((tmp -> value) > (tmp -> next -> value))
			return (1);
	tmp = tmp -> next;
	}
	return (0);
}
