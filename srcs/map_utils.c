/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:24:52 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 17:24:44 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int num, int power)
{
	int	result;
	int	i;

	if (power < 0)
		return (0);
	i = 0;
	result = 1;
	while (i < power)
	{
		result *= num;
		i++;
	}
	return (result);
}

int	calc_depth(int num)
{
	int	depth;
	int	tmp;

	if (num < 6)
		return (0);
	if (num < 15)
		return (1);
	depth = 1;
	tmp = 15;
	while (tmp < num)
	{
		tmp *= 3;
		depth++;
	}
	return (depth);
}

int	calc_map_size(int depth)
{
	int	depth_index;
	int	size;
	int	total;

	depth_index = 0;
	size = 1;
	total = 1;
	while (depth_index < depth)
	{
		size *= 3;
		total += size;
		depth_index++;
	}
	return (total);
}

void	set_sizes(t_map *map, t_triangle *tri, int start, int offset)
{
	tri->top_size = map->triangle_size[start + \
		ft_pow(3, map->depth - 1) + offset];
	tri->mid_size = map->triangle_size[start + 3 \
		* ft_pow(3, map->depth - 1) - offset - 1];
	tri->bot_size = map->triangle_size[start + \
		4 * ft_pow(3, map->depth - 1) - offset - 1];
}
