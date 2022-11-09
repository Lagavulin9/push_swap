/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:51:09 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:27:19 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	set_bot(t_map *map, int index, int size)
{
	int	bot_index;
	int	to;

	bot_index = index + size;
	to = index + size;
	while (index < to)
	{
		if (map->triangle_size[index] == 14 \
		|| map->triangle_size[index] == 15)
			map->triangle_size[bot_index] = 5;
		else
			map->triangle_size[bot_index] = map->triangle_size[index] / 3;
		map->reverse[bot_index] = map->reverse[index];
		index++;
		bot_index++;
	}
}

void	set_mid(t_map *map, int index, int size)
{
	int	mid_index;
	int	to;

	mid_index = index + 3 * size - 1;
	to = index + size;
	while (index < to)
	{
		if (map->triangle_size[index] == 14 \
		|| map->triangle_size[index] == 15)
			map->triangle_size[mid_index] = 5;
		else
			map->triangle_size[mid_index] = \
			map->triangle_size[index] / 3 + map->triangle_size[index] % 3;
		map->reverse[mid_index] = !map->reverse[index];
		index++;
		mid_index--;
	}
}

void	set_top(t_map *map, int index, int size)
{
	int	top_index;
	int	to;

	top_index = index + 4 * size - 1;
	to = index + size;
	while (index < to)
	{
		map->triangle_size[top_index] = map->triangle_size[index] / 3;
		map->reverse[top_index] = !map->reverse[index];
		index++;
		top_index--;
	}
}

void	adjust_reverse(t_map *map)
{
	int	i;

	if (map->depth % 2 == 0)
	{
		i = 0;
		while (i < map->map_size)
		{
			map->reverse[i] = !map->reverse[i];
			i++;
		}
	}
}

t_map	*set_map(int num_of_elements)
{
	int		depth_index;
	int		size;
	int		index;
	t_map	*map;

	map = ft_malloc(sizeof(t_map));
	map->depth = calc_depth(num_of_elements);
	map->map_size = calc_map_size(map->depth);
	map->triangle_size = ft_malloc(sizeof(int) * map->map_size);
	map->reverse = ft_malloc(sizeof(int) * map->map_size);
	map->triangle_size[0] = num_of_elements;
	depth_index = 0;
	index = 0;
	while (depth_index < map->depth)
	{
		size = ft_pow(3, depth_index++);
		set_bot(map, index, size);
		set_mid(map, index, size);
		set_top(map, index, size);
		index += size;
	}
	adjust_reverse(map);
	return (map);
}
