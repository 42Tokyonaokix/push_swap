/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:02 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 17:13:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	turk_insert_module(t_node **sa, t_node **sb, int na, int nb)
{
	int				rna;
	int				rnb;

	rna = ft_listsize(*sa) - na;
	rnb = ft_listsize(*sb) - nb;
	if (na == INT_MIN)
		return (2);
	if (((na >= nb && na <= rna) || (nb >= na && nb <= rnb)) && na * nb > 0)
		rotate_rr(sa, sb);
	else if (((rna >= rnb && rna <= na)
			|| (rnb >= rna && rnb <= nb)) && na * nb > 0)
		rotate_rrr(sa, sb);
	else if ((nb == 0 || nb - na > rnb) && na <= rna && na > 0)
		rotate_ra(sa, sb);
	else if ((nb == 0 || nb <= rnb - rna) && na > rna && na > 0)
		rotate_rra(sa, sb);
	else if ((na == 0 || na - nb > rna) && nb <= rnb && nb > 0)
		rotate_rb(sa, sb);
	else if ((na == 0 || na <= rna - rnb) && nb > rnb && nb > 0)
		rotate_rrb(sa, sb);
	else if (na == 0 && nb == 0)
		push_b(sa, sb);
	else
		return (0);
	return (1);
}

int	turk_insert(t_node **sa, t_node **sb)
{
	int				na;
	int				nb;

	na = find_cheapest(*sa, *sb);
	nb = rotate_to_insert(*sb, locate_to_index(*sa, na));
	return (turk_insert_module(sa, sb, na, nb));
}

int	reverse_insert_module(t_node **sa, t_node **sb, int na, int nb)
{
	int				la;
	int				lb;

	lb = (int)ft_listsize(*sb);
	la = (int)ft_listsize(*sa);
	if (!*sb)
		return (2);
	else if (nb >= lb - nb && nb > 0 && na >= la - na && na > 0)
		rotate_rr(sa, sb);
	else if (nb <= lb - nb && nb > 0 && na <= la - na && na > 0)
		rotate_rrr(sa, sb);
	else if (nb <= lb - nb && nb > 0 && (na == 0 || na > la - na))
		rotate_rb(sa, sb);
	else if (nb > lb - nb && nb > 0 && na == 0)
		rotate_rrb(sa, sb);
	else if (na <= la - na && na > 0 && (nb == 0 || nb > lb - nb))
		rotate_ra(sa, sb);
	else if (na > la - na && na > 0 && nb == 0)
		rotate_rra(sa, sb);
	else if (nb == 0 && na == 0)
		push_a(sa, sb);
	else
		return (0);
	return (1);
}

int	reverse_insert(t_node **sa, t_node **sb)
{
	unsigned int	max;
	int				nb;
	int				na;
	int				d;
	int				la;

	max = find_largest(*sb);
	nb = find_chunk(*sb, max, max);
	na = rotate_to_reverse(*sa, max);
	d = reverse_insert_module(sa, sb, na, nb);
	if (!d)
		return (0);
	if (d == 1)
		return (1);
	la = ft_listsize(*sa);
	na = find_chunk(*sa, 1, 1);
	if (na <= la - na && na > 0)
		rotate_ra(sa, sb);
	else if (na > la - na && na > 0)
		rotate_rra(sa, sb);
	else if (na == 0)
		return (2);
	return (1);
}
