/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:03:17 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/01 14:07:39 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_elem	*create_elem(int num)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new)
	{
		new->data = num;
		new->prev = 0;
		new->next = 0;
	}
	return (new);
}

void	append(t_deque *deque, t_elem *new)
{
	if (!new)
		return ;
	if (!deque->head)
		deque->head = new;
	new->prev = deque->tail;
	if (deque->tail)
		deque->tail->next = new;
	new->next = 0;
	deque->tail = new;
	deque->len += 1;
}

void	append_front(t_deque *deque, t_elem *new)
{
	if (!new)
		return ;
	if (!deque->head)
	{
		deque->head = new;
		deque->tail = new;
	}
	else
	{
		new->next = deque->head;
		deque->head->prev = new;
		new->prev = 0;
		deque->head = new;
	}
	deque->len += 1;
}

t_elem	*pop(t_deque *deque)
{
	t_elem	*last;

	last = deque->tail;
	if (last)
	{
		deque->tail = last->prev;
		if (deque->tail)
			deque->tail->next = 0;
		last->prev = 0;
		last->next = 0;
		deque->len -= 1;
	}
	if (deque->len == 0)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	return (last);
}

t_elem	*pop_front(t_deque *deque)
{
	t_elem	*first;

	first = deque->head;
	if (first)
	{
		deque->head = first->next;
		if (deque->head)
			deque->head->prev = 0;
		first->next = 0;
		first->prev = 0;
		deque->len -= 1;
	}
	if (deque->len == 0)
	{
		deque->head = 0;
		deque->tail = 0;
	}
	return (first);
}
