/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:28:15 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/09/14 14:01:06 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_toolbox	tools;

	atexit(leaks);
	if (argc != 1 || argv[1])
	{
		printf("Minishell must be executed wihtout arguments");
		exit(0);
	}
	tools.env = envp_dup(envp, &tools);
	tools_load(&tools);
	pwd_search(&tools);
	minishell_loop(&tools);
	return (0);
}
