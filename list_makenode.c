/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_makenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:22:55 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 17:12:05 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_value_argone(char **format, t_node *front)
{
	long long	tmp_value;
	t_node		*tmp_node;

	if (!format || !*format || !**format)
		return (NULL);
	while (**format)
	{
		tmp_value = ft_atol(format);
		if (tmp_value > INT_MAX || tmp_value < INT_MIN)
			return (NULL);
		tmp_node = ft_listnew(tmp_value);
		if (!front)
			front = tmp_node;
		else
			front = ft_listadd_back(front, tmp_node);
	}
	return (front);
}

/* This is    make_value_argone    tester */

//#include <stdio.h>

//int	main(void)
//{
//	const char	*str;
//	t_node		*front;
//	t_node		*tmp;

//	front = NULL;
//	str = "123 234 345 456 567 678 789 9011";
//	if (!atol_check(str))
//		return (0);
//	front = make_value(&str, front);
//	if (!front)
//		return (0);
//	tmp = front;
//	printf("%u!\n", ft_listsize(front));
//	printf("%d\n", tmp->value);
//	tmp = tmp->before;
//	while (tmp != front)
//	{
//		printf("%d\n", tmp->value);
//		tmp = tmp->before;
//	}
//}

t_node	*make_value_multiarg(int argc, char **argv, t_node *front)
{
	long long	tmp_value;
	t_node		*tmp_node;
	int			index;

	index = 1;
	while (index < argc)
	{
		if (atol_check(argv[index]) != 1)
			return (NULL);
		tmp_value = ft_atol(&argv[index]);
		if (tmp_value > INT_MAX || tmp_value < INT_MIN)
			return (NULL);
		tmp_node = ft_listnew(tmp_value);
		if (!front)
			front = tmp_node;
		else
			front = ft_listadd_back(front, tmp_node);
		index++;
	}
	return (front);
}

/* This is    make_value_multiarg    tester */

//#include <stdio.h>

//int	main(int argc, char **argv)
//{
//	t_node		*front;
//	t_node		*tmp;

//	front = NULL;
//	front = make_value_multiarg(argc, argv, front);
//	if (!front)
//		return (0);
//	tmp = front;
//	printf("%u!\n", ft_listsize(front));
//	printf("%d\n", tmp->value);
//	tmp = tmp->before;
//	while (tmp != front)
//	{
//		printf("%d\n", tmp->value);
//		tmp = tmp->before;
//	}
//}

t_node	*detect_smallest(t_node *front, unsigned int count)
{
	t_node			*smallest;
	t_node			*tmp;

	if (!front)
		return (NULL);
	tmp = front->after;
	if (!front->index)
		smallest = front;
	else
	{
		while (tmp->index)
			tmp = tmp->after;
		smallest = tmp;
	}
	while (tmp != front)
	{
		if (tmp != smallest && tmp->value == smallest->value)
			return (NULL);
		if (!tmp->index && tmp->value < smallest->value)
			smallest = tmp;
		tmp = tmp->after;
	}
	smallest->index = count;
	return (front);
}

t_node	*make_index(t_node *front)
{
	unsigned int	count;
	unsigned int	max;

	count = 1;
	max = ft_listsize(front);
	while (count <= max)
	{
		if (!detect_smallest(front, count))
			return (NULL);
		count++;
	}
	return (front);
}

/* This is    make_index     tester */

//#include <stdio.h>

//int	main(int argc, char **argv)
//{
//	t_node		*front;
//	t_node		*tmp;

//	front = NULL;
//	if (argc == 1)
//		return (printf("Error"));
//	if (argc > 2)
//		front = make_value_multiarg(argc, argv, front);
//	else
//	{
//		if (!atol_check(argv[1]))
//			return (printf("Error"));
//		front = make_value_argone(&argv[1], front);
//	}
//	if (!front)
//		return (printf("Error"));
//	front = make_index(front);
//	if (!front)
//		return (printf("Error"));
//	tmp = front;
//	printf("size:   %u\n", ft_listsize(front));
//	printf("front:  %d\n\n", front->value);
//	printf("value, index\n\n");
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->after;
//	}
//}

t_node	*make_node(int argc, char **argv, t_node *front)
{
	if (argc < 2)
		return (NULL);
	if (argc > 2)
		front = make_value_multiarg(argc, argv, front);
	else
	{
		if (!atol_check(argv[1]))
			return (NULL);
		front = make_value_argone(&argv[1], front);
	}
	if (!front)
		return (NULL);
	front = make_index(front);
	return (front);
}

/* This is    make_node     tester */

//#include <stdio.h>

//int	main(int argc, char **argv)
//{
//	t_node		*front;
//	t_node		*tmp;

//	front = NULL;
//	front = make_node(argc, argv, front);
//	if (!front)
//		return (printf("Error"));
//	tmp = front;
//	printf("size:   %u\n", ft_listsize(front));
//	printf("front:  %d\n\n", front->value);
//	printf("value, index\n\n");
//	printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//	tmp = tmp->after;
//	while (tmp != front)
//	{
//		printf(" %-4d, %-5u\n", tmp->value, tmp->index);
//		tmp = tmp->after;
//	}
//}
