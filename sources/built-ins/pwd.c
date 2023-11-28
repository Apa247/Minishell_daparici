/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:31 by daparici          #+#    #+#             */
/*   Updated: 2023/11/28 18:08:18 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*buffer;
	char	*current_directory;

	//buffer = (char *)malloc(PATH_MAX);
	buffer = ft_calloc(sizeof(char), PATH_MAX);
	if (buffer == NULL)
	{
		perror("Error en la asignacion de memoria");
		exit(EXIT_FAILURE);
	}
	current_directory = getcwd(buffer, PATH_MAX);
	if (current_directory == NULL)
	{
		perror("Error al obtener el directorio actual");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(current_directory, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	free(buffer);
	return (EXIT_SUCCESS);
}
