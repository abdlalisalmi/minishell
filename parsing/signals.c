/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:20:19 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/05 12:10:16 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* SIGINT is for Ctrl-C, SIGSTP is for Ctrl-Z, SIGQUIT is for Ctrl-\ */

void		signal_handlers(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
	}
}

void		init_signals(void)
{
	signal(SIGINT, signal_handlers);
}