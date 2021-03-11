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
    printf("Enter the value to enter into the Queue: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = rear = ptr;
        printf("Node is inserted into the Queue\n");
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        printf("Node is inserted into the Queue\n");
    }
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("The Queue is empty and there is nothing to delete!!!\n");
        return;
    }
    else
    {
        printf("The dequeued element is %d.\n", front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("The Queue is empty and there is nothing to display!!!\n");
        return;
    }
    else
    {
        int ctr = 0;
        struct node *ptr = front;
        while (ptr != NULL)
        {
            ++ctr;
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("The Queue is empty and there is nothing to peek!!!\n");
        return;
    }
    else
    {
        printf("The front element is %d.", front->data);
        return;
    }
}

int main()
{
    while (1)
    {
        int ch;

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