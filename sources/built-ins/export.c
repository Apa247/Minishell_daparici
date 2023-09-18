/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:51:30 by davidaparic       #+#    #+#             */
/*   Updated: 2023/09/15 12:40:07 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    print_export(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        ft_putstr_fd("declare -x ", STDOUT_FILENO);
        ft_putendl_fd(env[i], STDOUT_FILENO);
        i++;
    } 
}

int     check_parametres(char *cmd_arg)
{
    int i;

    i = 0;
    if (ft_isdigit(cmd_arg[0]))
        return(0);
    
}

void    ft_export(t_toolbox *tools, t_sp_cmds *exec_list)
{
    int i;

    i = 1;
    if (exec_list->cmd[1] == NULL || exec_list->cmd[1][0] == '\0')
        print_export(tools->sort_env);
    else
    {
        while (exec_list->cmd[i])
        {
            if 
        }
    }
}

