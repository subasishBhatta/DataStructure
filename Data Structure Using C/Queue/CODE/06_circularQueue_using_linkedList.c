#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    int val;
    printf("Enter the value you want to insert: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (rear == NULL)
    {
        front = rear = ptr;
        rear->next = front;
        printf("The Node is inserted in the Queue!!!\n");
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = front;
        printf("The Node is inserted in the Queue!!!\n");
    }
}

void dequeue()
{
    struct node *temp = front;
    if (rear == NULL)
    {
        printf("The Queue is empty!!! There is nothing to delete in the Queue!!!\n");
    }
    else if (front == rear)
    {
        printf("The Node %d is dequeued!!!\n", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("The Node %d is dequeued!!!\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (rear == NULL)
    {
        printf("The Queue is empty!!! There is nothing to peek!!!\n");
        return;
    }
    else
    {
        printf("The front element in the Queue is %d.", front->data);
        return;
    }
}

void display()
{
    int ctr = 0;
    struct node *p = front;
    if (rear == NULL)
    {
        printf("The Queue is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        printf("The elemnts in the Queue: \n");
        do
        {
            ctr++;
            printf("%d ", p->data);
            p = p->next;
        } while (p != front);
    }
}

int main()
{
    while (1)
    {
        int ch;

        printf("\n==================================================================\n");
        printf("                    Main menu for Circular Queue Operation                  \n");
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
            enqueue();
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