/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:25:09 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 21:44:54 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				v;
	unsigned int	i;
	struct s_node	*b;
	struct s_node	*n;
	unsigned int	dp;
	bool			lis;
}	t_node;

typedef struct s_lis
{
	int					len;
	unsigned int		end;
	unsigned int		srt;
}	t_lis;

/* index starts one and treat index 0 as NULL*/

long long		ft_atol(char **nptr);
int				count_number(char *str);
unsigned int	ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);

t_node			*ft_listnew(int value);
t_node			*ft_listadd_back(t_node *lst, t_node *new);
void			ft_listclear(t_node *lst);
unsigned int	ft_listsize(t_node *lst);
unsigned int	locate_to_index(t_node *lst, int locate);

int				find_chunk(t_node *sa, unsigned int start, unsigned int end);
unsigned int	find_largest(t_node *stk);
int				rotate_to_insert(t_node *stack_b, unsigned int index);
int				rotate_to_reverse(t_node *stk, unsigned int ind);
int				find_srt(t_node *sa, unsigned int start, unsigned int end);

t_node			*make_value_argone(char **format, t_node *front);
t_node			*make_value_multiarg(int argc, char **argv, t_node *front);
t_node			*detect_smallest(t_node *front, unsigned int count);
t_node			*make_index(t_node *front);
t_node			*make_node(int argc, char **argv, t_node *front);
t_node			*make_lis(t_node **sa);

int				swap_sa(t_node **afront, t_node **bfront);
int				swap_sb(t_node **afront, t_node **bfront);
int				swap_ss(t_node **afront, t_node **bfront);
int				push_a(t_node **afront, t_node **bfront);
int				push_b(t_node **afront, t_node **bfront);
int				rotate_ra(t_node **sa, t_node **sb);
int				rotate_rb(t_node **sa, t_node **sb);
int				rotate_rr(t_node **sa, t_node **sb);
int				rotate_rra(t_node **afront, t_node **bfront);
int				rotate_rrb(t_node **afront, t_node **bfront);
int				rotate_rrr(t_node **afront, t_node **bfront);

char			*exec_before_n(char	*str);
char			*proceed_after_n(char	*str);
char			*free_return_null(char *str);
char			*read_extend_str(int fd, char *str);
char			*get_next_line(int fd);

int				ft_strchr_len(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*allocate_char(char const *s1, char const *s2, char *joinstr);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strdup(const char *str);

//void			operation_manage(t_node **afront, t_node **bfront, size_t func);
//size_t			detect_function(char *display);
t_node			*node(t_node *stk, unsigned int index);

int				turk_insert_module(t_node **sa, t_node **sb, int na, int nb);
int				whole_turk_insert(t_node **sa, t_node **sb);
int				reverse_insert(t_node **sa, t_node **sb);
int				whole_reverse(t_node **sa, t_node **sb);
int				is_sorted(t_node *sa);
//void			print_stack(t_node *sa);

int				sort3(t_node **sa, t_node **sb);
int				sort5(t_node **sa, t_node **sb);

int				turk_insert_module(t_node **sa, t_node **sb, int na, int nb);
int				find_chunk(t_node *sa, unsigned int start, unsigned int end);
int				turk_insert(t_node **sa, t_node **sb);
int				find_cheapest(t_node *sa, t_node *sb);

#endif