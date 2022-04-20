/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:23:07 by gdeathst          #+#    #+#             */
/*   Updated: 2022/04/19 16:23:08 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	listen_message(int sig)
{
	static struct s_character	ch = {0, 0};

	if (sig == SIGUSR1)
		ch.character = ch.character | (1 << (7 - ch.current_bit));
	ch.current_bit++;
	if (ch.current_bit == 8)
	{
		if (ch.character == '\0')
			ch.character = '\n';
		ft_printf("%c", ch.character);
		ch.character = 0;
		ch.current_bit = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, listen_message);
	signal(SIGUSR2, listen_message);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		pause();
}
