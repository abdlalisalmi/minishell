/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:23:38 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/26 14:23:45 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_spaces(char *str)
{
	int		len;
	char	*ptr;
	int		j;

	int i = 0;
	j = 0;
	if (str[0] == '\0')
		return (strdup(str));
	len = strlen(str);
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	len -= 1;
	while ((str[len] == ' ' || str[len] == '\t') && len > 0)
	{
		if (str[len - 1] == '\\' && str[len] == ' ')
			break ;
		len--;
	}
	len += 1;
	len = (len - i < 0) ? i : len;
	ptr = (char *)malloc(sizeof(char) * (len + 1 - i));
	while (i < len && str[i])
		ptr[j++] = str[i++];
	ptr[j] = '\0';
	return (ptr);
}