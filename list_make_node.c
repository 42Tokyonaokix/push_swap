/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_make_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:22:55 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 21:49:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_value_argone(char **arg, t_node *stk)
{
	long long	tmp_v;
	t_node		*tmp_n;

	if (!arg || !*arg || !**arg)
		return (NULL);
	while (**arg)
	{
		tmp_v = ft_atol(arg);
		if (tmp_v > INT_MAX || tmp_v < INT_MIN)
			return (NULL);
		tmp_n = ft_listnew(tmp_v);
		if (!tmp_n)
			return (ft_listclear(stk), NULL);
		if (!stk)
			stk = tmp_n;
		else
			stk = ft_listadd_back(stk, tmp_n);
	}
	return (stk);
}

t_node	*make_value_multiarg(int argc, char **argv, t_node *stk)
{
	long long	tmp_v;
	t_node		*tmp_n;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (count_number(argv[i]) != 1)
			return (ft_listclear(stk), NULL);
		tmp_v = ft_atol(&argv[i]);
		if (tmp_v > INT_MAX || tmp_v < INT_MIN)
			return (NULL);
		tmp_n = ft_listnew(tmp_v);
		if (!tmp_n)
			return (ft_listclear(stk), NULL);
		if (!stk)
			stk = tmp_n;
		else
			stk = ft_listadd_back(stk, tmp_n);
		i++;
	}
	return (stk);
}

t_node	*detect_smallest(t_node *stk, unsigned int index)
{
	t_node			*min;
	t_node			*tmp;

	if (!stk)
		return (NULL);
	tmp = stk->n;
	if (!stk->i)
		min = stk;
	else
	{
		while (tmp->i)
			tmp = tmp->n;
		min = tmp;
	}
	while (tmp != stk)
	{
		if (tmp != min && tmp->v == min->v)
			return (NULL);
		if (!tmp->i && tmp->v < min->v)
			min = tmp;
		tmp = tmp->n;
	}
	min->i = index;
	return (stk);
}

t_node	*make_index(t_node *stk)
{
	unsigned int	count;
	unsigned int	max;

	count = 1;
	max = ft_listsize(stk);
	while (count <= max)
	{
		if (!detect_smallest(stk, count))
		{
			ft_listclear(stk);
			return (NULL);
		}
		count++;
	}
	return (stk);
}

t_node	*make_node(int argc, char **argv, t_node *stk)
{
	if (argc < 2)
		return (NULL);
	if (argc > 2)
		stk = make_value_multiarg(argc, argv, stk);
	else
	{
		if (!count_number(argv[1]))
			return (NULL);
		stk = make_value_argone(&argv[1], stk);
	}
	if (!stk)
		return (NULL);
	stk = make_index(stk);
	return (stk);
}
