#include <stdio.h>
#include <stdlib.h>
#define N 5

int s1[N], s2[N];
int top1 = -1;
int top2 = -1;
int ctr = 0;

void push1(int val)
{
    if (top1 == N - 1)
    {
        printf("The Queue is Full, we can't enter the value into the Queue!!!\n");
        return;
    }
    else
    {
        top1++;
        s1[top1] = val;
    }
}

void push2(int val)
{
    if (top2 == N - 1)
    {
        printf("The Queue is Full, we can't enter the value into the Queue!!!\n");
        return;
    }
    else
    {
        top2++;
        s2[top2] = val;
    }
}

int pop1()
{
    int c = s1[top1];
    --top1;
    return c;
}

int pop2()
{
    int c = s2[top2];
    --top2;
    return c;
}

void enqueue(int val)
{
    push1(val);
    ctr++;
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty and there is nothing to delete!!!\n");
        return;
    }
    else
    {
        for (int i = 0; i < ctr; i++)
        {
            int a = pop1();
            push2(a);
        }
        int b = pop2();
        printf("The dequeued element is %d.", b);
        --ctr;
        for (int i = 0; i < ctr; i++)
        {
            int b = pop2();
            push1(b);
        }
    }
}

void display()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The elements in the Queue: \n");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d ", s1[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty and there is nothing peek\n");
        return;
    }
    else
    {
        printf("The front element in the Queue is %d.", s1[0]);
    }
}

int main()
{
    while (1)
    {
        int ch, n;

        printf("\n==================================================================\n");
        printf("                    Main menu for Queue Operation                  \n");
        printf("==================================================================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value you want to enter: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Exiting!!!\n");
            exit(0);
        default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }
    return 0;
}