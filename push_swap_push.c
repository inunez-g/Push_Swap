/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:48:45 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:10:45 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunk_a(t_list **src, t_list **dest, int chunk, int first)
{
	int			pivot;
	int			size;
	static int	new_chunk;
	int			rra_counter;

	rra_counter = 0;
	if (!new_chunk)
		new_chunk = 1;
	pivot = ft_set_pivot(src, chunk);
	if (ft_sizeof_chunk(*src, chunk) == 5)
		size = 2;
	else
		size = ft_sizeof_chunk(*src, chunk) - ft_sizeof_chunk(*src, chunk) / 2;
	while ((*src) && (*src)->chunk == chunk && size > 0)
	{
		if ((int)(*src)->content < pivot)
			size = ft_push_nbrs(src, dest, new_chunk, size);
		else
			rra_counter = ft_rr_counter(src, rra_counter, 0);
	}
	if (ft_lstsize(*src) == 3 && !ft_sorted(*src, (int)(*src)->chunk, 'a'))
		ft_mini_quicksort(src);
	while (--rra_counter >= 0 && !first)
		ft_rra(src, 0);
	new_chunk++;
}

void	ft_push_chunk_b(t_list **src, t_list **dest, int chunk)
{
	int			pivot;
	int			size;
	static int	new_chunk;
	int			rrb_counter;

	rrb_counter = 0;
	if (!new_chunk)
		new_chunk = 1;
	pivot = ft_set_pivot(src, chunk);
	size = ft_sizeof_chunk(*src, chunk) / 2;
	while ((*src) && (*src)->chunk == chunk && size)
	{
		if ((int)(*src)->content >= pivot)
		{
			(*src)->chunk = new_chunk;
			ft_pa(src, dest);
			size--;
		}			
		else
			rrb_counter = ft_rr_counter(src, rrb_counter, 1);
	}
	while (--rrb_counter >= 0)
		ft_rrb(src, 0);
	new_chunk++;
}

int	ft_rr_counter(t_list **src, int rr_counter, int list)
{
	if (list == 0)
	{
		ft_ra(src, 0);
		rr_counter++;
	}
	else
	{
		ft_rb(src, 0);
		rr_counter++;
	}
	return (rr_counter);
}

void	ft_check_b(t_list **head_b, t_list **head_a)
{
	int	chunk;

	if (ft_sorted(*head_b, (int)(*head_b)->chunk, 'b'))
	{
		chunk = (int)(*head_b)->chunk;
		while (*head_b && (int)(*head_b)->chunk == chunk)
			ft_pa(head_b, head_a);
	}
	else if (ft_sizeof_chunk(*head_b, (int)(*head_b)->chunk) == 2)
	{
		ft_sb(head_b, 1);
		chunk = (int)(*head_b)->chunk;
		while (*head_b && (int)(*head_b)->chunk == chunk)
			ft_pa(head_b, head_a);
	}
	else if (ft_sizeof_chunk(*head_b, (int)(*head_b)->chunk) > 2)
		ft_push_chunk_b(head_b, head_a, (int)(*head_b)->chunk);
}

int	ft_push_nbrs(t_list **src, t_list **dest, int new_chunk, int size)
{
	(*src)->chunk = new_chunk;
	ft_pb(src, dest);
	size--;
	return (size);
}
