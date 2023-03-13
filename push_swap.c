#include "push_swap.h"

char *checkerror(int ac, char **av)
{
    int i;
    char *concat_str;
    char *tmp;

    if (ac < 2)
    {
        perror("Error: Not Enough Arguments!");
        exit(1);
    }
    concat_str = ft_strdup(av[1]);
    if (!concat_str)
    {
        perror("Error : Argument Is Empty!");
        exit(1);
    }
    i = 1;
    while (++i < ac)
    {
        tmp = ft_strjoin(concat_str, " ");
        free(concat_str);
        if (!tmp)
        {
            perror("Error : Memory Allocation Failed!");
            exit(1);
        }
        concat_str = ft_strjoin(tmp, av[i]);
        free(tmp);
        if (!concat_str)
        {
            perror("Error : Memory Allocation Failed!");
            exit(1);
        }
    }
    i = 0;
    while (concat_str[i])
    {
        // make sure to check whithin theres a number before + or -, if theres return
        if ((concat_str[i] >= '0' && concat_str[i] <= '9') || concat_str[i] == ' ' || concat_str[i] == '-' || concat_str[i] == '+')
            i++;
        else
        {
            perror("Error: The Argument Contains A Non Digit Character\n");
            exit(1);
        }
    }
    return (concat_str);
}

void free_split(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int *turnarray(char *concat_str, int *array_len)
{
    char **numList;
    int *array;
    int size;
    int i;
    int j;

    numList = ft_split(concat_str, ' ');
    if (!numList)
    {
        perror("Error: Spliting The String Failed\n");
        exit(1);
    }
    size = 0;
    while (numList[size])
    {
        //   printf("%s\n", numList[size]);
        size++;
    }
    array = (int *)malloc(size * sizeof(int));
    if (!array)
    {
        perror("Error: The Allocation Of The Array Is Failed\n");
        exit(1);
    }
    i = -1;
    while (++i < size)
    {
        long numcheck = ft_atoi(numList[i]);
        if (numcheck < INT_MIN || numcheck > INT_MAX)
        {
            perror("Error: Out Of Integer Range!\n");
            exit(1);
        }
        array[i] = ft_atoi(numList[i]);
        j = 0;
        while (j < i)
        {
            if (array[j] == array[i])
            {
                perror("Error: There's A Duplicated Number!\n");
                exit(1);
            }
            j++;
        }
    }
    *array_len = size;
    free_split(numList);
    free(concat_str);
    return (array);
}

void allocate_stacks(struct Stack **stack_a, struct Stack **stack_b, int *array, int array_len)
{
    int i;

    *stack_a = malloc(sizeof(struct Stack) + array_len * sizeof(int));
    if (!stack_a)
    {
        perror("Error: Memory Allocation Failed!\n");
        exit(1);
    }
    (*stack_a)->top = -1;
    *stack_b = malloc(sizeof(struct Stack) + array_len * sizeof(int));
    if (!stack_b)
    {
        perror("Error: Memory Allocation Failed!\n");
        exit(1);
    }
    (*stack_b)->top = -1;
    i = 0;
    while (i < array_len)
    {
        push(*stack_a, array[i], array_len);
        i++;
    }
}

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
    perror("Array Is Sorted Already!\n");
    exit(0);
}

void reverse_sorted_check(int *array, int arrlen, struct Stack *stackA)
{
    int i;

    i = 0;
    while (i < arrlen - 1)
    {
        if (array[i] > array[i + 1])
            i++;
        else
            return;
    }
    i = 0;
    while (i < arrlen)
    {
        rx('a', stackA, stackA);
        i++;
    }
}

int getmin(struct Stack *stack_a)
{
    int min;
    int i;

    if (isempty(stack_a))
    {
        perror("Theres no Element!\n");
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
    {
        sx('a', stackA, stackA);
    }
    else if (idk1 > idk2 && idk2 > idk3 && idk3 < idk1)
    {
        sx('a', stackA, stackA);
        rrx('a', stackA, stackA);
    }
    else if (idk1 > idk2 && idk2 < idk3 && idk3 < idk1)
    {
        rx('a', stackA, stackA);
    }
    else if (idk1 < idk2 && idk2 > idk3 && idk3 > idk1)
    {
        sx('a', stackA, stackA);
        rx('a', stackA, stackA);
    }
    else if (idk1 < idk2 && idk2 > idk1 && idk3 < idk1)
    {
        rrx('a', stackA, stackA);
    }
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

        while (stack_a->data[stack_a->top] != min && !isempty(stack_a))
        {
            if (index >= proximity)
                rx('a', stack_a, stack_b);
            else
                rrx('a', stack_a, stack_b);
        }
        px('b', stack_a, stack_b);
    }
    three_case(stack_a);
}

void    printArray(int *array, int n)
{
    int i = 0;

    while (i < n)
    {
        if (i+1 >= n)
            printf("%i\n", array[i]);
        else
            printf("%i, ", array[i]);
        i++;
    }
}

void    swap_int(int *a, int *b)
{
    int tmp;

    tmp = *b;
    *b = *a;
    *a = tmp;
}

void    sort_array(int *array, int n)
{
    //selection sort
    int i;
    int min_index;
    int j;

    i = 0;
    while(i < n - 1)
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

void    quarter_sort(struct Stack *stack_A, struct Stack *stack_B, int length, int divider)
{
    static int divide;
    int key_nbr;

    divide = divider;
    key
}

int main(int ac, char **av)
{
    char *concat_str;
    int *shadow_array;
    int array_len;
    struct Stack *stack_a;
    struct Stack *stack_b;

    array_len = 0;
    concat_str = checkerror(ac, av);
    shadow_array = turnarray(concat_str, &array_len);
    allocate_stacks(&stack_a, &stack_b, shadow_array, array_len);
    sorted_check(shadow_array, array_len);

    // printArray(shadow_array, array_len);
    sort_array(shadow_array, array_len);
    quarter_sort(stack_a, stack_b, array_len, 4);


    // if (array_len <= 10)
    //     teen_case(stack_a, stack_b);
    // printstack(stack_a, stack_b);
    // while(!isempty(stack_b))
    // {
    //     px('a', stack_a, stack_b);
    // }
    // printstack(stack_a, stack_b);
}
