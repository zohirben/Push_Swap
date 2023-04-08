/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:13:39 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:56 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int item, int max_size)
{
	if (stack->top == max_size - 1)
	{
		printf("Stack OverFlow\n");
		return ;
	}
	stack->top++;
	stack->data[stack->top] = item;
}

int	isempty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

void	sx(char x, t_stack *stackA, t_stack *stackB)
{
	if (x == 'a')
	{
		if (stackA->top <= 1)
			return ;
		swap(stackA);
		printf("sa\n");
	}
	else if (x == 'b')
	{
		return ;
		swap(stackB);
		printf("sb\n");
	}
	else if (x == 's')
	{
		if (stackA->top <= 1 || stackB->top <= 1)
			return ;
		swap(stackA);
		swap(stackB);
		printf("ss\n");
	}
	return ;
}

void	pushs(t_stack *stack1, t_stack *stack2)
{
	stack1->top++;
	stack1->data[stack1->top] = stack2->data[stack2->top];
	stack2->top--;
}
