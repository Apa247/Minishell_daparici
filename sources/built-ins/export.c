/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:51:30 by davidaparic       #+#    #+#             */
/*   Updated: 2023/09/25 20:05:57 by davidaparic      ###   ########.fr       */
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

char	**add_var_loop(char **sort_env, char **copy_env, char *cmd_arg)
{
	int i;
	
	i = 0;
	while (sort_env[i])
	{
		if (!sort_env[i + 1])
		{
			copy_env[i] = ft_strdup(sort_env[i]);
			copy_env[i + 1] = ft_strdup(cmd_arg);
		}
		else
			copy_env[i] = ft_strdup(sort_env[i]);
		i++;
	}
	return(copy_env);
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
	i = 0;
	copy_env = add_var_loop(sort_env, copy_env, cmd_arg);
	return(copy_env);
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
				&& !check_variable_exist(tools, exec_list->cmd[i]))
			{
				if (exec_list->cmd[i])
				{
					tmp = add_variable(tools->sort_env, exec_list->cmd[i]);
					free_arr(tools->sort_env);
					tools->sort_env = tmp;
				}
			}
			i++;
		}
	}
}
