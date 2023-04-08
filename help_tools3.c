/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:54 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:55 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_case(t_stack *stackA)
{
	int	idk1;
	int	idk2;
	int	idk3;

	idk1 = stackA->data[2];
	idk2 = stackA->data[1];
	idk3 = stackA->data[0];
	if (idk1 > idk2 && idk2 < idk3 && idk3 > idk1)
		sx('a', stackA, stackA);
	else if (idk1 > idk2 && idk2 > idk3 && idk3 < idk1)
	{
		sx('a', stackA, stackA);
		rrx('a', stackA, stackA);
	}
	else if (idk1 > idk2 && idk2 < idk3 && idk3 < idk1)
		rx('a', stackA, stackA);
	else if (idk1 < idk2 && idk2 > idk3 && idk3 > idk1)
	{
		sx('a', stackA, stackA);
		rx('a', stackA, stackA);
	}
	else if (idk1 < idk2 && idk2 > idk1 && idk3 < idk1)
		rrx('a', stackA, stackA);
}

void	teen_case(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	proximity;
	int	min;

	while (stack_a->top >= 3)
	{
		index = getmin(stack_a);
		min = stack_a->data[index];
		proximity = (stack_a->top) / 2;
		while (stack_a->data[stack_a->top] != min)
		{
			if (index >= proximity)
				rx('a', stack_a, stack_b);
			else
				rrx('a', stack_a, stack_b);
		}
		if (stack_a->data[stack_a->top] == min)
			px('b', stack_a, stack_b);
	}
	if (stack_a->top == 1)
		rx('a', stack_a, stack_b);
	else
		three_case(stack_a);
}

void	set_range(int *min_range, int *max_range, int size)
{
	if (size <= 100)
		size = 15;
	else if (size > 100)
		size = 30;
	*min_range = 0;
	*max_range = size - 1;
}

void	sort_stack_back(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	proximity;
	int	max;

	while (!isempty(stack_b))
	{
		index = getmax(stack_b);
		max = stack_b->data[index];
		proximity = (stack_b->top) / 2;
		while (stack_b->data[stack_b->top] != max)
		{
			if (index >= proximity)
				rx('b', stack_a, stack_b);
			else
				rrx('b', stack_a, stack_b);
		}
		px('a', stack_a, stack_b);
	}
}

void	increment_range(int *min_range, int *max_range, int max)
{
	if (*max_range < max)
	{
		(*min_range)++;
		(*max_range)++;
	}
	else
		return ;
}
