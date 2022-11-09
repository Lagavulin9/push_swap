/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangle_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:48:22 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:24:16 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_2(t_info *info)
{
	int	pivot;
	int	pb_count;
	int	ra_count;

	pivot = get_pivot(info->stack_a, 4);
	pb_count = 0;
	ra_count = 0;
	while (pb_count < 2)
	{
		if (info->stack_a->tail->data >= pivot)
		{
			pb(info);
			pb_count++;
		}
		else
		{
			ra(info);
			ra_count++;
		}
	}
	while (ra_count--)
		rra(info);
}

static void	push_reverse_2(t_info *info)
{
	int	pivot;
	int	pb_count;
	int	ra_count;

	pivot = get_pivot(info->stack_a, 4);
	pb_count = 0;
	ra_count = 0;
	while (pb_count < 2)
	{
		if (info->stack_a->tail->data < pivot)
		{
			pb(info);
			pb_count++;
		}
		else
		{
			ra(info);
			ra_count++;
		}
	}
	while (ra_count--)
		rra(info);
}

void	make_triangle_4(t_info *info, int reverse)
{
	if (reverse)
	{
		push_reverse_2(info);
		if (info->stack_b->tail->data < info->stack_b->tail->prev->data)
			sb(info);
	}
	else
	{
		push_2(info);
		if (info->stack_b->tail->data > info->stack_b->tail->prev->data)
			sb(info);
	}
	make_triangle_2(info, reverse);
}
