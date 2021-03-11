#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *temp = NULL;

void insert();
void search(struct node *);
void inOrder(struct node *);

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();

    inOrder(root);
    
    return 0;
}

void insert()
{
    int val;
    printf("Enter the data you want to insert: ");
    scanf("%d", &val);

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        search(root);
    }
    
}

void search(struct node *ptr)
{
    if (temp->data > ptr->data && ptr->right == NULL)
    {
        ptr->right = temp;
        return;
    }
    else if (temp->data > ptr->data && ptr->right != NULL)
    {
        search(ptr->right);
        return;
    }
    else if (temp->data < ptr->data && ptr->left == NULL)
    {
        ptr->left = temp;
        return;
    }
    else if (temp->data < ptr->data && ptr->left != NULL)
    {
        search(ptr->left);
        return;
    }
    
}

void inOrder(struct node *p)
{
    if (p == NULL)
    {
        printf("The BST is Empty!!!\n");
        return;
    }
    if (p->left != NULL)
    {
        inOrder(p->left);
    }
    printf("%d ->", p->data);
    if (p->right != NULL)
    {
        inOrder(p->right);
    }
    
}