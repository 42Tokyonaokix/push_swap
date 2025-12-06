/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:44:37 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 21:37:32 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	whole_turk_insert(t_node **sa, t_node **sb)
{
	int	count;
	int	l;

	count = 0;
	while (true)
	{
		l = turk_insert(sa, sb);
		if (l == 0)
			return (INT_MIN);
		if (!*sa)
			break ;
		count++;
	}
	return (count);
}

int	whole_reverse(t_node **sa, t_node **sb)
{
	int	count;
	int	l;

	count = 0;
	while (true)
	{
		l = reverse_insert(sa, sb);
		if (l == 0)
			return (INT_MIN);
		if (l == 2)
			return (count);
		count++;
	}
	return (count);
}

int	is_sorted(t_node *sa)
{
	t_node			*tmp;
	unsigned int	index;

	if (sa == sa->n)
		return (0);
	tmp = sa->n;
	index = 2;
	while (tmp != sa)
	{
		if (index != tmp->i)
			return (1);
		index++;
		tmp = tmp->n;
	}
	return (0);
}

int	algorithm(t_node **sa, t_node **sb)
{
	int	size;
	int	count;

	size = ft_listsize(*sa);
	if (size == 2)
		count = rotate_ra(sa, sb);
	else if (size == 3)
		count = sort3(sa, sb);
	else if (size < 6)
		count = sort5(sa, sb);
	else
	{
		count = whole_turk_insert(sa, sb);
		count += whole_reverse(sa, sb);
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_node			*sa;
	t_node			*sb;
	int				count;

	sa = NULL;
	sb = NULL;
	if (argc < 2)
		return (0);
	sa = make_node(argc, argv, sa);
	if (!sa)
	{
		ft_listclear(sa);
		write(2, "Error\n", 7);
		return (1);
	}
	if (!is_sorted(sa))
	{
		ft_listclear(sa);
		return (0);
	}
	count = algorithm(&sa, &sb);
	ft_listclear(sa);
	ft_listclear(sb);
	return (0);
}
