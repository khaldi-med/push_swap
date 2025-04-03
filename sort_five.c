#include "push_swap.h"

int ft_min_pos(t_stack *stack){
    int min_val = stack->value;
    int min_pos = 0;
    int curr_pos = 0;
    t_stack *tmp = stack;
    while(tmp){
        if(tmp->value < min_val)
        {
            min_val = tmp->value;
            min_pos = curr_pos;
        }
        tmp = tmp->next;
        curr_pos++;
    }
    return min_pos;
}

void ft_sort_five(t_stack **a, t_stack **b){
    int min_pos;
    int size;
    int pushed = 0;
    size = ft_stack_size(*a);
    if(size <= 3)
         return ft_sort_three(a);
    while(size - pushed > 3){
        min_pos = ft_min_pos(*a);
        while (min_pos > 0)
        {
            if(min_pos <= size / 2)
                ra(a);
            else
                rot_rev_a(a);
        min_pos = ft_min_pos(*a);
        }
        pb(a, b);
        pushed++;
    }
    ft_sort_three(a);
    while (*b)
        pa(a, b);
}