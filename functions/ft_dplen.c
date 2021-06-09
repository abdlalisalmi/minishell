/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dplen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:52:35 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/09 10:48:28 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

/*
** we use this function to calculate the len of **pointers
*/
int	ft_dplen(char **ptr)
{
	int len;

	len = 0;
	while (ptr[len] != 0)
		len++;
	return (len);	
}
