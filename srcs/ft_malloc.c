/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:44:38 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/09 12:47:29 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_exit(const char *str, int exit_status)
{
	if (str == NULL)
	{
		exit(exit_status);
	}
	else
	{
		write(2, str, ft_strlen(str));
		exit(exit_status);
	}
}

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		ft_exit("malloc error.\n", 1);
	ft_memset(p, 0, size);
	return (p);
}
