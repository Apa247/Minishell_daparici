/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:41:48 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/08/04 16:42:08 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *a)
{
	int		b;

	b = 0;
	if (a == NULL)
		return (0);
	while (a[b])
		b++;
	return (b);
}
