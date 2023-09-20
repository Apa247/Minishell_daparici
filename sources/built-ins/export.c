/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:51:30 by davidaparic       #+#    #+#             */
/*   Updated: 2023/09/20 12:39:28 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(char **env)
{
	int	i;
	int	k;

	i = 0;
	while (env[i])
	{
		k = 0;
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		while (env[i][k])
		{
			ft_putchar_fd(env[i][k], STDOUT_FILENO);
			if (env[i][k++] == '=')
				ft_putchar_fd('\"', STDOUT_FILENO);
		}
		if (ft_strchr(env[i], '='))
			ft_putchar_fd('\"', STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

char	**add_variable(char **sort_env, char *cmd_arg)
{
	int		i;
	char	**copy_env;

	i = 0;
	while (sort_env[i])
		i++;
	copy_env = ft_calloc(i + 2, sizeof(char *));
	if (!copy_env)
		return (NULL);
}

void	ft_export(t_toolbox *tools, t_sp_cmds *exec_list)
{
	int		i;
	char	**tmp;

	i = 1;
	if (exec_list->cmd[1] == NULL)
	{
		print_export(tools->sort_env);
	}
	else
	{
		while (exec_list->cmd[i])
		{
			if (!check_parametres(exec_list->cmd[i])
				&& !check_variable_exist(tools->sort_env, exec_list->cmd[i]))
			{
				tmp 
			}
			i++;
		}
	}
}
