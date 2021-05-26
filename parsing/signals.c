/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:20:19 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/27 00:45:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* SIGINT is for Ctrl-C, SIGSTP is for Ctrl-Z, SIGQUIT is for Ctrl-\ */

void		signal_handlers(int sig)
{
	if (sig == SIGINT)
	{
		g_all.buff = NULL;
		write(1, "\n", 1);
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
	}
	if (sig == SIGQUIT)
	{
		exit(0);
	}
}

void		init_signals()
{
	signal(SIGINT, signal_handlers);
	signal(SIGQUIT, signal_handlers);
}