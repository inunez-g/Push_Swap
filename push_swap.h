/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:11:55 by inunez-g          #+#    #+#             */
/*   Updated: 2021/12/20 11:09:21 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

void		ft_argstolist(int argc, char **argv, t_list **head_a);
void		ft_freelst(t_list *head_a, t_list *head_b);
void		ft_sa(t_list **head_a, int checker);
void		ft_sb(t_list **head_b, int checker);
void		ft_ss(t_list **head_a, t_list **head_b);
void		ft_pb(t_list **head_a, t_list **head_b);
void		ft_pa(t_list **head_a, t_list **head_b);
void		ft_ra(t_list **head_a, int checker);
void		ft_rb(t_list **head_b, int checker);
void		ft_rr(t_list **head_a, t_list **head_b);
void		ft_rra(t_list **head_a, int checker);
void		ft_rrb(t_list **head_b, int checker);
void		ft_rrr(t_list **head_a, t_list **head_b);
int			ft_sorted(t_list *head, int chunk, char list);
void		ft_chunk_to_zero(t_list **head, int chunk);
int			ft_sizeof_chunk(t_list *head, int chunk);
int			ft_set_pivot(t_list **src, int chunk);
void		ft_push_chunk_a(t_list **scr, t_list **dest, int chunk, int first);
void		ft_push_chunk_b(t_list **src, t_list **dest, int chunk);
void		ft_quicksort(t_list **head_a, t_list **head_b);
void		ft_mini_quicksort(t_list **head_a);
int			ft_rr_counter(t_list **src, int rr_counter, int list);
void		ft_check_b(t_list **head_b, t_list **head_a);
int			ft_minipivot(t_list **src);
int			ft_push_nbrs(t_list **src, t_list **dest, int new_chunk, int size);

#endif
