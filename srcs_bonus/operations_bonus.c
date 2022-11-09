/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:43:03 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 20:21:52 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_deque *deque)
{
	t_elem	*last;
	t_elem	*temp_prev;
	t_elem	*temp_next;

	last = deque->tail;
	if (deque->len > 2)
	{
		deque->tail = last->prev;
		last->prev->prev->next = last;
		temp_prev = last->prev->prev;
		temp_next = last->prev;
		last->prev->prev = last;
		last->prev->next = last->next;
		last->prev = temp_prev;
		last->next = temp_next;
	}
	else if (deque->len == 2)
	{
		deque->head = last;
		deque->tail = last->prev;
		deque->head->prev = 0;
		deque->head->next = deque->tail;
		deque->tail->prev = deque->head;
		deque->tail->next = 0;
	}
}

void	push(t_deque *dest, t_deque *src)
{
	t_elem	*src_last;

	src_last = pop(src);
	if (src_last)
		append(dest, src_last);
}

void	rotate(t_deque *a)
{
	t_elem	*front;

	front = pop(a);
	if (front)
		append_front(a, front);
}

void	reverse_rotate(t_deque *a)
{
	t_elem	*last;

	last = pop_front(a);
	if (last)
		append(a, last);
}
