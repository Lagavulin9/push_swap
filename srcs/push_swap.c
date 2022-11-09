/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:03:20 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 18:57:24 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	push_swap(t_info *info)
{
	t_map	*map;

	map = set_map(info->stack_a->len);
	make_triangles(info, map);
	merge_triangles(info, map);
	if (info->stack_a->len == 0)
	{
		while (info->stack_b->len)
		{
			pa(info);
		}
	}
	free(map->triangle_size);
	free(map->reverse);
	free(map);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc > 1)
	{
		check_errors(argc, argv);
		info.stack_a = parse_input(argc, argv);
		info.stack_b = create_deque();
		if (info.stack_a->len <= 5)
			sort_small(&info);
		else
			push_swap(&info);
		clear(info.stack_a);
		clear(info.stack_b);
	}
	return (0);
}
