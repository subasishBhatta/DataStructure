#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

int isFull(int *q)
{
    if (rear >= N - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(int *q)
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is Full!!! We can't enter a new element into the queue!!!\n");
        return;
    }
    else if (isEmpty(q))
    {
        rear = front = 0;
        q[rear] = val;
    }
    else
    {
        rear++;
        q[rear] = val;
    }
}

void dequeue(int *q)
{
    if (isEmpty(q))
    {
        printf("There is nothing to dequeue in the Queue!!!\n");
        return;
    }
    else if (rear == front)
    {
        printf("The element to be dequeued is %d.\n", q[front]);
        rear = front = -1;
        return;
    }
    else
    {
        printf("The element to be dequeued is %d.\n", q[front]);
        front++;
    }
}

void display(int *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is empty. There is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The values in the Queue are...\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

void peek(int *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is empty. There is nothing to peek!!!\n");
        return;
    }
    else
    {
        printf("The front element in the Queue is %d.\n", q[front]);
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
            enqueue(queue, n);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            peek(queue);
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