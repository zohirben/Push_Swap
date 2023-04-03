#include "push_swap.h"

void    push(struct Stack *stack, int item, int max_size)
{
    if (stack->top == max_size - 1)
    {
        printf("Stack OverFlow\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack UnderFlow\n");
        return -1;
    }

    stack->top--;
    return stack->data[stack->top];
}

int peek(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Is Empty\n");
        return -1;
    }

    return stack->data[stack->top];
}

int isempty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        // printf("Error : Stock Is Empty!\n");
        return (1);
    }
    return (0);
}

void printstack(struct Stack *stackA, struct Stack *stackB)
{
    int i = stackA->top;
    int j = stackB->top;
    printf("stack:\n");
    while(i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            printf("%d ", stackA->data[i]);
            i--;
        }
        else
            printf("  ");
        if (j >= 0)
        {
            printf("--- %d", stackB->data[j]);
            j--;
        }
        printf("\n");
    }
    if (i <= 0 && j <= 0)
    {
        printf("_ _\n");
        printf("a b\n");
    }
}

void    swap(struct Stack *stack)
{
    int temp;

    temp = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top-1];
    stack->data[stack->top - 1] = temp;
}

void    sx(char x, struct Stack *stackA, struct Stack *stackB)
{
    if (x == 'a')
    {
        if (stackA->top <= 1)
        {
            printf("Theres Only 1 Element Or None!\n");
            return;
        }
        swap(stackA);
        printf("sa\n");
    }
    else if (x == 'b')
    {
        if (stackB->top <= 1)
        {
            printf("Theres Only 1 Element Or None!\n");
            return;
        }
        swap(stackB);
        printf("sb\n");
    }
    else if (x == 's')
    {
        if (stackA->top <= 1 || stackB->top <= 1)
        {
            printf("Theres Only 1 Element Or None!\n");
            return;
        }
        swap(stackA);
        swap(stackB);
        printf("ss\n");
    }
    return;
}

void    pushs(struct Stack *stack1, struct Stack *stack2)
{
    stack1->top++;
    stack1->data[stack1->top] = stack2->data[stack2->top];
    stack2->top--;
}

void    px(char x, struct Stack *stackA, struct Stack *stackB)
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
    return;
}

void    rotate(struct Stack *stack)
{
    //first store the stack[top max] in a temp variable
    //shift elements up by replacing stack[top] with stack[top - 1]
    int i = stack->top;
    int temp = stack->data[i];
    while(i > 0)
    {
        stack->data[i] = stack->data[i-1];
        i--;
    }
    stack->data[i] = temp;
}

void    rx(char x, struct Stack *stackA, struct Stack *stackB)
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
    return;
}

void    reverseRotate(struct Stack *stack)
{
    //first store the stack[0] in a temp variable
    //shift elements up by replacing stack[top] with stack[top + 1]
    int i = 0;
    int temp = stack->data[0];
    while(i < stack->top)
    {
        stack->data[i] = stack->data[i+1];
        i++;
    }
    stack->data[i] = temp;
}

void    rrx(char x, struct Stack *stackA, struct Stack *stackB)
{
    if (x == 'a')
    {
        reverseRotate(stackA);
        printf("rra\n");
    }
    else if (x == 'b')
    {
        reverseRotate(stackB);
        printf("rrb\n");
    }
    else if (x == 'r')
    {
        reverseRotate(stackA);
        reverseRotate(stackB);
        printf("rrr\n");
    }
    return;
}
