/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:47:27 by jinholee          #+#    #+#             */
/*   Updated: 2022/11/09 13:40:19 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	execute_cmd(t_stacks *info, char *cmd)
{
	if (!is_valid_cmd(cmd))
		ft_exit("Error\n", 0);
	if (ft_strncmp("sa\n ", cmd, ft_strlen(cmd)) == 0)
		sa(info);
	else if (ft_strncmp("sb\n", cmd, ft_strlen(cmd)) == 0)
		sb(info);
	else if (ft_strncmp("ss\n", cmd, ft_strlen(cmd)) == 0)
		ss(info);
	else if (ft_strncmp("pa\n", cmd, ft_strlen(cmd)) == 0)
		pa(info);
	else if (ft_strncmp("pb\n", cmd, ft_strlen(cmd)) == 0)
		pb(info);
	else if (ft_strncmp("ra\n", cmd, ft_strlen(cmd)) == 0)
		ra(info);
	else if (ft_strncmp("rb\n", cmd, ft_strlen(cmd)) == 0)
		rb(info);
	else if (ft_strncmp("rr\n", cmd, ft_strlen(cmd)) == 0)
		rr(info);
	else if (ft_strncmp("rra\n", cmd, ft_strlen(cmd)) == 0)
		rra(info);
	else if (ft_strncmp("rrb\n", cmd, ft_strlen(cmd)) == 0)
		rrb(info);
	else if (ft_strncmp("rrr\n", cmd, ft_strlen(cmd)) == 0)
		rrr(info);
}

int	main(int argc, char *argv[])
{
	t_stacks	info;
	char		*cmd;

	if (argc > 1)
	{
		check_errors(argc, argv);
		info.stack_a = parse_input(argc, argv);
		info.stack_b = create_deque();
		cmd = get_next_line(0);
		while (cmd)
		{
			execute_cmd(&info, cmd);
			free(cmd);
			cmd = get_next_line(0);
		}
		if (info.stack_b->len == 0 && is_sorted(info.stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clear(info.stack_a);
		clear(info.stack_b);
	}
	return (0);
}
