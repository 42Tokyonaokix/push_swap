/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:36 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:26:56 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa = stack_a : sb = stack_b*/
int	rotate_ra(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa))
	{
		write(2, "6opeError\n", 10);
		return (0);
	}
	(*sa) = (*sa)->n;
	(void)sa;
	(void)sb;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_rb(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sb))
	{
		write(2, "7opeError\n", 10);
		return (0);
	}
	(*sb) = (*sb)->n;
	(void)sa;
	(void)sb;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_rr(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa) && !ft_listsize(*sb))
	{
		write(2, "8opeError\n", 10);
		return (0);
	}
	else if (!ft_listsize(*sb))
		(*sa) = (*sa)->n;
	else if (!ft_listsize(*sa))
		(*sb) = (*sb)->n;
	else
	{
		(*sa) = (*sa)->n;
		(*sb) = (*sb)->n;
	}
	write(1, "rr\n", 3);
	return (1);
}
