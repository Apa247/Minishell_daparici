/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:31 by daparici          #+#    #+#             */
/*   Updated: 2023/09/05 19:17:27 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
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
	printf("%s\n", current_directory);
	free(buffer);
}
