/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:31 by daparici          #+#    #+#             */
/*   Updated: 2023/09/09 16:02:47 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*buffer;
	char	*current_directory;

	buffer = (char *)malloc(PATH_MAX);
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
	//printf("%s\n", current_directory);
	free(buffer);
	return (EXIT_SUCCESS);
}
