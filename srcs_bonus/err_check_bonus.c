/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:07:03 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/09 12:51:15 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	is_valid_cmd(char *cmd)
{
	return (ft_strncmp("sa\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("sb\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("ss\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("pa\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("pb\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("ra\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("rb\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("rr\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("rra\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("rrb\n", cmd, ft_strlen(cmd)) == 0
		|| ft_strncmp("rrr\n", cmd, ft_strlen(cmd)) == 0);
}

int	is_integer(char *str)
{
	int		sign;
	int		flag;
	long	temp;

	temp = 0;
	sign = 1;
	flag = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (FALSE);
		flag = 1;
		temp = temp * 10 + (*str++ - '0');
		if (temp > 2147483648)
			return (FALSE);
		if (temp == 2147483648 && sign != -1)
			return (FALSE);
	}
	return (flag);
}

int	is_sorted(t_deque *deque)
{
	t_elem	*elem;

	if (deque->len == 0)
		return (FALSE);
	if (deque->len == 1)
		return (TRUE);
	elem = deque->head;
	while (elem->next)
	{
		if (elem->data < elem->next->data)
			return (FALSE);
		elem = elem->next;
	}
	return (TRUE);
}

t_deque	*parse_input(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**splitted;
	t_deque	*input;

	input = create_deque();
	i = 1;
	while (i < argc)
	{
		splitted = ft_split(argv[i++], ' ');
		j = 0;
		if (!*splitted)
			ft_exit("Error\n", 1);
		while (splitted[j])
		{
			if (!is_integer(splitted[j]))
				ft_exit("Error\n", 1);
			append_front(input, create_elem(ft_atoi(splitted[j])));
			free(splitted[j++]);
		}
		free(splitted);
	}
	return (input);
}

void	check_errors(int argc, char *argv[])
{
	t_deque	*input;

	input = parse_input(argc, argv);
	if (is_duplicate(input))
		ft_exit("Error\n", 1);
	clear(input);
}
