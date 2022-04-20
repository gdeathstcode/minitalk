/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:23:02 by gdeathst          #+#    #+#             */
/*   Updated: 2022/04/19 16:23:03 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	err_exit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

static void	send_byte(const pid_t pid, char byte)
{
	int		current_bit;
	int		ret;

	current_bit = 7;
	while (current_bit >= 0)
	{
		if (byte & (1 << current_bit))
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
			err_exit("ERROR: CANNOT_SEND_MESSAGE\n");
		current_bit--;
		usleep(DELAY);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	pid_t	pid;

	if (argc != 3 || ft_atoi(argv[1]) <= 0)
		err_exit("ERROR: ./client PID_SERVER STRING_TO_PASS\n");
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (1)
	{
		send_byte(pid, *str);
		if (*str == '\0')
			break ;
		str++;
	}
	return (EXIT_SUCCESS);
}
