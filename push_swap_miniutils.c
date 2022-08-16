/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_miniutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:51:44 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:10:14 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minipivot(t_list **src)
{
	int		min_x_int;
	int		limit;
	int		size;
	t_list	*temp;

	temp = *src;
	limit = 2147483647;
	size = 2;
	while (size > 0)
	{
		min_x_int = -2147483648;
		while (temp)
		{
			if ((int)temp->content > min_x_int && (int)temp->content < limit)
				min_x_int = (int)temp->content;
			temp = temp->next;
		}
		limit = min_x_int;
		temp = *src;
		size--;
	}
	return (limit);
}

void	ft_mini_quicksort(t_list **head_a)
{
	int	pivot;

	if (ft_sorted(*head_a, (int)(*head_a)->chunk, 'a'))
		exit(1);
	pivot = ft_minipivot(head_a);
	if ((int)(*head_a)->content == pivot)
	{
		if ((int)(*head_a)->next->content > pivot)
			ft_rra(head_a, 0);
		else
			ft_sa(head_a, 1);
	}
	else if ((int)(*head_a)->next->content == pivot)
	{
		ft_sa(head_a, 1);
		ft_rra(head_a, 0);
	}
	else if ((int)(*head_a)->content > pivot)
		ft_ra(head_a, 0);
	else
	{
		ft_sa(head_a, 1);
		ft_ra(head_a, 0);
	}
}
