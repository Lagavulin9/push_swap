/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:26:15 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 20:21:36 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	merge_sort_divide(t_elem *head, t_elem **front, t_elem **back)
{
	t_elem	*fast;
	t_elem	*slow;

	if (!head || !head->next)
	{
		*front = head;
		*back = 0;
		return ;
	}
	fast = head->next;
	slow = head;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front = head;
	*back = slow->next;
	slow->next = 0;
}

t_elem	*merge(t_elem *front, t_elem *back)
{
	t_elem	*result;

	if (!front)
		return (back);
	if (!back)
		return (front);
	if (front->data <= back->data)
	{
		result = front;
		result->next = merge(front->next, back);
	}
	else
	{
		result = back;
		result->next = merge(front, back->next);
	}
	return (result);
}

void	merge_sort(t_elem **head)
{
	t_elem	*front;
	t_elem	*back;

	if (!*head || !(*head)->next)
		return ;
	merge_sort_divide(*head, &front, &back);
	merge_sort(&front);
	merge_sort(&back);
	*head = merge(front, back);
}

int	is_duplicate(t_deque *input)
{
	t_elem	*elem;

	merge_sort(&input->head);
	elem = input->head;
	while (elem->next)
	{
		if (elem->data == elem->next->data)
			return (1);
		elem = elem->next;
	}
	return (0);
}
