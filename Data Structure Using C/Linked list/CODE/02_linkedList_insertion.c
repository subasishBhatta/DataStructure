#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    int ctr = 0;
    printf("The elements in the linked list are: \n");
    while (ptr != NULL)
    {
        ++ctr;
        printf("%d) %d\n", ctr, ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insert a node in the beginning of the linked list
struct node *insertAtBegin(struct node *head, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = head;

    return ptr;
}

// Insert a node at a given index of the linked list
struct node *insertInBetween(struct node *head, int value, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;

    struct node *p = head;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Insert a node at the end of the linked list
void insertAtEnd(struct node *head, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
}

// Insert a node after a given a node in the linked list
void insertAfterNode(struct node *prevNode, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    printf("\n");
    linkedListTraversal(head);

    // head = insertAtBegin(head, 88);
    // head = insertInBetween(head, 88, 3);
    // insertAtEnd(head, 88)
    insertAfterNode(second, 88);
    printf("\n");
    linkedListTraversal(head);

    return 0;
}