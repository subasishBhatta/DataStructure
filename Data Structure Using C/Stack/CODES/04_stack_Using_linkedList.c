#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value you want to insert in the stack: ");
    scanf("%d", &val);

    ptr->data = val;
    ptr->next = top;
    top = ptr;

    printf("Node is successfully inserted in the stack\n");
}

void pop()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("The stack is empty. There is nothing to be popped out!!!\n");
    }
    else
    {
        printf("The popped out value is %d.\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("The stack is empty. There is nothing to peek!!!\n");
    }
    else
    {
        printf("The top element in the stack is %d.\n", top->data);
    }
}

void display()
{
    struct node *p = top;
    if (top == NULL)
    {
        printf("There is nothing to display. The stack is completely empty!!!\n");
    }
    else
    {
        int ctr = 0;
        while (p != NULL)
        {
            ++ctr;
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\nThere are total %d no of elements in the stack\n", ctr);
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
            sleep(1);
            break;
        case 3:
            peek();
            sleep(1);
            break;
        case 4:
            display();
            sleep(2);
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