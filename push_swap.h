/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:25:09 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 20:02:18 by natakaha         ###   ########.fr       */
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
	int				value;
	unsigned int	index;
	struct s_node	*after;
	struct s_node	*before;
}	t_node;

/* index starts one and treat index 0 as NULL*/

long long		ft_atol(char **nptr);
size_t			count_words(char const *s);
int				atol_check(char *nptr);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);

t_node			*ft_listnew(int value);
t_node			*ft_listadd_back(t_node *lst, t_node *new);
void			ft_listclear(t_node *lst);
unsigned int	ft_listsize(t_node *lst);
unsigned int	locate_to_index(t_node *lst, int locate);

int				find_chunk_front(t_node *sa,
					unsigned int start, unsigned int end);
unsigned int	find_largest(t_node *stk);
int				rotate_to_insert(t_node *stack_b, unsigned int index);

t_node			*make_value_argone(char **format, t_node *front);
t_node			*make_value_multiarg(int argc, char **argv, t_node *front);
t_node			*detect_smallest(t_node *front, unsigned int count);
t_node			*make_index(t_node *front);
t_node			*make_node(int argc, char **argv, t_node *front);

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

void			operation_manage(t_node **afront, t_node **bfront, size_t func);
size_t			detect_function(char *display);

int				chunked_insert(t_node **sa, t_node **sb, unsigned int srt,
					unsigned int end);
int				reverse_insert(t_node **sa, t_node **sb);
void			print_stack(char c, t_node *stack);

#endif