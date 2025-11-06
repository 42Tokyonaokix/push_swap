/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:41:25 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:26:42 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rra(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa))
	{
		write(2, "3opeError\n", 10);
		return (0);
	}
	(*sa) = (*sa)->b;
	(void)sa;
	(void)sb;
	write(1, "rra\n", 4);
	return (1);
}

int	rotate_rrb(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sb))
	{
		write(2, "4opeError\n", 10);
		return (0);
	}
	(*sb) = (*sb)->b;
	(void)sa;
	(void)sb;
	write(1, "rrb\n", 4);
	return (1);
}

int	rotate_rrr(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa) && !ft_listsize(*sb))
	{
		write(2, "5opeError\n", 10);
		return (0);
	}
	else if (!ft_listsize(*sa))
		(*sb) = (*sb)->b;
	else if (!ft_listsize(*sb))
		(*sa) = (*sa)->b;
	else
	{
		(*sa) = (*sa)->b;
		(*sb) = (*sb)->b;
	}
	write(1, "rrr\n", 4);
	return (1);
}
