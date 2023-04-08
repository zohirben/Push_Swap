/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:57 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:58 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(char x, t_stack *stackA, t_stack *stackB)
{
	if (x == 'a')
	{
		if (!isempty(stackB))
		{
			pushs(stackA, stackB);
			printf("pa\n");
		}
	}
	else if (x == 'b')
	{
		if (!isempty(stackA))
		{
			pushs(stackB, stackA);
			printf("pb\n");
		}
	}
	return ;
}

void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->top;
	temp = stack->data[i];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[i] = temp;
}

void	rx(char x, t_stack *stackA, t_stack *stackB)
{
	if (x == 'a')
	{
		rotate(stackA);
		printf("ra\n");
	}
	else if (x == 'b')
	{
		rotate(stackB);
		printf("rb\n");
	}
	else if (x == 'r')
	{
		rotate(stackA);
		rotate(stackB);
		printf("rr\n");
	}
	return ;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->data[0];
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = temp;
}

void	rrx(char x, t_stack *stackA, t_stack *stackB)
{
	if (x == 'a')
	{
		reverse_rotate(stackA);
		printf("rra\n");
	}
	else if (x == 'b')
	{
		reverse_rotate(stackB);
		printf("rrb\n");
	}
	else if (x == 'r')
	{
		reverse_rotate(stackA);
		reverse_rotate(stackB);
		printf("rrr\n");
	}
	return ;
}
