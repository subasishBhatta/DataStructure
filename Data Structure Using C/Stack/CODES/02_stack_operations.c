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

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!!! Can't enter %d in the stack.\n", val);
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }

}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!!!\n");
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}

int peek(struct stack *ptr, int i)
{
    if ((ptr->top - i + 1) < 0)
    {
        printf("The stack is Underflow!!!\n");
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
    
}

int main()
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));

    // Pushing the values into the stack
    push(sp, 12);
    push(sp, 22);
    push(sp, 32);
    push(sp, 42);
    push(sp, 52);
    push(sp, 62);
    push(sp, 72);
    push(sp, 82);
    push(sp, 92);
    push(sp, 2);
    push(sp, 122);

    // Popping out the values from the stack
    printf("The value poped out is %d.\n", pop(sp));
    printf("The value poped out is %d.\n", pop(sp));
    printf("The value poped out is %d.\n", pop(sp));

    // Peeking all the values remaining in the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d.\n", j+1, peek(sp, j));
    }

    return 0;
}