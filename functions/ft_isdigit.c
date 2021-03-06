/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:07:56 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 11:08:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_isdigit(int arg)
{
	if (!((arg >= '0') && (arg <= '9')))
		return (0);
	return (1);
}
