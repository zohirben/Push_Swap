#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<unistd.h>

struct Stack {
    int top;
    int data[];
};

void allocate_stacks(struct Stack **stack_a, struct Stack **stack_b, int *array, int array_len);
void create_array(char ***numList, int **array, int *size, char *concat_str);
void    rrx(char x, struct Stack *stackA, struct Stack *stackB);
void    sx(char x, struct Stack *stackA, struct Stack *stackB);
void    px(char x, struct Stack *stackA, struct Stack *stackB);
void    rx(char x, struct Stack *stackA, struct Stack *stackB);
// void array_validation(char **numList, int **array, int size);
void printstack(struct Stack *stackA, struct Stack *stackB);
void    pushs(struct Stack *stack1, struct Stack *stack2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void push(struct Stack *stack, int item, int max_size);
void checkerror1(int ac, char **av, char **concat_str);
int *turnarray(char *concat_str, int *array_len);
void    reverseRotate(struct Stack *stack);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void    rotate(struct Stack *stack);
char *checkerror(int ac, char **av);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void    swap(struct Stack *stack);
char *valid_str(char *concat_str);
int isempty(struct Stack *stack);
long    ft_atoi(const char *str);
void ft_str_is_num(char *str);
int peek(struct Stack *stack);
int pop(struct Stack *stack);
void free_split(char **str);
void error(void);

#endif