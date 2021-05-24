/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:01:52 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/24 10:07:51 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	int ret;
	
	ret = 1;

	while (ret > 0) 
	{
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
		ret = ft_gnl(&g_all.buff);
	}
	return (0);
}