#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *arr;
    int rear;
    int front;
};

int isFull(struct queue *p)
{
    if (p->rear >= p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *p)
{
    if (p->front == -1 && p->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is Full!!! We can't enter a new element into the queue!!!\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->rear = q->front = 0;
        q->arr[q->rear] = val;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("There is nothing to dequeue in the Queue!!!\n");
        return;
    }
    else if (q->rear == q->front)
    {
        printf("The element to be dequeued is %d.\n", q->arr[q->front]);
        q->rear = q->front = -1;
        return;
    }
    else
    {
        printf("The element to be dequeued is %d.\n", q->arr[q->front]);
        q->front++;
    }
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is empty. There is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The values in the Queue are...\n");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The Queue is empty. There is nothing to peek!!!\n");
        return;
    }
    else
    {
        printf("The front element in the Queue is %d.\n", q->arr[q->front]);
    }
}

int main()
{
    int capacity;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    printf("Enter the size of the Queue, you want to create: ");
    scanf("%d", &capacity);
    q->size = capacity;
    q->rear = -1;
    q->front = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

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
            enqueue(q, n);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            peek(q);
            break;
        case 5:
            printf("Exiting!!!\n");
            exit(0);
        default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }

    // enqueue(q, 12);
    // enqueue(q, 23);
    // enqueue(q, 34);
    // enqueue(q, 45);
    // display(q);
    // peek(q);
    // dequeue(q);
    // peek(q);
    // display(q);
    // enqueue(q, 55);
    // enqueue(q, 65);
    // enqueue(q, 75);
    // display(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // display(q);
    // peek(q);

    return 0;
}