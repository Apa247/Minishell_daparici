/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:32:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/11/28 16:52:19 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_msg(char *msg)
{
	printf("ERROR: %s", msg);
	return (-1);
}

int	error_token(t_token token)
{
	printf("minishell: sintax error near unexpected ", STDERR_FILENO);
	if (token == PIPE)
		printf("'|'\n", STDERR_FILENO);
	if (token == LESS)
		printf("'<'\n", STDERR_FILENO);
	if (token == LESS_LESS)
		printf("'<<'\n", STDERR_FILENO);
	if (token == GREAT)
		printf("'>'\n", STDERR_FILENO);
	if (token == GREAT_GREAT)
		printf("'>>'\n", STDERR_FILENO);
	return (-1);
}


