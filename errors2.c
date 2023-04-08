/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:50 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:51 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_str_is_num(char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) == 0)
		error();
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
	}
	error();
}

char	*valid_str(char *concat_str)
{
	int	i;

	i = 0;
	while (concat_str[i])
	{
		if ((concat_str[i] >= '0' && concat_str[i] <= '9')
			|| concat_str[i] == ' ' || concat_str[i] == '-'
			|| concat_str[i] == '+')
			i++;
		else
			error();
	}
	return (concat_str);
}

void	checkerror1(int ac, char **av, char **concat_str)
{
	if (ac < 2)
		exit(0);
	*concat_str = ft_strdup(av[1]);
	if (!*concat_str)
		error();
}
