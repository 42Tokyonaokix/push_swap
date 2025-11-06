/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_make_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:54:57 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 17:08:04 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_push_swap_bonus.h"

t_node	*ft_listnew(int value)
{
	t_node	*newlist;

	newlist = (t_node *)malloc(sizeof(t_node));
	if (newlist == NULL)
		return (NULL);
	newlist->v = value;
	newlist->i = 0;
	newlist->lis = false;
	newlist->n = newlist;
	newlist->b = newlist;
	return (newlist);
}

t_node	*ft_listadd_back(t_node *lst, t_node *new)
{
	t_node	*last;

	if (!lst)
		return (new);
	last = lst->b;
	new->n = lst;
	new->b = last;
	last->n = new;
	lst->b = new;
	return (lst);
}

void	ft_listclear(t_node *lst)
{
	t_node	*tmp;
	int		size;
	int		count;

	if (!lst)
		return ;
	size = ft_listsize(lst);
	count = 0;
	tmp = lst;
	while (count < size)
	{
		tmp = tmp->n;
		free(lst);
		lst = NULL;
		lst = tmp;
		count++;
	}
}

unsigned int	ft_listsize(t_node *lst)
{
	t_node			*tmp;
	unsigned int	count;

	if (!lst)
		return (0);
	tmp = lst->n;
	count = 1;
	while (tmp && tmp != lst)
	{
		tmp = tmp->n;
		count++;
	}
	return (count);
}

unsigned int	locate_to_index(t_node *lst, int locate)
{
	t_node	*tmp;
	int		count;

	if (!lst)
		return (INT_MAX);
	if (locate == 0)
		return (lst->i);
	if (locate < 0)
		locate = ft_listsize(lst) + locate;
	count = 0;
	tmp = lst;
	while (count < locate)
	{
		tmp = tmp->n;
		count++;
	}
	return (tmp->i);
}
