/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_makenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:54:57 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 16:18:09 by natakaha         ###   ########.fr       */
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
	newlist->value = value;
	newlist->index = 0;
	newlist->after = newlist;
	newlist->before = newlist;
	return (newlist);
}

t_node	*ft_listadd_back(t_node *lst, t_node *new)
{
	t_node	*last;

	if (!lst)
		return (new);
	last = lst->before;
	new->after = lst;
	new->before = last;
	last->after = new;
	lst->before = new;
	return (lst);
}

void	ft_listclear(t_node *lst)
{
	t_node	*temp;

	if (!lst)
		return ;
	temp = (lst->after);
	while (true)
	{
		free(lst);
		lst = temp;
		if (lst == NULL)
			return ;
		temp = (lst)->after;
	}
}

unsigned int	ft_listsize(t_node *lst)
{
	t_node			*tmp;
	unsigned int	count;

	if (!lst)
		return (0);
	tmp = lst->after;
	count = 1;
	while (tmp && tmp != lst)
	{
		tmp = tmp->after;
		count++;
	}
	return (count);
}

unsigned int	locate_to_index(t_node *lst, int locate)
{
	t_node	*tmp;
	int		count;

	if (!lst)
	{
		write(1, "OpeError\n", 9);
		return (INT_MAX);
	}
	if (locate == 0)
		return (lst->index);
	if (locate < 0)
		locate = ft_listsize(lst) + locate;
	count = 0;
	tmp = lst;
	while (count < locate)
	{
		tmp = tmp->after;
		count++;
	}
	return (tmp->index);
}
