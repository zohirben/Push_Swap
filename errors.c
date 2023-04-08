#include "push_swap.h"

void ft_str_is_num(char *str)
{
    int i;

    i = -1;
    if (ft_strlen(str) == 0)
        error();
    while (str[++i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            return;
    }
    error();
}

char *valid_str(char *concat_str)
{
    int i;

    i = 0;
    while (concat_str[i])
    {
        if ((concat_str[i] >= '0' && concat_str[i] <= '9') || concat_str[i] == ' ' || concat_str[i] == '-' || concat_str[i] == '+')
            i++;
        else
            error();
    }
    return (concat_str);
}

void checkerror1(int ac, char **av, char **concat_str)
{
    if (ac < 2)
        exit(0);
    *concat_str = ft_strdup(av[1]);
    if (!*concat_str)
        error();
}

void error(void)
{
    ft_putstr_fd("Error\n", 2);
    exit(0);
}

char *checkerror(int ac, char **av)
{
    int i;
    char *concat_str;
    char *tmp;

    checkerror1(ac, av, &concat_str);
    i = 1;
    ft_str_is_num(av[i]);
    while (++i < ac)
    {
        tmp = ft_strjoin(concat_str, " ");
        free(concat_str);
        if (!tmp)
            exit(0);
        ft_str_is_num(av[i]);
        concat_str = ft_strjoin(tmp, av[i]);
        free(tmp);
        if (!concat_str)
            error();
    }
    concat_str = valid_str(concat_str);
    return (concat_str);
}

void create_array(char ***numList, int **array, int *size, char *concat_str)
{
    *numList = ft_split(concat_str, ' ');
    if (!*numList)
        error();
    *size = 0;
    while ((*numList)[(*size)])
        (*size)++;
    *array = (int *)malloc((*size) * sizeof(int));
    if (!*array)
        error();
}

void array_validation(char **numList, int **array, int size)
{
    int i;
    int j;
    long numcheck;

    i = -1;
    while (++i < size)
    {
        numcheck = ft_atoi(numList[i]);
        if (numcheck < INT_MIN || numcheck > INT_MAX)
            error();
        (*array)[i] = ft_atoi(numList[i]);
        j = 0;
        while (j < i)
        {
            if ((*array)[j] == (*array)[i])
                error();
            j++;
        }
    }
}

int *turnarray(char *concat_str, int *array_len)
{
    char **num_list;
    int *array;
    int size;

    create_array(&num_list, &array, &size, concat_str);
    array_validation(num_list, &array, size);
    *array_len = size;
    free_split(num_list);
    free(concat_str);
    return (array);
}
