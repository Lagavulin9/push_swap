/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:24 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 21:32:02 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stacks *info)
{
	swap(info->stack_a);
}

void	sb(t_stacks *info)
{
	swap(info->stack_b);
}

void	ss(t_stacks *info)
{
	sa(info);
	sb(info);
}

void	pa(t_stacks *info)
{
	push(info->stack_a, info->stack_b);
}

void	pb(t_stacks *info)
{
	push(info->stack_b, info->stack_a);
}
