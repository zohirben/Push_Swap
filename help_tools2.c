/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:53 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:54 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	sort_array(int *array, int n)
{
	int	i;
	int	min_index;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		min_index = i;
		while (j < n)
		{
			if (array[min_index] > array[j])
				min_index = j;
			j++;
		}
		swap_int(&array[min_index], &array[i]);
		i++;
	}
}

int	getmax(t_stack *stack)
{
	int	max;
	int	i;

	if (isempty(stack))
		error();
	max = 0;
	i = stack->top;
	if (stack->top == 0)
	{
		return (0);
	}
	while (i != -1)
	{
		if (stack->data[i] > stack->data[max])
			max = i;
		i--;
	}
	return (max);
}

int	getmin(t_stack *stack_a)
{
	int	min;
	int	i;

	if (isempty(stack_a))
	{
		exit(0);
	}
	min = 0;
	i = stack_a->top;
	if (stack_a->top == 0)
	{
		return (0);
	}
	while (i != -1)
	{
		if (stack_a->data[i] < stack_a->data[min])
			min = i;
		i--;
	}
	return (min);
}

void	sorted_check(int *array, int arrlen)
{
	int	i;

	i = 0;
	while (i < arrlen - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return ;
	}
	exit(0);
}
