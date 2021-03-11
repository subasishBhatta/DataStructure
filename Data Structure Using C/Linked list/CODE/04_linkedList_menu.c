#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void traverse();
void insertAtBegin();
void insertByIndex();
void insertAtEnd();
void deleteAtBegin();
void deleteByindex();
void deleteAtEnd();
void searchByValue();

int main()
{
    // Creating the linked list menu
    int ch;

    printf("\n\n*********Main Menu*********\n");
    printf("\nChoose one option from the following list ...\n");
    printf("========================================================\n");
    printf("1. Insert a node at the begining of the linked list\n");
    printf("2. Insert a node at any given index of the linked list\n");
    printf("3. Insert a node at the end of the linked list\n");

    printf("4. Delete a node at the begining of the linked list\n");
    printf("5. Delete a node at any given index of the linked list\n");
    printf("6. Delete a node at the end of the linked list\n");

    printf("7. Traverse the linked list\n");
    printf("8. Search any element by value in the linked list\n");
    printf("9. Quit the menu\n");
    printf("========================================================\n");

    while (1)
    {
        printf("Enter your prefered choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            insertByIndex();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteByindex();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            traverse();
            break;
        case 8:
            searchByValue();
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
    // traverse();
    // insertByIndex();
    // traverse();
    // insertAtEnd();
    // traverse();
    // deleteAtBegin();
    // traverse();
    // deleteByindex();
    // traverse();
    // deleteAtEnd();
    // traverse();
    // searchByValue();
    // traverse();

    return 0;
}

void traverse()
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertAtBegin()
{
    int val;
    printf("Enter the value you want to enter: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    ptr->next = head;
    head = ptr;
}

void insertByIndex()
{
    int val, index, ctr = 0;
    printf("Enter the index where you want to enter the number: ");
    scanf("%d", &index);

    printf("Enter the number you want to enter: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    struct node *p = head;
    while (p != NULL)
    {
        ++ctr;
        p = p->next;
    }
    printf("%d\n", ctr);
    if (index >= ctr)
    {
        printf("Can't enter the value you are given! You have exceeded the no of elements in the linked list\n");
    }
    else
    {
        struct node *a = head;
        for (int i = 1; i < index - 1; i++)
        {
            a = a->next;
        }
        ptr->next = a->next;
        a->next = ptr;
    }
}

void insertAtEnd()
{
    int val;
    printf("Enter the value you want to enter: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
}

void deleteAtBegin()
{
    char ch;
    printf("Please verify, are you sure you want to delete the first element?\n");
    printf("Enter 'y' for sure and 'n' if you are not sure: ");
    fflush(stdin);
    scanf("%c", &ch);

    if (ch == 'y')
    {
        struct node *p = head;
        head = head->next;
        free(p);
    }
    else
    {
        return;
    }
}

void deleteByindex()
{
    int index, ctr = 0;
    printf("Enter the index value which you want to delete: ");
    scanf("%d", &index);

    struct node *a = head;
    while (a != NULL)
    {
        ++ctr;
        a = a->next;
    }

    if (index >= ctr)
    {
        printf("The index value you entered exceeds the number of element in the linked list\n");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;

        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
}

void deleteAtEnd()
{
    char ch;
    printf("Please verify, are you sure you want to delete the last element in the linked list?\n");
    printf("Enter 'y' for sure and 'n' if you are not sure: ");
    fflush(stdin);
    scanf("%c", &ch);

    if (ch == 'y')
    {
        struct node *p = head;
        struct node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
    }
    else
    {
        return;
    }
}

void searchByValue()
{
    int val, ctr = 0;
    printf("Enter the value you want to search in the linked list: ");
    scanf("%d", &val);

    struct node *p = head;
    while (p != NULL)
    {
        ++ctr;
        if (p->data == val)
        {
            printf("The number %d, you entered is found at the index value: %d\n", val, ctr);
            break;
        }
        p = p->next;
    }
}