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

void    rrx(char x, struct Stack *stackA, struct Stack *stackB);
void    sx(char x, struct Stack *stackA, struct Stack *stackB);
void    px(char x, struct Stack *stackA, struct Stack *stackB);
void    rx(char x, struct Stack *stackA, struct Stack *stackB);
void printstack(struct Stack *stackA, struct Stack *stackB);
void    pushs(struct Stack *stack1, struct Stack *stack2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void    reverseRotate(struct Stack *stack);
char	**ft_split(char const *s, char c);
void push(struct Stack *stack, int item, int max_size);
char	*ft_strjoin(char *s1, char *s2);
void    rotate(struct Stack *stack);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void    swap(struct Stack *stack);
int isempty(struct Stack *stack);
long    ft_atoi(const char *str);
int peek(struct Stack *stack);
int pop(struct Stack *stack);

#endif