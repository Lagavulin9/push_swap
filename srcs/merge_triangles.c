/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_triangles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:57:01 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:21:52 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_min_a(t_info *info, int bot_size, int mid_size, int top_size)
{
	int	min;

	min = 2147483647;
	if (bot_size && min >= info->stack_a->head->data)
		min = info->stack_a->head->data;
	if (mid_size && min >= info->stack_b->tail->data)
		min = info->stack_b->tail->data;
	if (top_size && min >= info->stack_b->head->data)
		min = info->stack_b->head->data;
	return (min);
}

int	ft_max_a(t_info *info, int bot_size, int mid_size, int top_size)
{
	int	max;

	max = -2147483648;
	if (bot_size && max <= info->stack_a->head->data)
		max = info->stack_a->head->data;
	if (mid_size && max <= info->stack_b->tail->data)
		max = info->stack_b->tail->data;
	if (top_size && max <= info->stack_b->head->data)
		max = info->stack_b->head->data;
	return (max);
}

int	ft_min_b(t_info *info, int bot_size, int mid_size, int top_size)
{
	int	min;

	min = 2147483647;
	if (bot_size && min >= info->stack_b->head->data)
		min = info->stack_b->head->data;
	if (mid_size && min >= info->stack_a->tail->data)
		min = info->stack_a->tail->data;
	if (top_size && min >= info->stack_a->head->data)
		min = info->stack_a->head->data;
	return (min);
}

int	ft_max_b(t_info *info, int bot_size, int mid_size, int top_size)
{
	int	max;

	max = -2147483648;
	if (bot_size && max <= info->stack_b->head->data)
		max = info->stack_b->head->data;
	if (mid_size && max <= info->stack_a->tail->data)
		max = info->stack_a->tail->data;
	if (top_size && max <= info->stack_a->head->data)
		max = info->stack_a->head->data;
	return (max);
}

void	merge_triangles(t_info *info, t_map *map)
{
	while (map->depth > 0)
	{
		if (info->stack_a->len == 0)
			merge_in_a(info, map);
		else if (info->stack_b->len == 0)
			merge_in_b(info, map);
		map->depth--;
	}
}
