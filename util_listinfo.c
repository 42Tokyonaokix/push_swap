/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_listinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:07:32 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 20:01:37 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_chunk_front(t_node *stack_a, unsigned int start, unsigned int end)
{
	t_node	*tmp;
	int		count;

	if (!stack_a)
		return (INT_MIN);
	if (start <= stack_a->index && stack_a->index <= end)
		return (0);
	tmp = stack_a->after;
	count = 1;
	while (tmp != stack_a)
	{
		if (start <= tmp->index && tmp->index <= end)
			return (count);
		count++;
		tmp = tmp->after;
	}
	return (INT_MIN);
}

/* non defined when locate is larger than listsize*/

static bool	insert_is_ok(t_node *stack, unsigned int i)
{
	t_node			*back;

	back = stack->before;
	if (stack->index > back->index
		&& (i > stack->index || back->index > i))
		return (true);
	else if (back->index > i && i > stack->index)
		return (true);
	else
		return (false);

}

int	rotate_to_insert(t_node *stk, unsigned int index)
{
	int		i;
	t_node	*tmp;

	if (ft_listsize(stk) < 2)
		return (0);
	if (insert_is_ok(stk, index))
		return (0);
	tmp = stk->after;
	i = 1;
	while (tmp != stk)
	{
		if (insert_is_ok(tmp, index))
			break ;
		tmp = tmp->after;
		i++;
	}
	return (i);
}

unsigned int	find_largest(t_node *stk)
{
	t_node				*tmp;
	unsigned int		max;

	tmp = stk->after;
	max = stk->index;
	while (tmp != stk)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->after;
	}
	return (max);
}

/*These are rotate_to_insert testers*/



//int	main(int argc, char **argv)
//{
//	t_node			*sa;
//	t_node			*sb;
//	int				l;

//	sa = NULL;
//	sb = NULL;
//	sa = tester_index_node(&argv[1], sa);
//	sb = tester_index_node(&argv[2], sb);
//	if (!sa)
//		return (write(1, "Error\n", 6));
//	l = find_chunk_front(sa, 3, 3);
//	printf("locate: %d\n", l);
//	(void)argc;
//	(void)argv;
//}
