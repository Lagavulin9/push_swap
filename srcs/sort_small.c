/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:18:29 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:27:38 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_3(t_info *info)
{
	const int	a = info->stack_a->tail->data;
	const int	b = info->stack_a->tail->prev->data;
	const int	c = info->stack_a->head->data;

	if (a > b && a > c && b > c)
	{
		sa(info);
		rra(info);
	}
	else if (a > b && a > c && b < c)
		ra(info);
	else if (b > a && b > c && a > c)
		rra(info);
	else if (b > a && b > c && a < c)
	{
		rra(info);
		sa(info);
	}
	else if (c > a && c > b && a > b)
		sa(info);
}

void	sort_small_4(t_info *info)
{
	int	pivot;
	int	pb_count;

	pivot = get_pivot(info->stack_a, 4);
	pb_count = 0;
	while (pb_count < 2)
	{
		if (info->stack_a->tail->data < pivot)
		{
			pb(info);
			pb_count++;
		}
		else
			ra(info);
	}
	if (info->stack_a->tail->data > info->stack_a->head->data)
		sa(info);
	if (info->stack_b->head->data > info->stack_b->tail->data)
		sb(info);
	pa(info);
	pa(info);
}

void	sort_small_5(t_info *info)
{
	int	pivot;
	int	pb_count;

	pivot = get_pivot(info->stack_a, 5);
	pb_count = 0;
	while (pb_count < 2)
	{
		if (info->stack_a->tail->data < pivot)
		{
			pb(info);
			pb_count++;
		}
		else
			ra(info);
	}
	sort_small_3(info);
	if (info->stack_b->head->data > info->stack_b->tail->data)
		sb(info);
	pa(info);
	pa(info);
}

void	sort_small(t_info *info)
{
	if (info->stack_a->len == 2)
		sa(info);
	else if (info->stack_a->len == 3)
		sort_small_3(info);
	else if (info->stack_a->len == 4)
		sort_small_4(info);
	else if (info->stack_a->len == 5)
		sort_small_5(info);
}
