#include "push_swap.h"

char    *checkerror(int ac, char **av)
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
    while(concat_str[i])
    {
        //make sure to check whithin theres a number before + or -, if theres return
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

void    free_split(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int *turnarray(char *concat_str)
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
    while(++i < size)
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
    free_split(numList);
    free(concat_str);
    return (array);
}
//array length
int arrlen(int *array)
{
    int i;

    i = 0;
    while(array[i])
        i++;
    return (i);
}

void    allocate_stacks(struct Stack **stack_a, struct Stack **stack_b, int *array, int array_len)
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
    while(i < array_len)
    {
        push(&stack_a, array[i], array_len);
        i++;
    }
}

int main(int ac, char **av)
{
    char *concat_str;
    int *shadow_array;
    int array_len;
    struct Stack *stack_a;
    struct Stack *stack_b;
    
    // stack A
    // struct Stack stackA;
    // stackA.top = -1;
    concat_str = checkerror(ac, av);
    shadow_array = turnarray(concat_str);
    array_len = arrlen(shadow_array);
    allocate_stacks(&stack_a, &stack_b, shadow_array, array_len);
    // push(&stackA, 8);
    // push(&stackA, 5);
    // push(&stackA, 6);
    // push(&stackA, 3);
    // push(&stackA, 1);
    // push(&stackA, 2);
    
    // stack B

    // struct Stack stackB;
    // stackB.top = -1;
    
    //print the stack before rotationw
    // printstack(&stackA, &stackB);
    // sx('a', &stackA, &stackB);
    // px('b', &stackA, &stackB);
    // px('b', &stackA, &stackB);
    // px('b', &stackA, &stackB);
    // sx('a', &stackA, &stackB);
    // px('a', &stackA, &stackB);
    // px('a', &stackA, &stackB);
    // px('a', &stackA, &stackB);

    // printstack(&stackA, &stackB);
}
