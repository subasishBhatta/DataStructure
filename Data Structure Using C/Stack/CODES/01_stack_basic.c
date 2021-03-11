#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // (ptr->top) == (ptr->size -1) ? return 1 : return 0 ; 
}

int main()
{
    // struct stack s;
    // s.size = 6;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    // Manually inserting elements into the stack
    s->arr[0] = 5;
    s->top++;

    s->arr[1] = 15;
    s->top++;

    (*s).arr[2] = 25;
    s->top++;

    s->arr[3] = 35;
    s->top++;

    s->arr[4] = 45;
    s->top++;

    s->arr[5] = 55;
    s->top++;

    // Checking the status of the stack
    if (isEmpty(s))
    {
        printf("The stack is Empty!!!\n");
    }
    else
    {
        printf("The stack is not empty!!!\n");
    }
    
    if (isFull(s))
    {
        printf("The stack is Full!!!\n");
    }
    else
    {
        printf("The stack is not Full!!!\n");
    }
    
    return 0;
}