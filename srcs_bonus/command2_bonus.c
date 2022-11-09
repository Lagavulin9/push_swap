/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:24 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 21:32:14 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_stacks *info)
{
	rotate(info->stack_a);
}

void	rb(t_stacks *info)
{
	rotate(info->stack_b);
}

void	rr(t_stacks *info)
{
	ra(info);
	rb(info);
}

void	rra(t_stacks *info)
{
	reverse_rotate(info->stack_a);
}

void	rrb(t_stacks *info)
{
	reverse_rotate(info->stack_b);
}
