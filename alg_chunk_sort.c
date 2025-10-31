/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_chunk_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:10:02 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/01 00:01:04 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa = stack_a : sb = stack_b : (start,end) = chunk_range */
/*ra = necessary number of ra : rb = same of rb : rrb = same of rrb*/
/*ain = index of variable "ra" location*/
/*return value of "find_check_front" INT_MIN means no*/

int	chunked_insert(t_node **sa, t_node **sb, unsigned int srt, unsigned int end)
{
	int				na;
	unsigned int	ain;
	int				nb;
	int				rnb;

	na = find_chunk_front(*sa, srt, end);
	if (na == INT_MIN)
		return (0);
	ain = locate_to_index(*sa, na);
	nb = rotate_to_insert(*sb, ain);
	rnb = ft_listsize(*sb) - nb;
	if ((na >= nb && nb > 0) || (nb > na && rnb >= nb - na && na > 0))
		rotate_rr(sa, sb);
	else if ((nb >= na && rnb < nb - na && na > 0) || (na > 0 && nb == 0))
		rotate_ra(sa, sb);
	else if (na == 0 && nb == 0)
		push_b(sa, sb);
	else if (na == 0 && nb <= rnb)
		rotate_rb(sa, sb);
	else if (na == 0 && nb > rnb)
		rotate_rrb(sa, sb);
	else
		return (-1);
	return (1);
}

int	whole_insert(t_node **sa, t_node **sb)
{
	unsigned int	srt;
	int				l;
	int				count;
	unsigned int	size;

	size = ft_listsize(*sa);
	srt = 1;
	count = 0;
	while (srt <= size)
	{
		l = 1;
		while (l > 0)
		{
			l = chunked_insert(sa, sb, srt, srt + 28);
			count++;
		}
		srt += 29;
	}
	return (count);
}

int	reverse_insert(t_node **sa, t_node **sb)
{
	unsigned int	max;
	int				loc;
	int				size;

	max = find_largest(*sb);
	loc = find_chunk_front(*sb, max, max);
	size = (int)ft_listsize(*sb);
	if (loc >= size - loc)
		while (size-- >= loc)
			rotate_rb(sa, sb);
	else
		while (loc-- >= 0)
			rotate_rrb(sa, sb);

	while (size >= 0)
	{
		push_a(sa, sb);
		size--;
	}

	return (loc + size);
}

/*choose_operate tester*/

//#include <stdio.h>

//void	print_stack(char c, t_node *stack)
//{
//	t_node	*tmp;

//	if (!stack)
//	{
//		printf("%c: None\n", c);
//		return ;
//	}
//	tmp = stack;
//	printf ("%c:%3d,", c, tmp->index);
//	tmp = tmp->after;
//	while (tmp != stack)
//	{
//		printf("%3d,", tmp->index);
//		tmp = tmp->after;
//	}
//	printf("\n\n");
//}

//int	main(int argc, char **argv)
//{
//	t_node			*sa;
//	t_node			*sb;
//	int				l;
//	int				count;

//	sa = NULL;
//	sb = NULL;
//	sa = make_node(argc, argv, sa);
//	if (!sa)
//		return (write(1, "Error\n", 7));
//	print_stack('a', sa);
//	print_stack('b', sb);
//	l = 1;
//	count = whole_insert(&sa, &sb);
//	count += reverse_insert(&sa, &sb);
//	print_stack('a', sa);
//	print_stack('b', sb);
//	printf("\n%d", count);
//	(void)argc;
//	(void)argv;
//}
