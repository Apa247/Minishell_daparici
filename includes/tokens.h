/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:45:51 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/11/28 15:25:26 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
#define TOKENS_H

#include "minishell.h"
#include "structs.h"

t_token	check_token(char *tk, int i);

t_command	*init_cmd(void);
void   		comm_addback(t_command **head, t_command *new);
void    	cmd_show(t_command *cmd);
void    	cmd_free(t_command *cmd);

#endif
