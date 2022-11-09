/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:15:29 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/09 12:37:22 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <sys/types.h>
# define TRUE 1
# define FALSE 0

typedef struct s_elem
{
	int				data;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct s_deque
{
	t_elem	*head;
	t_elem	*tail;
	size_t	len;
}				t_deque;

typedef struct s_stacks
{
	t_deque	*stack_a;
	t_deque	*stack_b;
}				t_stacks;

/* ************************************************************************** */
t_elem	*create_elem(int num);
void	append(t_deque *deque, t_elem *new);
void	append_front(t_deque *deque, t_elem *new);
t_elem	*pop(t_deque *deque);
t_elem	*pop_front(t_deque *deque);

/* ************************************************************************** */
t_deque	*create_deque(void);
void	clear(t_deque *deque);

/* ************************************************************************** */
void	ft_exit(const char *str, int exit_status);
void	*ft_malloc(size_t size);

/* ************************************************************************** */
int		is_valid_cmd(char *cmd);
int		is_integer(char *str);
int		is_sorted(t_deque *deque);
t_deque	*parse_input(int argc, char *argv[]);
void	check_errors(int argc, char *argv[]);

/* ************************************************************************** */
void	merge_sort_divide(t_elem *head, t_elem **front, t_elem **back);
t_elem	*merge(t_elem *front, t_elem *back);
void	merge_sort(t_elem **head);
int		is_duplicate(t_deque *input);

/* ************************************************************************** */
void	swap(t_deque *deque);
void	push(t_deque *dest, t_deque *src);
void	rotate(t_deque *a);
void	reverse_rotate(t_deque *a);

/* ************************************************************************** */
void	swap_both(t_deque *a, t_deque *b);
void	rotate_both(t_deque *a, t_deque *b);
void	reverse_rotate_both(t_deque *a, t_deque *b);

/* ************************************************************************** */
void	sa(t_stacks *info);
void	sb(t_stacks *info);
void	ss(t_stacks *info);
void	pa(t_stacks *info);
void	pb(t_stacks *info);
/* ************************************************************************** */
void	ra(t_stacks *info);
void	rb(t_stacks *info);
void	rr(t_stacks *info);
void	rra(t_stacks *info);
void	rrb(t_stacks *info);

void	rrr(t_stacks *info);

#endif