/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:41:25 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 23:35:55 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rra(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa))
	{
		write(1, "3OpeError\n", 10);
		return (0);
	}
	(*sa) = (*sa)->before;
	(void)sa;
	(void)sb;
	write(1, "rra\n", 4);
	return (1);
}

int	rotate_rrb(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sb))
	{
		write(1, "4peError\n", 10);
		return (0);
	}
	(*sb) = (*sb)->before;
	(void)sa;
	(void)sb;
	write(1, "rrb\n", 4);
	return (1);
}

int	rotate_rrr(t_node **sa, t_node **sb)
{
	if (!ft_listsize(*sa) && !ft_listsize(*sb))
	{
		write(1, "5OpeError\n", 10);
		return (0);
	}
	else if (!ft_listsize(*sa))
		(*sb) = (*sb)->before;
	else if (!ft_listsize(*sb))
		(*sa) = (*sa)->before;
	else
	{
		(*sa) = (*sa)->before;
		(*sb) = (*sb)->before;
	}
	write(1, "rrr\n", 4);
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
//	rotate_rrr(&sa, &sb);
//	rotate_rrr(&sa, &sb);
//	printf("\n\n");
//	print_stack('a', sa);
//	print_stack('b', sb);
//	(void)argc;
//	(void)argv;
//}
