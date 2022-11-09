/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:24 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 14:14:56 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	ra(t_info *info)
{
	rotate(info->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	rotate(info->stack_b);
	write(1, "rb\n", 3);
}

void	rra(t_info *info)
{
	reverse_rotate(info->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	reverse_rotate(info->stack_b);
	write(1, "rrb\n", 4);
}
