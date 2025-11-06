/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ope_manage_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:11:09 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:23:05 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_push_swap_bonus.h"
#include "push_swap.h"

//size_t	detect_function(char *display)
//{
//	if (!ft_strcmp(display, "sa\n"))
//		return (1);
//	else if (!ft_strcmp(display, "sb\n"))
//		return (2);
//	else if (!ft_strcmp(display, "ss\n"))
//		return (3);
//	else if (!ft_strcmp(display, "pa\n"))
//		return (4);
//	else if (!ft_strcmp(display, "pb\n"))
//		return (5);
//	else if (!ft_strcmp(display, "ra\n"))
//		return (6);
//	else if (!ft_strcmp(display, "rb\n"))
//		return (7);
//	else if (!ft_strcmp(display, "rr\n"))
//		return (8);
//	else if (!ft_strcmp(display, "rra\n"))
//		return (9);
//	else if (!ft_strcmp(display, "rrb\n"))
//		return (10);
//	else if (!ft_strcmp(display, "rrr\n"))
//		return (11);
//	else if (!display)
//		return (12);
//	return (0);
//}

bool	checker_operation_manage(t_node **sa, t_node **sb, char *display)
{
	if (!ft_strcmp(display, "sa\n"))
		checker_swap_sa(sa, sb);
	else if (!ft_strcmp(display, "sb\n"))
		checker_swap_sb(sa, sb);
	else if (!ft_strcmp(display, "ss\n"))
		checker_swap_ss(sa, sb);
	else if (!ft_strcmp(display, "pa\n"))
		checker_push_a(sa, sb);
	else if (!ft_strcmp(display, "pb\n"))
		checker_push_b(sa, sb);
	else if (!ft_strcmp(display, "ra\n"))
		checker_rotate_ra(sa, sb);
	else if (!ft_strcmp(display, "rb\n"))
		checker_rotate_rb(sa, sb);
	else if (!ft_strcmp(display, "rr\n"))
		checker_rotate_rr(sa, sb);
	else if (!ft_strcmp(display, "rra\n"))
		checker_rotate_rra(sa, sb);
	else if (!ft_strcmp(display, "rrb\n"))
		checker_rotate_rrb(sa, sb);
	else if (!ft_strcmp(display, "rrr\n"))
		checker_rotate_rrr(sa, sb);
	else
		return (false);
	return (true);
}

bool	read_stdin(t_node **sa, t_node **sb)
{
	char			*display;

	while (true)
	{
		display = get_next_line(0);
		if (!display)
			return (true);
		if (!checker_operation_manage(sa, sb, display))
			return (false);
		free(display);
	}
	return (true);
}

int	judge(t_node *sa, t_node *sb)
{
	unsigned int	index;
	unsigned int	max;
	t_node			*tmp;

	if (sb)
		return (write(1, "KO\n", 3));
	if (1 != sa->i)
		return (write(1, "KO\n", 3));
	tmp = sa->n;
	max = ft_listsize(sa);
	index = 2;
	while (index <= max)
	{
		if (tmp->i != index)
			return (write(1, "KO\n", 3));
		index++;
		tmp = tmp->n;
	}
	return (write(1, "OK\n", 3));
}

int	main(int argc, char **argv)
{
	t_node		*sa;
	t_node		*sb;

	sa = NULL;
	sb = NULL;
	if (argc == 2)
		sa = make_value_argone(&argv[1], sa);
	else
		sa = make_value_multiarg(argc, argv, sa);
	sa = make_index(sa);
	if (!sa)
		return (write(2, "Error\n", 6));
	if (!read_stdin(&sa, &sb))
		return (write(2, "Error\n", 6));
	judge(sa, sb);
	(void)argc;
	(void)argv;
}
