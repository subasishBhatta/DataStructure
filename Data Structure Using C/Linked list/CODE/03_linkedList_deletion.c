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

// Delete the begging node of the linked list
struct node* deleteAtBegin(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);

    return head;
}

// Delete a node by the index value in the linked list
struct node* deleteInBetween(struct node *head, int index)
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

    return head;
}

// Delete the last node of the linked list
struct node* deleteAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);

    return head;
}

// Delete a node by searching a given value from the linked list
struct node* deleteByValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if (q->next != NULL)
    {
        p->next = q->next;
        free(q);        
    }
    else
    {
        printf("The given value is not found in the linked list\n");
    }
    
    return head;
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

    // Before
    printf("\n");
    linkedListTraversal(head);

    // head = deleteAtBegin(head);
    // head = deleteInBetween(head, 2);
    // head = deleteAtEnd(head);
    head = deleteByValue(head, 33);
    // After
    printf("\n");
    linkedListTraversal(head);

    return 0;
}