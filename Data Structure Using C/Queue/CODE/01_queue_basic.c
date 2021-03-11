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

int main()
{
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->size = 5;
    q->rear = -1;
    q->front = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    // Manually inserting elements into the queue
    q->arr[0] = 12;
    q->rear++;
    q->front++;
    q->arr[1] = 52;
    q->rear++;
    q->front++;
    q->arr[2] = 42;
    q->rear++;
    q->front++;
    q->arr[3] = 32;
    q->rear++;
    q->front++;
    q->arr[4] = 22;
    q->rear++;
    q->front++;

    if (isEmpty(q))
    {
        printf("The Queue is empty\n");
    }
    else
    {
        printf("The Queue is not empty.\n");
    }
    
    
    if (isFull(q))
    {
        printf("The queue is Full.\n");
    }
    else
    {
        printf("The Queue is not full.\n");
    }
    
    

    return 0;
}