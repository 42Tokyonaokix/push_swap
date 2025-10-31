/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:11:09 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 17:08:38 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_manage(t_node **stack_a, t_node **stack_b, size_t func)
{
	if (func == 0)
		return ;
	else if (func == 1)
		swap_sa(stack_a, stack_b);
	else if (func == 2)
		swap_sb(stack_a, stack_b);
	else if (func == 3)
		swap_ss(stack_a, stack_b);
	else if (func == 4)
		push_a(stack_a, stack_b);
	else if (func == 5)
		push_b(stack_a, stack_b);
	else if (func == 6)
		rotate_ra(stack_a, stack_b);
	else if (func == 7)
		rotate_rb(stack_a, stack_b);
	else if (func == 8)
		rotate_rr(stack_a, stack_b);
	else if (func == 9)
		rotate_rra(stack_a, stack_b);
	else if (func == 10)
		rotate_rrb(stack_a, stack_b);
	else if (func == 11)
		rotate_rrr(stack_a, stack_b);
}

size_t	detect_function(char *display)
{
	if (!ft_strcmp(display, "sa\n"))
		return (1);
	else if (!ft_strcmp(display, "sb\n"))
		return (2);
	else if (!ft_strcmp(display, "ss\n"))
		return (3);
	else if (!ft_strcmp(display, "pa\n"))
		return (4);
	else if (!ft_strcmp(display, "pb\n"))
		return (5);
	else if (!ft_strcmp(display, "ra\n"))
		return (6);
	else if (!ft_strcmp(display, "rb\n"))
		return (7);
	else if (!ft_strcmp(display, "rr\n"))
		return (8);
	else if (!ft_strcmp(display, "rra\n"))
		return (9);
	else if (!ft_strcmp(display, "rrb\n"))
		return (10);
	else if (!ft_strcmp(display, "rrr\n"))
		return (11);
	else if (!display)
		return (12);
	return (0);
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
//	read_stdin(&afront, &bfront);
//	printf("\n\n");
//	print_stack('a', afront);
//	print_stack('b', bfront);
//	(void)argc;
//	(void)argv;
//}
