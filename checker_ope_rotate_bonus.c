/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:36 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 20:19:54 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

void	checker_rotate_ra(t_node **sa, t_node **sb)
{
	if (!*sa)
		;
	else
		(*sa) = (*sa)->n;
	(void)sa;
	(void)sb;
}

void	checker_rotate_rb(t_node **sa, t_node **sb)
{
	if (!*sb)
		;
	else
		(*sb) = (*sb)->n;
	(void)sa;
	(void)sb;
}

void	checker_rotate_rr(t_node **sa, t_node **sb)
{
	if (!*sa && !*sb)
		;
	else if (!*sa)
	{
		(*sb) = (*sb)->n;
		return ;
	}
	else if (!*sb)
	{
		(*sa) = (*sa)->n;
		return ;
	}
	else
	{
		(*sa) = (*sa)->n;
		(*sb) = (*sb)->n;
	}
}
