/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:49 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:50 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

char	*checkerror(int ac, char **av)
{
	int		i;
	char	*concat_str;
	char	*tmp;

	checkerror1(ac, av, &concat_str);
	i = 1;
	ft_str_is_num(av[i]);
	while (++i < ac)
	{
		tmp = ft_strjoin(concat_str, " ");
		free(concat_str);
		if (!tmp)
			exit(0);
		ft_str_is_num(av[i]);
		concat_str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!concat_str)
			error();
	}
	concat_str = valid_str(concat_str);
	return (concat_str);
}

void	create_array(char ***numList, int **array, int *size, char *concat_str)
{
	*numList = ft_split(concat_str, ' ');
	if (!*numList)
		error();
	*size = 0;
	while ((*numList)[(*size)])
		(*size)++;
	*array = (int *)malloc((*size) * sizeof(int));
	if (!*array)
		error();
}

void	array_validation(char **numList, int **array, int size)
{
	int		i;
	int		j;
	long	numcheck;

	i = -1;
	while (++i < size)
	{
		numcheck = ft_atoi(numList[i]);
		if (numcheck < INT_MIN || numcheck > INT_MAX)
			error();
		(*array)[i] = ft_atoi(numList[i]);
		j = 0;
		while (j < i)
		{
			if ((*array)[j] == (*array)[i])
				error();
			j++;
		}
	}
}

int	*turnarray(char *concat_str, int *array_len)
{
	char	**num_list;
	int		*array;
	int		size;

	create_array(&num_list, &array, &size, concat_str);
	array_validation(num_list, &array, size);
	*array_len = size;
	free_split(num_list);
	free(concat_str);
	return (array);
}
