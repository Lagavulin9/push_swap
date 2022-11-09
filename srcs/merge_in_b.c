/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_in_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:05:48 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:25:44 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	partial_move_to_b(t_info *info, t_map *map)
{
	int	start;
	int	end;
	int	i;

	end = calc_map_size(map->depth) - 1;
	start = end - ft_pow(3, map->depth - 1) + 1;
	while (start <= end)
	{
		i = 0;
		while (i < map->triangle_size[start])
		{
			pb(info);
			i++;
		}
		start++;
	}
}

void	merge_normal_in_b(t_info *info, t_map *map, int start, int offset)
{
	t_triangle	tri;
	int			max;

	set_sizes(map, &tri, start, offset);
	while (tri.bot_size + tri.mid_size + tri.top_size)
	{
		max = ft_max_b(info, tri.bot_size, tri.mid_size, tri.top_size);
		if (tri.bot_size && info->stack_b->head->data == max)
		{
			rrb(info);
			tri.bot_size--;
		}
		else if (tri.mid_size && info->stack_a->tail->data == max)
		{
			pb(info);
			tri.mid_size--;
		}
		else if (tri.top_size && info->stack_a->head->data == max)
		{
			rra(info);
			pb(info);
			tri.top_size--;
		}
	}
}

void	merge_reverse_in_b(t_info *info, t_map *map, int start, int offset)
{
	t_triangle	tri;
	int			min;

	set_sizes(map, &tri, start, offset);
	while (tri.bot_size + tri.mid_size + tri.top_size)
	{
		min = ft_min_b(info, tri.bot_size, tri.mid_size, tri.top_size);
		if (tri.bot_size && info->stack_b->head->data == min)
		{
			rrb(info);
			tri.bot_size--;
		}
		else if (tri.mid_size && info->stack_a->tail->data == min)
		{
			pb(info);
			tri.mid_size--;
		}
		else if (tri.top_size && info->stack_a->head->data == min)
		{
			rra(info);
			pb(info);
			tri.top_size--;
		}
	}
}

void	merge_in_b(t_info *info, t_map *map)
{
	int	start;
	int	end;
	int	offset;

	partial_move_to_b(info, map);
	end = calc_map_size(map->depth - 1) - 1;
	start = end - ft_pow(3, map->depth - 1) + 1;
	offset = 0;
	while (start <= end)
	{
		if (map->reverse[start] == TRUE)
			merge_reverse_in_b(info, map, \
			end - ft_pow(3, map->depth - 1) + 1, offset++);
		else
			merge_normal_in_b(info, map, \
			end - ft_pow(3, map->depth - 1) + 1, offset++);
		start++;
	}
}
