/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_manage_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:11:09 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 04:51:00 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

bool	checker_operation_manage(t_node **afront, t_node **bfront, size_t func)
{
	if (func == 0)
		return (false);
	else if (func == 1)
		checker_swap_sa(afront, bfront);
	else if (func == 2)
		checker_swap_sb(afront, bfront);
	else if (func == 3)
		checker_swap_ss(afront, bfront);
	else if (func == 4)
		checker_push_a(afront, bfront);
	else if (func == 5)
		checker_push_b(afront, bfront);
	else if (func == 6)
		checker_rotate_ra(afront, bfront);
	else if (func == 7)
		checker_rotate_rb(afront, bfront);
	else if (func == 8)
		checker_rotate_rr(afront, bfront);
	else if (func == 9)
		checker_rotate_rra(afront, bfront);
	else if (func == 10)
		checker_rotate_rrb(afront, bfront);
	else if (func == 11)
		checker_rotate_rrr(afront, bfront);
	return (true);
}

bool	read_stdin(t_node **afront, t_node **bfront)
{
	size_t	func;
	size_t	len;
	char	*display;

	len = 1;
	while (len)
	{
		display = get_next_line(0);
		len = ft_strlen(display);
		func = detect_function(display);
		free(display);
		if (!checker_operation_manage(afront, bfront, func))
			return (false);
	}
	return (true);
}

int	judge(t_node *afront, t_node *bfront)
{
	unsigned int	index;
	unsigned int	max;
	t_node			*tmp;

	if (bfront)
		return (write(1, "KO\n", 3));
	if (1 != afront->index)
		return (write(1, "KO\n", 3));
	tmp = afront->after;
	max = ft_listsize(afront);
	index = 2;
	while (index <= max)
	{
		if (tmp->index != index)
			return (write(1, "KO\n", 3));
		index++;
		tmp = tmp->after;
	}
	return (write(1, "OK\n", 3));
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
//	if (argc == 2)
//		afront = make_value_argone(&argv[1], afront);
//	else
//		afront = make_value_multiarg(argc, argv, afront);
//	afront = make_index(afront);
//	if (!afront)
//		return (write(1, "Error\n", 6));
//	if (!read_stdin(&afront, &bfront))
//		return (write(1, "Error\n", 6));
//	judge(afront, bfront);
//	(void)argc;
//	(void)argv;
//}
