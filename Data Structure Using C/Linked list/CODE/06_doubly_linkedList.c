#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <conio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void createNode()
{
    int val, ch;

    while (ch)
    {
        printf("\nEnter the value for the node: ");
        scanf("%d", &val);

        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->next = NULL;
        ptr->prev = NULL;

        if (head == NULL)
        {
            head = tail = ptr;
        }
        else
        {
            tail->next = ptr;
            ptr->prev = tail;
            tail = ptr;
        }
        printf("\nDo you want to add more no of nodes?\n");
        printf("Press '1' to ADD and '0' to EXIT\n");
        scanf("%d", &ch);
    }
}

void traverse()
{
    printf("\n");
    int ctr = 0;
    struct node *c = head;
    while (c != NULL)
    {
        ++ctr;
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
    sleep(1);
}

void insertAtBegin()
{
    int val;
    printf("\nEnter the value you want to insert in the at the begining of the linked list: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = tail = ptr;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void insertAtEnd()
{
    int val;
    printf("\nEnter the value you want to insert in the at the end of the linked list: ");
    scanf("%d", &val);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL)
    {
        head = tail = ptr;
    }
    else
    {
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
}

void insertByIndex()
{
    int index, val, ctr = 0;
    printf("\nEnter the index value where you want to insert: ");
    scanf("%d", &index);

    struct node *c = head;
    while (c != NULL)
    {
        ++ctr;
        c = c->next;
    }
    // printf("\nNo of element in the linked list is : %d\n", ctr);

    if (index == 1)
    {
        insertAtBegin();
        return;
    }
    else if (index == (ctr + 1))
    {
        insertAtEnd();
        return;
    }
    else if (index > ctr)
    {
        printf("\nEnter a valid index value since you have only %d no of elements in the linked list\n", ctr);
        return;
    }
    else
    {
        printf("\nEnter the value you want to enter in the position %d: ", index);
        scanf("%d", &val);

        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->next = NULL;
        ptr->prev = NULL;
        struct node *temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        ptr->next->prev = ptr;
    }
}

void deleteAtBegin()
{
    struct node *c = head;
    if (head == NULL)
    {
        printf("\nThere is no node in the linked list\n");
        return;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        free(c);
        // printf("Node is deleted!!!\n");
    }
}

void deleteAtEnd()
{
    struct node *c;
    if (head == NULL)
    {
        printf("The linked list is empty!!!!\n");
    }
    else
    {
        c = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(c);
        // printf("Node is deleted!!!\n");
    }
}

void deleteByIndex()
{
    int index, ctr = 0;
    printf("\nEnter the index value where you want to delete: ");
    scanf("%d", &index);

    struct node *c = head;
    while (c != NULL)
    {
        ++ctr;
        c = c->next;
    }

    if (index == 1)
    {
        deleteAtBegin();
    }
    else if (index == ctr)
    {
        deleteAtEnd();
    }
    else if (index > ctr)
    {
        printf("Can't delete the given node!!!\n");
        printf("There are only %d no of nodes in the linked list\n", ctr);
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
        q->next->prev = p;
        free(q);
    }
}

void searchByValue()
{
    int val, ctr = 0, flag = 0;

    struct node *p = head;
    if (head == NULL)
    {
        printf("There isn't any element in the linked list\n");
    }
    else
    {
        printf("\nEnter the value you want to found: ");
        scanf("%d", &val);

        while (p != NULL)
        {
            ++ctr;
            if (p->data == val)
            {
                printf("\n***The number %d is found at the index %d***\n", val, ctr);
                return;
            }
            p = p->next;
        }
        printf("The number you entered is not found!!!\n");
    }
}

int main()
{
    // Creating the linked list menu
    int ch;

    while (1)
    {
        printf("========================================================\n");
        printf("\n\n*********Main Menu for doubly linked list*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("========================================================\n");
        printf("0. Create a node in the doubly linked list\n");
        printf("1. Insert a node at the begining of the doubly linked list\n");
        printf("2. Insert a node at any given index of the doubly linked list\n");
        printf("3. Insert a node at the end of the circuladoubly list\n");

        printf("4. Delete a node at the begining of the doubly linked list\n");
        printf("5. Delete a node at any given index of the doubly linked list\n");
        printf("6. Delete a node at the end of the doubly linked list\n");

        printf("7. Traverse the doubly linked list\n");
        printf("8. Search any element by value in the doubly linked list\n");
        printf("9. Quit the menu\n");
        printf("========================================================\n");

        printf("Enter your prefered choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            createNode();
            printf("The node is created!!!\n");
            sleep(1);
            break;
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
    // createNode();
        // traverse();
        // insertAtBegin();
        // traverse();
        // // getch();
        // insertAtEnd();
        // traverse();
        // insertByIndex();
        // traverse();
        // deleteAtBegin();
        // traverse();
        // deleteAtEnd();
        // traverse();
        // deleteByIndex();
        // traverse();
        // searchByValue();
        // traverse();

    return 0;
}