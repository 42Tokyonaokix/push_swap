/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:24:43 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/01 22:58:03 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_BONUS_H
# define CHECKER_PUSH_SWAP_BONUS_H

# include "push_swap.h"

void			checker_swap_sa(t_node **sa, t_node **sb);
void			checker_swap_sb(t_node **sa, t_node **sb);
void			checker_swap_ss(t_node **sa, t_node **sb);
void			checker_push_a(t_node **sa, t_node **sb);
void			checker_push_b(t_node **sa, t_node **sb);
void			checker_rotate_ra(t_node **sa, t_node **sb);
void			checker_rotate_rb(t_node **sa, t_node **sb);
void			checker_rotate_rr(t_node **sa, t_node **sb);
void			checker_rotate_rra(t_node **sa, t_node **sb);
void			checker_rotate_rrb(t_node **sa, t_node **sb);
void			checker_rotate_rrr(t_node **sa, t_node **sb);

bool			read_stdin(t_node **sa, t_node **sb);
int				judge(t_node *sa, t_node *sb);

#endif