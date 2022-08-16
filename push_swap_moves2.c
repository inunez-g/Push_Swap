/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:04:22 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:07:19 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **head_a, int checker)
{
	t_list	*s_buff;

	if (ft_lstsize(*head_a) < 2)
		return ;
	s_buff = *head_a;
	*head_a = s_buff->next;
	s_buff->next = NULL;
	ft_lstadd_back(head_a, s_buff);
	if (checker == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **head_b, int checker)
{
	t_list	*s_buff;

	if (ft_lstsize(*head_b) < 2)
		return ;
	s_buff = *head_b;
	*head_b = s_buff->next;
	s_buff->next = NULL;
	ft_lstadd_back(head_b, s_buff);
	if (checker == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	if ((ft_lstsize(*head_a) < 2) && (ft_lstsize(*head_b) < 2))
		return ;
	ft_ra(head_a, 1);
	ft_rb(head_b, 1);
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **head_a, int checker)
{
	t_list	*s_buff;
	t_list	*f_buff;

	if (ft_lstsize(*head_a) < 2)
		return ;
	f_buff = *head_a;
	s_buff = *head_a;
	while (f_buff->next != NULL)
		f_buff = f_buff->next;
	while (s_buff->next != f_buff)
		s_buff = s_buff->next;
	s_buff->next = NULL;
	f_buff->next = *head_a;
	*head_a = f_buff;
	if (checker == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **head_b, int checker)
{
	t_list	*s_buff;
	t_list	*f_buff;

	if (ft_lstsize(*head_b) < 2)
		return ;
	f_buff = *head_b;
	s_buff = *head_b;
	while (f_buff->next != NULL)
		f_buff = f_buff->next;
	while (s_buff->next != f_buff)
		s_buff = s_buff->next;
	s_buff->next = NULL;
	f_buff->next = *head_b;
	*head_b = f_buff;
	if (checker == 0)
		write(1, "rrb\n", 4);
}
