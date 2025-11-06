/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_swap_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 07:29:53 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:24:06 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

static t_node	*swap_ab_module(t_node *stk)
{
	t_node	*s0;
	t_node	*s2;
	t_node	*s3;

	if (!stk)
		return (NULL);
	if (ft_listsize(stk) <= 2)
		return (stk->n);
	s0 = stk->b;
	s2 = stk->n;
	s3 = s2->n;
	stk->b = s2;
	stk->n = s3;
	s2->b = s0;
	s2->n = stk;
	s0->n = s2;
	s3->b = stk;
	return (s2);
}

/* This is    swap_ab_module     tester */

//#include <stdio.h>

//int	main(int argc, char **argv)
//{
//	t_node		*stk;
//	t_node		*tmp;

//	stk = NULL;
//	stk = make_node(argc, argv, stk);
//	if (!stk)
//		return (printf("Error"));
//	tmp = stk;
//	printf("size:   %u\n", ft_listsize(stk));
//	printf("stk:  %d\n\n", stk->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->n;
//	while (tmp != stk)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->n;
//	}
//	stk = swap_ab_module(stk);
//	printf("\n\n\nsize:   %u\n", ft_listsize(stk));
//	printf("stk:  %d\n\n", stk->value);
//	printf("value, index\n");
//	tmp = stk;
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->n;
//	while (tmp != stk)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->n;
//	}
//}

void	checker_swap_sa(t_node **sa, t_node **sb)
{
	if (!*sa)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	*sa = swap_ab_module(*sa);
	(void)sa;
	(void)sb;
}

void	checker_swap_sb(t_node **sa, t_node **sb)
{
	if (!*sb)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	*sb = swap_ab_module(*sb);
	(void)sa;
	(void)sb;
}

void	checker_swap_ss(t_node **sa, t_node **sb)
{
	if (!*sa && !*sb)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	*sa = swap_ab_module(*sa);
	*sb = swap_ab_module(*sb);
}
