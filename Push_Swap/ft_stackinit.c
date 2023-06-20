#include "push_swap.h"
/*
typedef struct t_node
{
    int                value;
    struct t_node    *next;
    struct t_node    *prev;
}    t_node;

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    t_node *a = NULL;
    char *str[6] = {str[0]="0",str[1]="2",str[2]="6",str[3]="21",str[4]="90",str[5] = 0};
    int nbr;
    int i = 0;

    while (str[i] != NULL)
    {
      nbr = atol(str[i]);
      ft_initlist(&a, nbr);
      i++;
    }
}
*/
void ft_initlist(t_node **root, int valu, int indx)
{
  t_node *node;

  	node = malloc(sizeof(t_node));
  if (node == NULL)	
	  ft_error(1, root);
	node->value = valu;
	node -> index = indx;
	node->next =NULL;
  if (*root == NULL)
  {
      *root = node;
      node->prev = NULL; 
  }
  else
  {
    t_node *temp = *root;
    while(temp->next != NULL)
    	temp = temp->next;
    temp->next = node;
    node->prev = temp;
  }
  ft_checkvalues(root);
}

void ft_checkvalues(t_node **root)
{
	t_node *first;
	t_node *sec;

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
	t_node *curr;

	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr -> next;
		free (tmp);
	}
}
