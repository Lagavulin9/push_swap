/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_triangles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:38:50 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 20:14:48 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	make_triangle_2(t_info *info, int reverse)
{
	if (reverse)
	{
		if (info->stack_a->tail->data > info->stack_a->tail->prev->data)
			sa(info);
	}
	else
	{
		if (info->stack_a->tail->data < info->stack_a->tail->prev->data)
			sa(info);
	}
	pb(info);
	pb(info);
}

void	make_triangle_3(t_info *info, int reverse)
{
	if (reverse)
	{
		if (info->stack_a->tail->data > info->stack_a->tail->prev->data)
			sa(info);
		pb(info);
		if (info->stack_a->tail->data > info->stack_a->tail->prev->data)
			sa(info);
		pb(info);
		if (info->stack_b->tail->data < info->stack_b->tail->prev->data)
			sb(info);
		pb(info);
	}
	else
	{
		if (info->stack_a->tail->data < info->stack_a->tail->prev->data)
			sa(info);
		pb(info);
		if (info->stack_a->tail->data < info->stack_a->tail->prev->data)
			sa(info);
		pb(info);
		if (info->stack_b->tail->data > info->stack_b->tail->prev->data)
			sb(info);
		pb(info);
	}
}

int	get_pivot(t_deque *stack_a, int num)
{
	t_elem	*top;
	int		arr[5];
	int		i;

	i = 0;
	top = stack_a->tail;
	while (i < num)
	{
		arr[i++] = top->data;
		top = top->prev;
	}
	i = 0;
	while (i < num - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ft_swap(&arr[i], &arr[i + 1]);
			i = 0;
			continue ;
		}
		i++;
	}
	return (arr[num / 2]);
}

void	make_triangles(t_info *info, t_map *map)
{
	int	index;

	index = map->map_size - ft_pow(3, map->depth);
	while (index < map->map_size)
	{
		if (map->triangle_size[index] == 1)
			pb(info);
		else if (map->triangle_size[index] == 2)
			make_triangle_2(info, map->reverse[index]);
		else if (map->triangle_size[index] == 3)
			make_triangle_3(info, map->reverse[index]);
		else if (map->triangle_size[index] == 4)
			make_triangle_4(info, map->reverse[index]);
		else if (map->triangle_size[index] == 5)
			make_triangle_5(info, map->reverse[index]);
		index++;
	}
}
