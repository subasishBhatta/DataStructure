#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack[N];
int top = -1;

int isEmpty(int *p)
{
    if (top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(int *p)
{
    if (top == N - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Time complexity O(1)
void push()
{
    int val;
    if (isFull(stack))
    {
        printf("The stack is already Full!!!\n");
    }
    else
    {
        printf("Enter the value you want to push into the stack: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

// Time complexity O(1)
void pop()
{
    if (isEmpty(stack))
    {
        printf("The Stack is Underflow!!! There is nothing to pop out\n");
    }
    else
    {
        int val = stack[top];
        top--;
        printf("The value which popped out is %d.\n", val);
    }
}

// Time complexity O(1)
void peek()
{
    if (isEmpty(stack))
    {
        printf("The Stack is Underflow!!! There is nothing to peek\n");
    }
    else
    {
        printf("The top value in the stack is %d.\n", stack[top]);
    }
}

// Time complexity O(n)
void display()
{
    if (isEmpty(stack))
    {
        printf("The Stack is Underflow!!!\nThere is nothing to display!!!\n");
    }
    else
    {
        printf("The values are displayed from top of the stack to bottom\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n==================================================================\n");
        printf("                    Main menu for Stack Operation                  \n");
        printf("==================================================================\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye Bye!!!\n");
            exit(0);

        default:
            printf("Invalid Input!!!\n");
            break;
        }
    }

    return 0;
}