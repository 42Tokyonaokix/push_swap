/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_swap_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 07:29:53 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/30 23:30:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
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

void	checker_swap_sa(t_node **afront, t_node **bfront)
{
	*afront = swap_ab_module(*afront);
	(void)afront;
	(void)bfront;
}

void	checker_swap_sb(t_node **afront, t_node **bfront)
{
	*bfront = swap_ab_module(*bfront);
	(void)afront;
	(void)bfront;
}

void	checker_swap_ss(t_node **afront, t_node **bfront)
{
	*afront = swap_ab_module(*afront);
	*bfront = swap_ab_module(*bfront);
}

/* This is    swap_ss     tester */

//int	main(void)
//{
//	t_node		*afront;
//	t_node		*bfront;
//	t_node		*atmp;
//	t_node		*btmp;
//	char		*str1;
//	char		*str2;

//	afront = NULL;
//	bfront = NULL;
//	str1 = "123 456 789";
//	str2 = NULL;
//	afront = make_value_argone(&str1, afront);
//	afront = make_index(afront);
//	bfront = make_value_argone(&str2, bfront);
//	bfront = make_index(bfront);
//	if (!afront || !bfront)
//		return (printf("Error"));
//	atmp = afront;

//	printf("aaaaaaaaa\nsize:   %u\n", ft_listsize(afront));
//	printf("afront:  %d\n", afront->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//	atmp = atmp->after;
//	while (atmp != afront)
//	{
//		printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//		atmp = atmp->after;
//	}

//	printf("aaaaaaaaa\nbbbbbbbbb\nsize:   %u\n", ft_listsize(bfront));
//	printf("bfront:  %d\n", bfront->value);
//	printf("value, index\n");
//	btmp = bfront;
//	printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//	btmp = btmp->after;
//	while (btmp != bfront)
//	{
//		printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//		btmp = btmp->after;
//	}

//	swap_ss(&afront, &bfront);

//	atmp = afront;
//	printf("bbbbbbbbb\n\naaaaaaaaa\nsize:   %u\n", ft_listsize(afront));
//	printf("afront:  %d\n", afront->value);
//	printf("value, index\n");
//	printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//	atmp = atmp->after;
//	while (atmp != afront)
//	{
//		printf(" %-4d, %-5u\n", atmp->value, atmp->index);
//		atmp = atmp->after;
//	}

//	printf("aaaaaaaaa\nbbbbbbbbb\nsize:   %u\n", ft_listsize(bfront));
//	printf("bfront:  %d\n", bfront->value);
//	printf("value, index\n");
//	btmp = bfront;
//	printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//	btmp = btmp->after;
//	while (btmp != bfront)
//	{
//		printf(" %-4d, %-5u\n", btmp->value, btmp->index);
//		btmp = btmp->after;
//	}
//	printf("bbbbbbbbb\n");
//}
