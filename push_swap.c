/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:41:58 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:09:51 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argstolist(int argc, char **argv, t_list **head_a)
{
	char	**nbrarray;
	int		i;
	size_t	number;

	i = 0;
	if (argc == 2)
	{
		nbrarray = ft_split(argv[1], ' ');
		while (nbrarray[i])
		{
			number = (size_t)ft_atoi(nbrarray[i]);
			ft_lstadd_back(head_a, ft_lstnew((void *)number));
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			number = (int)ft_atoi(argv[i]);
			ft_lstadd_back(head_a, ft_lstnew((void *)number));
			i++;
		}
	}
}

void	ft_freelst(t_list *head_a, t_list *head_b)
{
	t_list	*tmp;

	while (head_a)
	{
		tmp = head_a;
		head_a = head_a->next;
		free(tmp);
	}
	while (head_b)
	{
		tmp = head_b;
		head_b = head_b->next;
		free(tmp);
	}
}

void	ft_norepeat(t_list **head_a)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*head_a)
		exit(1);
	temp1 = *head_a;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->content == temp2->content)
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	ft_argstolist(argc, argv, &head_a);
	ft_norepeat(&head_a);
	if (ft_lstsize(head_a) == 3)
		ft_mini_quicksort(&head_a);
	else
		ft_quicksort(&head_a, &head_b);
	ft_freelst(head_a, head_b);
	return (0);
}
