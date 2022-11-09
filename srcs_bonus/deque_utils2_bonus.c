/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:27 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 20:21:45 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

t_deque	*create_deque(void)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque));
	if (new)
	{
		new->head = 0;
		new->tail = 0;
		new->len = 0;
	}
	return (new);
}

void	clear(t_deque *deque)
{
	t_elem	*head;
	t_elem	*temp;

	head = deque->head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free(deque);
}
