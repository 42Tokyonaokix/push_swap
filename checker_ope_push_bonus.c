/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_push_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:50:30 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 17:11:17 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
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

void	checker_push_a(t_node **sa, t_node **sb)
{
	unsigned int	na;
	unsigned int	nb;

	na = ft_listsize(*sa);
	nb = ft_listsize(*sb);
	if (nb == 0)
		;
	else if (nb > 1 && na > 0)
		push_ab_module1(sb, sa);
	else if (nb == 1 && na > 0)
		push_ab_module2(sb, sa);
	else if (nb >= 1 && na == 0)
		push_ab_module3(sb, sa);
}

void	checker_push_b(t_node **sa, t_node **sb)
{
	unsigned int	na;
	unsigned int	nb;

	na = ft_listsize(*sa);
	nb = ft_listsize(*sb);
	if (na == 0)
		;
	else if (na > 1 && nb > 0)
		push_ab_module1(sa, sb);
	else if (na == 1 && nb > 0)
		push_ab_module2(sa, sb);
	else if (na >= 1 && nb == 0)
		push_ab_module3(sa, sb);
}

/* This is    push_ab     tester */

//#include <stdio.h>

//void	print_stack(char c, t_node *front)
//{
//	t_node *tmp;

//	if (!front)
//	{
//		printf("%c size: %u\n", c, ft_listsize(front));
//		printf("list: None\n");
//		return ;
//	}
//	tmp = front;
//	printf("%c size: %u\n", c, ft_listsize(front));
//	printf("list:  %3d,", tmp->value);
//	tmp = tmp->n;
//	while (tmp != front)
//	{
//		printf("%-3d,", tmp->value);
//		tmp = tmp->n;
//	}
//	printf("\n\n");
//}
//int	main(int argc, char **argv)
//{
//	t_node		*sa;
//	t_node		*sb;

//	sa = NULL;
//	sb = NULL;
//	sa = make_value_argone(&argv[1], sa);
//	sa = make_index(sa);
//	sb = make_value_argone(&argv[2], sb);
//	sb = make_index(sb);

//	if (!sa && !sb)
//		return (printf("Error\n"));
//	print_stack('a', sa);
//	print_stack('b', sb);
//	printf("\n\n");
//	push_b(&sa, &sb);
//	printf("\n\n");
//	print_stack('a', sa);
//	print_stack('b', sb);
//	(void)argc;
//	(void)argv;
//}
