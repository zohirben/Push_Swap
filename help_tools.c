/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:51 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:52 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	allocate_stacks(t_stack **stack_a, t_stack **stack_b,
		int *array, int array_len)
{
	int	i;

	*stack_a = malloc(sizeof(t_stack) + array_len * sizeof(int));
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	(*stack_a)->top = -1;
	*stack_b = malloc(sizeof(t_stack) + array_len * sizeof(int));
	if (!stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	(*stack_b)->top = -1;
	i = array_len - 1;
	while (i >= 0)
	{
		push(*stack_a, array[i], array_len);
		i--;
	}
}
