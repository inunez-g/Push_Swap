/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:36:45 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:07:21 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	if ((ft_lstsize(*head_a) < 2) && (ft_lstsize(*head_b) < 2))
		return ;
	ft_rra(head_a, 1);
	ft_rrb(head_b, 1);
	write(1, "rrr\n", 4);
}
