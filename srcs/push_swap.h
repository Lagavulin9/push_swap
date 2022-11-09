/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:00:15 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 21:15:06 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_info
{
	t_deque	*stack_a;
	t_deque	*stack_b;
}				t_info;

typedef struct s_map
{
	int	*triangle_size;
	int	*reverse;
	int	map_size;
	int	depth;
}				t_map;

typedef struct s_triangle
{
	int	bot_size;
	int	mid_size;
	int	top_size;
}				t_triangle;

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
void	ft_exit(const char *str, int exit_status);
void	*ft_malloc(size_t size);

/* ************************************************************************** */
int		ft_pow(int num, int power);
int		calc_depth(int num);
int		calc_map_size(int depth);
void	set_sizes(t_map *map, t_triangle *tri, int start, int offset);

/* ************************************************************************** */
void	set_bot(t_map *map, int index, int size);
void	set_mid(t_map *map, int index, int size);
void	set_top(t_map *map, int index, int size);
t_map	*set_map(int num_of_elements);

/* ************************************************************************** */
int		get_pivot(t_deque *stack_a, int num);
void	make_triangle_2(t_info *info, int reverse);
void	make_triangle_3(t_info *info, int reverse);
void	make_triangles(t_info *info, t_map *map);

/* ************************************************************************** */
void	make_triangle_4(t_info *info, int reverse);
/* ************************************************************************** */
void	make_triangle_5(t_info *info, int reverse);

/* ************************************************************************** */
void	partial_move_to_a(t_info *info, t_map *map);
void	merge_normal_in_a(t_info *info, t_map *map, int start, int offset);
void	merge_reverse_in_a(t_info *info, t_map *map, int start, int offset);
void	merge_in_a(t_info *info, t_map *map);

/* ************************************************************************** */
void	partial_move_to_b(t_info *info, t_map *map);
void	merge_normal_in_b(t_info *info, t_map *map, int start, int offset);
void	merge_reverse_in_b(t_info *info, t_map *map, int start, int offset);
void	merge_in_b(t_info *info, t_map *map);

/* ************************************************************************** */
int		ft_min_a(t_info *info, int bot_size, int mid_size, int top_size);
int		ft_max_a(t_info *info, int bot_size, int mid_size, int top_size);
int		ft_min_b(t_info *info, int bot_size, int mid_size, int top_size);
int		ft_max_b(t_info *info, int bot_size, int mid_size, int top_size);
void	merge_triangles(t_info *info, t_map *map);

/* ************************************************************************** */
void	sa(t_info *info);
void	sb(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
/* ************************************************************************** */
void	ra(t_info *info);
void	rb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);

/* ************************************************************************** */
void	sort_small_3(t_info *info);
void	sort_small_4(t_info *info);
void	sort_small_5(t_info *info);
void	sort_small(t_info *info);

/* ************************************************************************** */
void	push_swap(t_info *info);
#endif
