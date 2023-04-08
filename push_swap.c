#include "push_swap.h"

void sorted_check(int *array, int arrlen)
{
    int i;

    i = 0;
    while (i < arrlen - 1)
    {
        if (array[i] < array[i + 1])
            i++;
        else
            return;
    }
    exit(0);
}

int getmin(struct Stack *stack_a)
{
    int min;
    int i;

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
    return min;
}

void three_case(struct Stack *stackA)
{
    int idk1;
    int idk2;
    int idk3;

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

void teen_case(struct Stack *stack_a, struct Stack *stack_b)
{
    int index;
    int proximity;
    int min;

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

void printArray(int *array, int n)
{
    int i = 0;

    while (i < n)
    {
        if (i + 1 >= n)
            printf("%i\n", array[i]);
        else
            printf("%i, ", array[i]);
        i++;
    }
}

void swap_int(int *a, int *b)
{
    int tmp;

    tmp = *b;
    *b = *a;
    *a = tmp;
}

void sort_array(int *array, int n)
{
    int i;
    int min_index;
    int j;

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

int getmax(struct Stack *stack)
{
    int max;
    int i;

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
    return max;
}

void sort_stack_back(struct Stack *stack_a, struct Stack *stack_b)
{
    int index;
    int proximity;
    int max;

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

void set_range(int *min_range, int *max_range, int size)
{
    *min_range = 0;
    *max_range = size - 1;
}

int equal_range(int number, int min, int max, int *array)
{
    while (min <= max)
    {
        if (number == array[min])
            return (1);
        min++;
    }
    return (0);
}

void increment_range(int *min_range, int *max_range, int max)
{
    if (*max_range < max)
    {
        (*min_range)++;
        (*max_range)++;
    }
}

void range_out(struct Stack *stack_a, struct Stack *stack_b, int *shadow_array, int array_len, int range)
{
    int min_range;
    int max_range;
    set_range(&min_range, &max_range, range);
    while (!isempty(stack_a))
    {
        if (equal_range(stack_a->data[stack_a->top], min_range, max_range, shadow_array))
        {
            px('b', stack_a, stack_b);
            increment_range(&min_range, &max_range, array_len);
        }
        else if (stack_a->data[stack_a->top] < shadow_array[min_range])
        {
            px('b', stack_a, stack_b);
            rx('b', stack_a, stack_b);
        }
        else if (stack_a->data[stack_a->top] > shadow_array[max_range])
        {
            rx('a', stack_a, stack_b);
        }
    }
    sort_stack_back(stack_a, stack_b);
}

int main(int ac, char **av)
{
    char *concat_str;
    int *shadow_array;
    int array_len;
    struct Stack *stack_a;
    struct Stack *stack_b;

    concat_str = checkerror(ac, av);
    shadow_array = turnarray(concat_str, &array_len);
    allocate_stacks(&stack_a, &stack_b, shadow_array, array_len);
    sorted_check(shadow_array, array_len);
    sort_array(shadow_array, array_len);

    // printstack(stack_a, stack_b);
    if (array_len <= 10)
    {
        teen_case(stack_a, stack_b);
        sort_stack_back(stack_a, stack_b);
    }
    else if (array_len <= 100)
        range_out(stack_a, stack_b, shadow_array, array_len, 15);
    else if (array_len > 100)
        range_out(stack_a, stack_b, shadow_array, array_len, 30);
    free(shadow_array);
    free(stack_a);
    free(stack_b);
}
