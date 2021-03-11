#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[rear] = val;
        printf("The value %d is inserted into the Queue.\n", val);
    }
    else if (((rear + 1) % N) == front)
    {
        printf("The Queue is full, we can't insert %d into the Queue!!!\n", val);
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = val;
        printf("The value %d is inserted into the Queue.\n", val);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is empty!!!There is nothing to delete!!!\n");
        return;
    }
    else if (front == rear)
    {
        printf("The value to be dequeued is %d.", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The value to be dequeued is %d.", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (front == -1)
    {
        printf("The Queue is empty!!! There is nothing to display!!!\n");
    }
    else if (front == rear)
    {
        printf("The elements in the Queue are: \n");
        printf("%d \n", queue[front]);
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[i]);
        printf("\n");
    }
}

void peek()
{
    if (front == -1)
    {
        printf("The Queue is empty!!! There is nothing to peek!!!\n");
    }
    else
    {
        printf("The front element in the Queue is %d.\n", queue[front]);
    }
}

int main()
{
    while (1)
    {
        int ch, n;

        printf("\n==================================================================\n");
        printf("                    Main menu for  Circular Queue Operation                  \n");
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