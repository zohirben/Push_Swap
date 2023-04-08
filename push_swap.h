/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:14:17 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:18 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Stack
{
	int	top;
	int	data[];
}	t_stack;

void	allocate_stacks(t_stack **stack_a, t_stack **stack_b,
			int *array, int array_len);
void	create_array(char ***numList, int **array, int *size, char *concat_str);
void	sort_stack_back(t_stack *stack_a, t_stack *stack_b);
void	rrx(char x, t_stack *stackA, t_stack *stackB);
void	sx(char x, t_stack *stackA, t_stack *stackB);
void	px(char x, t_stack *stackA, t_stack *stackB);
void	rx(char x, t_stack *stackA, t_stack *stackB);
void	increment_range(int *min_range, int *max_range, int max);
void	teen_case(t_stack *stack_a, t_stack *stack_b);
void	array_validation(char **numList, int **array, int size);
void	pushs(t_stack *stack1, t_stack *stack2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	set_range(int *min_range, int *max_range, int size);
void	push(t_stack *stack, int item, int max_size);
void	checkerror1(int ac, char **av, char **concat_str);
int		*turnarray(char *concat_str, int *array_len);
void	reverse_rotate(t_stack *stack);
char	**ft_split(char const *s, char c);
void	sorted_check(int *array, int arrlen);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	three_case(t_stack *stackA);
void	rotate(t_stack *stack);
char	*checkerror(int ac, char **av);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	sort_array(int *array, int n);
void	swap(t_stack *stack);
char	*valid_str(char *concat_str);
int		getmin(t_stack *stack_a);
int		isempty(t_stack *stack);
long	ft_atoi(const char *str);
int		getmax(t_stack *stack);
void	ft_str_is_num(char *str);
void	swap_int(int *a, int *b);
void	free_split(char **str);
void	error(void);

#endif