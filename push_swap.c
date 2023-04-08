/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:14:04 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:05 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	equal_range(int number, int min, int max, int *array)
{
	while (min <= max)
	{
		if (number == array[min])
			return (1);
		min++;
	}
	return (0);
}

void	range_out(t_stack *stack_a, t_stack *stack_b, int *shadow_array,
		int array_len)
{
	int	min_range;
	int	max_range;

	set_range(&min_range, &max_range, array_len);
	while (!isempty(stack_a))
	{
		if (equal_range(stack_a->data[stack_a->top], min_range, max_range,
				shadow_array))
		{
			px('b', stack_a, stack_b);
			increment_range(&min_range, &max_range, array_len);
		}
		else if (stack_a->data[stack_a->top] < shadow_array[min_range])
		{
			px('b', stack_a, stack_b);
			increment_range(&min_range, &max_range, array_len);
			rx('b', stack_a, stack_b);
		}
		else if (stack_a->data[stack_a->top] > shadow_array[max_range])
		{
			rx('a', stack_a, stack_b);
		}
	}
	sort_stack_back(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char	*concat_str;
	int		*shadow_array;
	int		array_len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	concat_str = checkerror(ac, av);
	shadow_array = turnarray(concat_str, &array_len);
	allocate_stacks(&stack_a, &stack_b, shadow_array, array_len);
	sorted_check(shadow_array, array_len);
	sort_array(shadow_array, array_len);
	if (array_len <= 10)
	{
		teen_case(stack_a, stack_b);
		sort_stack_back(stack_a, stack_b);
	}
	range_out(stack_a, stack_b, shadow_array, array_len);
	free(shadow_array);
	free(stack_a);
	free(stack_b);
}
