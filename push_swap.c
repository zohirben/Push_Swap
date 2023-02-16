#include "push_swap.h"

int checkerror(int ac, char **av)
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
        if ((concat_str[i] >= '0' && concat_str[i] <= '9') || concat_str[i] == ' ')
            i++;
        else
        {
            perror("Error: The Argument Contains A Non Digit Character\n");
            exit(1);
        }
    }
    printf("%s\n", concat_str);
    free(concat_str);
    return (0);
}

int main(int ac, char **av)
{
    // stack A
    // struct Stack stackA;
    // stackA.top = -1;
    checkerror(ac, av);
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
// make the program accept arguments and try to check errors in them / progress rn
// errors : no duplicate number, number not > int_max or < int_min, argument aren't integers. / not done yet
// maybe we should make a makefile that compiles libft library including printf in it. / done :D