/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 07:29:53 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 17:59:10 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*swap_ab_module(t_node *front)
{
	t_node	*zero;
	t_node	*second;
	t_node	*third;

	if (!front)
		return (NULL);
	if (ft_listsize(front) <= 2)
		return (front->after);
	zero = front->before;
	second = front->after;
	third = second->after;
	front->before = second;
	front->after = third;
	second->before = zero;
	second->after = front;
	zero->after = second;
	third->before = front;
	return (second);
}

/* This is    swap_ab_module     tester */

//#include <stdio.h>

//int	main(int argc, char **argv)
//{
//	t_node		*front;
//	t_node		*tmp;

//	front = NULL;
//	front = make_node(argc, argv, front);
//	if (!front)
//		return (printf("Error"));
//	tmp = front;
//	printf("size:   %u\n", ft_listsize(front));
//	printf("front:  %d\n\n", front->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->after;
//	}
//	front = swap_ab_module(front);
//	printf("\n\n\nsize:   %u\n", ft_listsize(front));
//	printf("front:  %d\n\n", front->value);
//	printf("value, index\n");
//	tmp = front;
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->after;
//	}
//}

int	swap_sa(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sa) < 2)
	{
		write(1, "OpeError\n", 9);
		return (0);
	}
	*sa = swap_ab_module(*sa);
	(void)sa;
	(void)sb;
	write(1, "sa\n", 3);
	return (1);
}

int	swap_sb(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sb) < 2)
	{
		write(1, "OpeError\n", 9);
		return (0);
	}
	*sb = swap_ab_module(*sb);
	(void)sa;
	(void)sb;
	write(1, "sb\n", 3);
	return (1);
}

int	swap_ss(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sa) < 2 && ft_listsize(*sb) < 2)
	{
		write(1, "OpeError\n", 9);
		return (0);
	}
	if (ft_listsize(*sa) < 2)
		*sb = swap_ab_module(*sb);
	if (ft_listsize(*sb) < 2)
		*sb = swap_ab_module(*sa);
	else
	{
		*sa = swap_ab_module(*sa);
		*sb = swap_ab_module(*sb);
	}

	(void)sa;
	(void)sb;
	write(1, "ss\n", 3);
	return (1);
}

/* This is    swap_ss     tester */

//int	main(void)
//{
//	t_node		*sa;
//	t_node		*sb;
//	t_node		*atmp;
//	t_node		*btmp;
//	char		*str1;
//	char		*str2;

//	sa = NULL;
//	sb = NULL;
//	str1 = "123 456 789";
//	str2 = NULL;
//	sa = make_value_argone(&str1, sa);
//	sa = make_index(sa);
//	sb = make_value_argone(&str2, sb);
//	sb = make_index(sb);
//	if (!sa || !sb)
//		return (printf("Error"));
//	atmp = sa;

//	printf("aaaaaaaaa\nsize:   %u\n", ft_listsize(sa));
//	printf("sa:  %d\n", sa->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//	atmp = atmp->after;
//	while (atmp != sa)
//	{
//		printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//		atmp = atmp->after;
//	}

//	printf("aaaaaaaaa\nbbbbbbbbb\nsize:   %u\n", ft_listsize(sb));
//	printf("sb:  %d\n", sb->value);
//	printf("value, index\n");
//	btmp = sb;
//	printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//	btmp = btmp->after;
//	while (btmp != sb)
//	{
//		printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//		btmp = btmp->after;
//	}

//	swap_ss(&sa, &sb);

//	atmp = sa;
//	printf("bbbbbbbbb\n\naaaaaaaaa\nsize:   %u\n", ft_listsize(sa));
//	printf("sa:  %d\n", sa->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//	atmp = atmp->after;
//	while (atmp != sa)
//	{
//		printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//		atmp = atmp->after;
//	}

//	printf("aaaaaaaaa\nbbbbbbbbb\nsize:   %u\n", ft_listsize(sb));
//	printf("sb:  %d\n", sb->value);
//	printf("value, index\n");
//	btmp = sb;
//	printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//	btmp = btmp->after;
//	while (btmp != sb)
//	{
//		printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//		btmp = btmp->after;
//	}
//	printf("bbbbbbbbb\n");
//}
