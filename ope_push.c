/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:50:30 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:25:08 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_listsize(*give) > 1 && ft_listsize(*take) > 0 */
static void	push_ab_module1(t_node **give, t_node **take)
{
	t_node	*t0;
	t_node	*g0;
	t_node	*g2;

	g0 = (*give)->b;
	g2 = (*give)->n;
	g0->n = g2;
	g2->b = g0;
	t0 = (*take)->b;
	t0->n = (*give);
	(*give)->b = t0;
	(*take)->b = (*give);
	(*give)->n = (*take);
	*take = *give;
	*give = g2;
}

/* ft_listsize(*give) == 1 && ft_listsize(*take) > 0 */
static void	push_ab_module2(t_node **give, t_node **take)
{
	t_node	*t0;

	t0 = (*take)->b;
	t0->n = (*give);
	(*give)->b = (t0);
	(*give)->n = (*take);
	(*take)->b = (*give);
	(*take) = *give;
	(*give) = NULL;
}

/* ft_listsize(*give) >= 1 && ft_listsize(*take) == 0 */
static void	push_ab_module3(t_node **give, t_node **take)
{
	t_node	*g0;
	t_node	*g2;

	if (ft_listsize(*give) == 1)
	{
		*take = *give;
		(*take)->n = *take;
		(*take)->b = *take;
		*give = NULL;
		return ;
	}
	else if (ft_listsize(*give) > 1)
	{
		g0 = (*give)->b;
		g2 = (*give)->n;
		g0->n = g2;
		g2->b = g0;
		(*give)->n = *give;
		(*give)->b = *give;
		*take = *give;
		*give = g2;
		return ;
	}
}

int	push_a(t_node **sa, t_node **sb)
{
	unsigned int	na;
	unsigned int	nb;

	na = ft_listsize(*sa);
	nb = ft_listsize(*sb);
	if (nb == 0)
	{
		write(2, "1opeError\n", 10);
		return (0);
	}
	else if (nb > 1 && na > 0)
		push_ab_module1(sb, sa);
	else if (nb == 1 && na > 0)
		push_ab_module2(sb, sa);
	else if (nb >= 1 && na == 0)
		push_ab_module3(sb, sa);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(t_node **sa, t_node **sb)
{
	unsigned int	na;
	unsigned int	nb;

	na = ft_listsize(*sa);
	nb = ft_listsize(*sb);
	if (na == 0)
	{
		write(2, "2opeError\n", 10);
		return (0);
	}
	else if (na > 1 && nb > 0)
		push_ab_module1(sa, sb);
	else if (na == 1 && nb > 0)
		push_ab_module2(sa, sb);
	else if (na >= 1 && nb == 0)
		push_ab_module3(sa, sb);
	write(1, "pb\n", 3);
	return (1);
}
