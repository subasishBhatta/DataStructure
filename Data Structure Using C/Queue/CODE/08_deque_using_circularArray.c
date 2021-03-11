#include <stdio.h>
#include <stdlib.h>
#define N 5

int deque[N];
int front = -1;
int rear = -1;

void enqueueFront(int val)
{
    // if (front == (rear + 1) % N)
    if (front == 0 && rear == N - 1 || front == rear + 1)
    {
        printf("The Deque is Full and we can't enter the value in it!!!\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = val;
        printf("The value is inserted in the Deque.\n");
    }
    else if (front == 0)
    {
        front = N - 1;
        deque[front] = val;
        printf("The value is inserted in the Deque.\n");
    }
    else
    {
        front--;
        deque[front] = val;
        printf("The value is inserted in the Deque.\n");
    }
}

void enqueueRear(int val)
{
    if (front == 0 && rear == N - 1 || front == rear + 1)
    {
        printf("The Deque is Full and we can't enter the value in it!!!\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = val;
        printf("The value is inserted in the Deque.\n");
    }
    else if (rear == N - 1)
    {
        rear = 0;
        deque[rear] = val;
        printf("The value is inserted in the Deque.\n");
    }
    else
    {
        rear++;
        deque[rear] =val;
        printf("The value is inserted in the Deque.\n");
    }
}

void dequeueFront()
{
    if (front == -1 && rear == -1)
    {
        printf("The Deque is empty and there is nothing to delete!!!\n");
    }
    else if (front == rear)
    {
        printf("The dequeued value from the Deque is %d.", deque[front]);
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("The dequeued value from the Deque is %d.", deque[front]);
        front = 0;
    }
    else
    {
        printf("The dequeued value from the Deque is %d.", deque[front]);
        front++;
    }
}

void dequeueRear()
{
    if (front == -1 && rear == -1)
    {
        printf("The Deque is empty and there is nothing to delete!!!\n");
    }
    else if (front == rear)
    {
        printf("The dequeued value from the Deque is %d.", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("The dequeued value from the Deque is %d.", deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("The dequeued value from the Deque is %d.", deque[rear]);
        rear--;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("The Deque is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        int i = front;
        printf("The values in the Deque: \n");
        while (i != rear)
        {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d ", deque[i]);
        printf("\n");
    }
}

void getFront()
{
    if (front == -1 && rear == -1)
    {
        printf("The Deque is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The front element in the Deque is %d.\n", deque[front]);
    }
}

void getRear()
{
    if (front == -1 && rear == -1)
    {
        printf("The Deque is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The rear element in the Deque is %d.\n", deque[rear]);
    }
}

int main()
{
    while (1)
    {
        int ch, n;

        printf("\n==================================================================\n");
        printf("                    Main menu for Deque Operation                  \n");
        printf("==================================================================\n");
        printf("1. Enqueue at the Front\n");
        printf("2. Enqueue at the Rear\n");
        printf("3. Dequeue at the Front\n");
        printf("4. Dequeue at the Rear\n");
        printf("5. Get the front value\n");
        printf("6. Get the Rear value\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value you want to enter: ");
            scanf("%d", &n);
            enqueueFront(n);
            break;
        case 2:
            printf("Enter the value you want to enter: ");
            scanf("%d", &n);
            enqueueRear(n);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            getFront();
            break;
        case 6:
            getRear();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting!!!\n");
            exit(0);
        default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }

    return 0;
}