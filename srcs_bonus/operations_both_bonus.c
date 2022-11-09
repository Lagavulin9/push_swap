/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:34:37 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/08 20:23:15 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_both(t_deque *a, t_deque *b)
{
	swap(a);
	swap(b);
}

void	rotate_both(t_deque *a, t_deque *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both(t_deque *a, t_deque *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
