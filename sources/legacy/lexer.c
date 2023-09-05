/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:43:37 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/09/05 18:18:46 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_parser(char	*input)
{
	if (ft_strcmp(input, "|") == 0)
		return (1);
	else if (ft_strcmp(input, "<") == 0)
		return (2);
	else if (ft_strcmp(input, "<<") == 0)
		return (3);
	else if (ft_strcmp(input, ">") == 0)
		return (4);
	else if (ft_strcmp(input, ">>") == 0)
		return (5);
	else
		return (0);
}

void	show_split(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		tk = token_parser(input[i]);
		if (tk != 0)
			lexer_addback(&lexer, lexer_new(NULL, tk));
		else
			lexer_addback(&lexer, lexer_new(input[i], 0));
		tk = 0;
		i++;
	}
	printf("\n");
}
void	get_cmds(t_lexer *lex)
{
	t_cmds	*cmds;

	cmds = NULL;
	show_lexer(lex);
	while (lex->next)
	{
		if (lex->word)
		{
			parser_addback(&cmds, parser_new(ft_split(lex->word, ' '), 0));
		}
		else if (lex->token)
			parser_addback(&cmds, parser_new(NULL, lex->token));
		lex = lex->next;
	}
	if (lex->word)
		parser_addback(&cmds, parser_new(ft_split(lex->word, ' '), 0));
	else if (lex->token)
		parser_addback(&cmds, parser_new(NULL, lex->token));
	show_parser(cmds);
	l_free(lex);
	//system("leaks -q minishell");
}
