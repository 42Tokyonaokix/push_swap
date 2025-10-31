/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:36 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 23:36:11 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa = stack_a : sb = stack_b*/
int	rotate_ra(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa))
	{
		write(1, "6OpeError\n", 10);
		return (0);
	}
	(*sa) = (*sa)->after;
	(void)sa;
	(void)sb;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_rb(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sb))
	{
		write(1, "7OpeError\n", 10);
		return (0);
	}
	(*sb) = (*sb)->after;
	(void)sa;
	(void)sb;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_rr(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa) && !ft_listsize(*sb))
	{
		write(1, "8OpeError\n", 10);
		return (0);
	}
	else if (!ft_listsize(*sb))
		(*sa) = (*sa)->after;
	else if (!ft_listsize(*sa))
		(*sb) = (*sb)->after;
	else
	{
		(*sa) = (*sa)->after;
		(*sb) = (*sb)->after;
	}
	write(1, "rr\n", 3);
	return (1);
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
