/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:53:02 by daparici          #+#    #+#             */
/*   Updated: 2023/09/26 11:06:50 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_executor(t_toolbox *tools)
{
	int	exit;

	exit = 0;
	while (tools->sp_cmds)
	{
		if (ft_strcmp(tools->sp_cmds->cmd[0], "pwd") == 0)
			exit = ft_pwd();
		if (ft_strcmp(tools->sp_cmds->cmd[0], "echo") == 0)
			ft_echo(tools->sp_cmds);
		if (ft_strcmp(tools->sp_cmds->cmd[0], "env") == 0)
			ft_env(tools->env);
		if (ft_strcmp(tools->sp_cmds->cmd[0], "export") == 0)
			ft_export(tools);
		tools->sp_cmds = tools->sp_cmds->next;
	}
}

