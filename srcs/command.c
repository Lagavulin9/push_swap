/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:24 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 14:15:31 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	sa(t_info *info)
{
	swap(info->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	swap(info->stack_b);
	write(1, "sb\n", 3);
}

void	pa(t_info *info)
{
	push(info->stack_a, info->stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	push(info->stack_b, info->stack_a);
	write(1, "pb\n", 3);
}
