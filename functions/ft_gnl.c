/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:45:56 by atahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/24 10:50:51 by aes-salm         ###   ########.fr       */
=======
/*   Updated: 2021/05/24 11:55:36 by atahiri          ###   ########.fr       */
>>>>>>> 153047ff83e3202844243e341f55a9fc924d0c3a
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_gnl(char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !(*line = (char *)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
