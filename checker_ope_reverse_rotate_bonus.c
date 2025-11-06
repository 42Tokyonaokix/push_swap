/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_reverse_rotate_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:41:25 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:23:22 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

void	checker_rotate_rra(t_node **sa, t_node **sb)
{
	if (!*sa)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	(*sa) = (*sa)->b;
	(void)sb;
}

void	checker_rotate_rrb(t_node **sa, t_node **sb)
{
	if (!*sb)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	(*sb) = (*sb)->b;
	(void)sa;
}

void	checker_rotate_rrr(t_node **sa, t_node **sb)
{
	if (!*sa && !*sb)
	{
		write(2, "opeError\n", 9);
		return ;
	}
	if (!*sa)
	{
		(*sb) = (*sb)->b;
		return ;
	}
	if (!*sb)
	{
		(*sa) = (*sa)->b;
		return ;
	}
	(*sa) = (*sa)->b;
	(*sb) = (*sb)->b;
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
