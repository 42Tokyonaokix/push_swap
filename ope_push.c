/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:50:30 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 23:34:30 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_listsize(*from) > 1 && ft_listsize(*to) > 0 */
static void	push_ab_module1(t_node **from, t_node **to)
{
	t_node	*to_0;
	t_node	*from_0;
	t_node	*from_2;

	from_0 = (*from)->before;
	from_2 = (*from)->after;
	from_0->after = from_2;
	from_2->before = from_0;
	to_0 = (*to)->before;
	to_0->after = (*from);
	(*from)->before = to_0;
	(*to)->before = (*from);
	(*from)->after = (*to);
	*to = *from;
	*from = from_2;
}

/* ft_listsize(*from) == 1 && ft_listsize(*to) > 0 */
static void	push_ab_module2(t_node **from, t_node **to)
{
	t_node	*to_0;

	to_0 = (*to)->before;
	to_0->after = (*from);
	(*from)->before = (to_0);
	(*from)->after = (*to);
	(*to)->before = (*from);
	(*to) = *from;
	(*from) = NULL;
}

/* ft_listsize(*from) >= 1 && ft_listsize(*to) == 0 */
static void	push_ab_module3(t_node **from, t_node **to)
{
	t_node	*from_0;
	t_node	*from_2;

	if (ft_listsize(*from) == 1)
	{
		*to = *from;
		*from = NULL;
		return ;
	}
	else if (ft_listsize(*from) > 1)
	{
		from_0 = (*from)->before;
		from_2 = (*from)->after;
		from_0->after = from_2;
		from_2->before = from_0;
		(*from)->after = *from;
		(*from)->before = *from;
		*to = *from;
		*from = from_2;
		return ;
	}
}

int	push_a(t_node **afront, t_node **bfront)
{
	unsigned int	asize;
	unsigned int	bsize;

	asize = ft_listsize(*afront);
	bsize = ft_listsize(*bfront);
	if (bsize == 0)
	{
		write(1, "1OpeError\n", 10);
		return (0);
	}
	else if (bsize > 1 && asize > 0)
		push_ab_module1(bfront, afront);
	else if (bsize == 1 && asize > 0)
		push_ab_module2(bfront, afront);
	else if (bsize >= 1 && asize == 0)
		push_ab_module3(bfront, afront);
	write(1, "pa\n", 3);
	return (1);
}

int	push_b(t_node **afront, t_node **bfront)
{
	unsigned int	asize;
	unsigned int	bsize;

	asize = ft_listsize(*afront);
	bsize = ft_listsize(*bfront);
	if (asize == 0)
	{
		write(1, "2OpeError\n", 10);
		return (0);
	}
	else if (asize > 1 && bsize > 0)
		push_ab_module1(afront, bfront);
	else if (asize == 1 && bsize > 0)
		push_ab_module2(afront, bfront);
	else if (asize >= 1 && bsize == 0)
		push_ab_module3(afront, bfront);
	write(1, "pb\n", 3);
	return (1);
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
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf("%-3d,", tmp->value);
//		tmp = tmp->after;
//	}
//	printf("\n\n");
//}
//int	main(int argc, char **argv)
//{
//	t_node		*afront;
//	t_node		*bfront;

//	afront = NULL;
//	bfront = NULL;
//	afront = make_value_argone(&argv[1], afront);
//	afront = make_index(afront);
//	bfront = make_value_argone(&argv[2], bfront);
//	bfront = make_index(bfront);

//	if (!afront && !bfront)
//		return (printf("Error\n"));
//	print_stack('a', afront);
//	print_stack('b', bfront);
//	printf("\n\n");
//	push_b(&afront, &bfront);
//	printf("\n\n");
//	print_stack('a', afront);
//	print_stack('b', bfront);
//	(void)argc;
//	(void)argv;
//}
