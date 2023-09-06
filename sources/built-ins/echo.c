/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:17:51 by daparici          #+#    #+#             */
/*   Updated: 2023/09/06 18:02:15 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arguments(char **arg, int i)
{
	while (arg[i])
	{
		ft_putstr_fd(arg[i], STDOUT_FILENO);
		if (arg[i + 1])
			ft_putchar_fd(" ", STDOUT_FILENO);
		i++;
	}
}

void	ft_echo(t_sp_cmds *sp_cmds)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 1;
	j = 0;
	if (ft_strcmp(sp_cmds->cmd[i], "-n") == 0)
	{
		flag = 1;
		i++;
	}
	if (sp_cmds->cmd[i])
		print_arguments(sp_cmds->cmd, i);
	if (flag == 0)
		ft_putchar_fd("\n", STDOUT_FILENO);
}
