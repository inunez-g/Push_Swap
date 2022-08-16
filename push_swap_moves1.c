/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:05:25 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:07:17 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head_a, int checker)
{
	t_list	*buff;

	if (ft_lstsize(*head_a) < 2)
		return ;
	buff = (*head_a)->next;
	(*head_a)->next = buff->next;
	buff->next = *head_a;
	*head_a = buff;
	if (checker == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **head_b, int checker)
{
	t_list	*buff;

	if (ft_lstsize(*head_b) < 2)
		return ;
	buff = (*head_b)->next;
	(*head_b)->next = buff->next;
	buff->next = *head_b;
	*head_b = buff;
	if (checker == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*f_buff;
	t_list	*s_buff;

	if (ft_lstsize(*head_a) <= 0)
		return ;
	f_buff = *head_a;
	s_buff = (*head_a)->next;
	*head_a = s_buff;
	ft_lstadd_front(head_b, f_buff);
	write(1, "pb\n", 3);
}

void	ft_pa(t_list **head_b, t_list **head_a)
{
	t_list	*f_buff;
	t_list	*s_buff;

	if (ft_lstsize(*head_b) <= 0)
		return ;
	f_buff = *head_b;
	s_buff = (*head_b)->next;
	*head_b = s_buff;
	ft_lstadd_front(head_a, f_buff);
	write(1, "pa\n", 3);
}
