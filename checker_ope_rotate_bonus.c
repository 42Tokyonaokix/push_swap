/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:36 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/30 23:28:37 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

void	checker_rotate_ra(t_node **afront, t_node **bfront)
{
	(*afront) = (*afront)->after;
	(void)afront;
	(void)bfront;
}

void	checker_rotate_rb(t_node **afront, t_node **bfront)
{
	(*bfront) = (*bfront)->after;
	(void)afront;
	(void)bfront;
}

void	checker_rotate_rr(t_node **afront, t_node **bfront)
{
	(*afront) = (*afront)->after;
	(*bfront) = (*bfront)->after;
}

//#include <stdio.h>

//void	print_stack(char c, t_node *front)
//{
//	t_node	*tmp;

//	if (!front)
//	{
//		printf("%c size: %u\n", c, ft_listsize(front));
//		printf("list: None\n");
//		return ;
//	}
//	tmp = front;
//	printf("%c size:  %u\n", c, ft_listsize(front));
//	printf("list:  %3d,", tmp->value);
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf("%3d,", tmp->value);
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
//	rotate_rr(&afront, &bfront);
//	printf("\n\n");
//	print_stack('a', afront);
//	print_stack('b', bfront);
//	(void)argc;
//	(void)argv;
//}
