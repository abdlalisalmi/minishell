/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:03:01 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 11:03:24 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *str, int c)
{
	char			*pstr;
	unsigned int	i;

	pstr = (char*)str;
	i = 0;
	while (i <= ft_strlen(pstr))
	{
		if (str[i] == c)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
