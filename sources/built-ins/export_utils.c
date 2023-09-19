/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:40 by daparici          #+#    #+#             */
/*   Updated: 2023/09/19 17:54:23 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_error(char *cmd_arg)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(cmd_arg, STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putendl_fd(" : not a valid identifier", STDERR_FILENO);
}

int	lenght_to_equal(char *cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i] && cmd_arg[i] != '=')
		i++;
	return (i);
}

int	check_variable_exist(t_toolbox *tools, char *cmd_arg)
{
	int	i;

	i = 0;
	while (tools->sort_env[i])
	{
		if (ft_strncmp(tools->sort_env[i], cmd_arg, !lenght_to_equal(cmd_arg)))
		{
			free(tools->sort_env[i]);
			tools->sort_env[i] = ft_strdup(cmd_arg);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_parametres(char *cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i] != '=' && cmd_arg[i])
	{
		if (ft_isdigit(cmd_arg[0]) || !cmd_arg[0])
		{
			export_error(cmd_arg);
			return (1);
		}
		printf("%c\n", cmd_arg[i]);
		if ((cmd_arg[i] != '_') && (ft_isalnum(cmd_arg[i]) == 0))
		{
			printf("hola\n");
			export_error(cmd_arg);
			return (1);
		}
		i++;
	}
	return (0);
}