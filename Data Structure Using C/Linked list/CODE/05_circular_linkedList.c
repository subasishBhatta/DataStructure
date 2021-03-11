#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBegin()
{
    int val;
    printf("Enter the value you want to enter: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *q = head;
        while (q->next != head)
        {
            q = q->next;
        }
        q->next = ptr;
        ptr->next = head;

        head = ptr;
    }
}

void insertByIndex()
{
    int val, index, ctr = 0;
    printf("Enter the index value where you want to insert a number: ");
    scanf("%d", &index);

    if (index == 1)
    {
        printf("You can't insert in the first index here, For this you have another choice..\n");
        return;
    }

    printf("Enter the value you want to insert in the circular linked list: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *c = head;
        do
        {
            ++ctr;
            c = c->next;
        } while (c != head);

        printf("%d\n", ctr);
        if (index >= ctr)
        {
            printf("The index you entered is greater than or equal tothe no of element in the circular linked list!!!\n");
        }
        else
        {
            struct node *p = head;
            for (int i = 1; i <= index - 1; i++)
            {
                ptr->next = p->next;
                p->next = ptr;
            }
        }
    }
}

void insertAtEnd()
{
    int val;
    printf("Enter the value you want to insert at the linked list: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }
}

void deleteAtBegin()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("There is nothing to delete!!!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("Node is deleted!!!\n");
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
    }
}

void deleteByIndex()
{
    int index, ctr = 0;
    if (head == NULL)
    {
        printf("There is nothing to delete!!!\n");
    }
    else if (head->next == head)
    {
        // head = NULL;
        free(head);
    }

    else
    {
        printf("Enter the index value where you want to delete the number: ");
        scanf("%d", &index);
        if (index == 1)
        {
            printf("You can't enter first index here, For that you have to choose other option from menu\n");
            return;
        }
        struct node *c = head;
        do
        {
            ++ctr;
            c = c->next;
        } while (c != head);
        if (index >= ctr)
        {
            printf("The index you entered is greater than or equal tothe no of element in the circular linked list!!!\n");
        }
        else
        {
            struct node *p = head;
            struct node *q = p->next;
            for (int i = 1; i < index - 1; i++)
            {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            free(q);
        }
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("There is nothing to delete!!!\n");
    }
    else if (head->next == head)
    {
        // head = NULL;
        free(head);
    }
    else
    {
        struct node *p = head;
        struct node *q = p->next;
        while (q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
}

void searchByValue()
{
    int val, ctr = 0, flag = 0;
    if (head == NULL)
    {
        printf("There isn't any element to find...\n");
        return;
    }
    else if (head->next == head)
    {
        printf("There is only one element in the circular linked list\n");
        return;
    }
    else
    {
        printf("Enter the value you want to search: ");
        scanf("%d", &val);

        struct node *p = head;
        do
        {
            ++ctr;
            if (p->data == val)
            {
                printf("The value %d is found at the index %d.\n", val, ctr);
                flag = 1;
            }
            p = p->next;

        } while (p != head);
        if (flag == 0)
        {
            printf("The value you entered is not found!!!\n");
        }
    }
}

void traverse()
{
    if (head == NULL)
    {
        printf("There is nothing to traverse\n");
    }
    else
    {
        struct node *p = head;
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != head);
        printf("\n");
    }
}

int main()
{
    // Creating the linked list menu
    int ch;

    while (1)
    {
        printf("========================================================\n");
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("========================================================\n");
        printf("1. Insert a node at the begining of the circular linked list\n");
        printf("2. Insert a node at any given index of the circular linked list\n");
        printf("3. Insert a node at the end of the circular linked list\n");

        printf("4. Delete a node at the begining of the circular linked list\n");
        printf("5. Delete a node at any given index of the circular linked list\n");
        printf("6. Delete a node at the end of the circular linked list\n");

        printf("7. Traverse the circular linked list\n");
        printf("8. Search any element by value in the circular linked list\n");
        printf("9. Quit the menu\n");
        printf("========================================================\n");

        printf("Enter your prefered choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertAtBegin();
            printf("The node is inserted!!!\n");
            sleep(1);
            break;
        case 2:
            insertByIndex();
            printf("The node is inserted!!!\n");
            sleep(1);
            break;
        case 3:
            insertAtEnd();
            printf("The node is inserted!!!\n");
            sleep(1);
            break;
        case 4:
            deleteAtBegin();
            sleep(1);
            break;
        case 5:
            deleteByIndex();
            printf("The node is deleted!!!\n");
            sleep(1);
            break;
        case 6:
            deleteAtEnd();
            printf("The node is deleted!!!\n");
            sleep(1);
            break;
        case 7:
            traverse();
            sleep(1);
            break;
        case 8:
            searchByValue();
            sleep(1);
            break;
        case 9:
            printf("Bye Bye!!!\n");
            exit(0);
            break;
        default:
            printf("Enter a valid input from the menu\n");
            break;
        }
    }

    // insertAtBegin();
    // insertAtBegin();
    // insertAtBegin();
    // insertAtBegin();
    // traverse();
    // insertByIndex();
    // traverse();
    // insertAtEnd();
    // traverse();
    // deleteAtBegin();
    // traverse();
    // deleteByIndex();
    // traverse();
    // deleteAtEnd();
    // traverse();
    // searchByValue();
    // traverse();

    return 0;
}