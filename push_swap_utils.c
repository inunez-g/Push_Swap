/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:10 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:07:23 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list *head, int chunk, char list)
{
	int	mult;

	if (list == 'a')
		mult = 1;
	if (list == 'b')
		mult = -1;
	if (!head)
		return (0);
	while (head->next && head->chunk == chunk)
	{
		if ((int)head->content * mult > (int)head->next->content * mult)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_chunk_to_zero(t_list **head, int chunk)
{
	t_list	*temp;

	temp = *head;
	while (temp && temp->chunk == chunk)
	{
		temp->chunk = 0;
		temp = temp->next;
	}
}

int	ft_sizeof_chunk(t_list *head, int chunk)
{
	int	i;

	i = 0;
	while (head && head->chunk == chunk)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	ft_set_pivot(t_list **src, int chunk)
{
	int		min_x_int;
	int		limit;
	int		size;
	t_list	*temp;

	temp = *src;
	limit = 2147483647;
	if (ft_sizeof_chunk(*src, chunk) == 5)
		size = 3;
	else
		size = ft_sizeof_chunk(temp, chunk) / 2;
	while (size > 0)
	{
		min_x_int = -2147483648;
		while (temp && temp->chunk == chunk)
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

void	ft_quicksort(t_list **head_a, t_list **head_b)
{
	int	first;

	first = 1;
	while (!ft_sorted(*head_a, (int)(*head_a)->chunk, 'a') || *head_b)
	{
		if (ft_sorted(*head_a, (int)(*head_a)->chunk, 'a'))
			ft_chunk_to_zero(head_a, (int)(*head_a)->chunk);
		while (ft_sizeof_chunk(*head_a, (int)(*head_a)->chunk) > 2
				&& !ft_sorted(*head_a, (int)(*head_a)->chunk, 'a'))
			ft_push_chunk_a(head_a, head_b, (int)(*head_a)->chunk, first);
		first = 0;
		if (!ft_sorted(*head_a, (int)(*head_a)->chunk, 'a')
				&& ft_sizeof_chunk(*head_a, (int)(*head_a)->chunk) <= 2)
			ft_sa(head_a, 1);
		if (ft_sorted(*head_a, (int)(*head_a)->chunk, 'a'))
			ft_chunk_to_zero(head_a, (int)(*head_a)->chunk);
		if (*head_b)
			ft_check_b(head_b, head_a);
		if (ft_sorted(*head_a, (int)(*head_a)->chunk, 'a'))
			ft_chunk_to_zero(head_a, (int)(*head_a)->chunk);
	}
}
