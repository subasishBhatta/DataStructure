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
struct node *t1, *t2;

void insert();
void search(struct node *);
void inOrder(struct node *);

void delete ();
void search1(struct node *, int);
void delete1(struct node *);
int smallest(struct node *);
int largest(struct node *);

int main()
{
    int ch;
    while (1)
    {
        printf("\n==================================================================\n");
        printf("                    Main menu for Circular Queue Operation                  \n");
        printf("==================================================================\n");
        printf("1. Insert in the BST\n");
        printf("2. Display the content in INORDER\n");
        printf("3. Delete\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            delete();
            break;
        case 4:
            printf("Exiting!!!\n");
            exit(0);
        default:
            printf("Enter a valid choice!!!\n");
            break;
        }
    }
    

    return 0;
}

void insert()
{
    int val;
    printf("Enter the value you want to insert in the BST: ");
    scanf("%d", &val);

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }
    else
    {
        search(root);
    }
}

void search(struct node *p)
{
    if ((temp->data > p->data) && (p->right != NULL))
    {
        search(p->right);
        return;
    }
    else if (temp->data > p->data && p->right == NULL)
    {
        p->right = temp;
    }
    else if (temp->data < p->data && p->left == NULL)
    {
        p->left = temp;
        return;
    }
    else if (temp->data < p->data && p->left != NULL)
    {
        search(p->left);
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

void delete ()
{
    int val;
    printf("Entere the value you want to delete in the BST: ");
    scanf("%d", &val);

    if (root == NULL)
    {
        printf("The BST is Empty, There's nothing to delete!!!\n");
        return;
    }

    t1 = root;
    t2 = root;

    search1(root, val);
}

void search1(struct node *p, int val)
{
    if (val > p->data)
    {
        t1 = p;
        search1(p->right, val);
    }
    else if (val < p->data)
    {
        t1 = p;
        search1(p->left, val);
    }
    else if (val == p->data)
    {
        delete1(p);
    }
}

void delete1(struct node *p)
{
    int k;
    // If there is no node i.e. to delete a leaf node
    if (p->left == NULL && p->right == NULL)
    {
        if (t1->left == p)
        {
            t1->left = NULL;
        }
        else if (t1->right == p)
        {
            t1->right = NULL;
        }
        free(p);
        return;
    }
    // If we want to delete a node having only a single child node
    // Let the node having a right child
    else if (p->left == NULL)
    {
        if (p == t1)
        {
            root = p->right;
            t1 = root;
        }
        else if (t1->left == p)
        {
            t1->left = p->right;
        }
        else if (t1->right == p)
        {
            t1->right = p->right;
        }
        free(p);
        return;
    }
    // Let the node is having a left child only
    else if (p->right == NULL)
    {
        if (p == t1)
        {
            root = p->left;
            t1 = root;
        }
        else if (t1->left == p)
        {
            t1->left = p->left;
        }
        else if (t1->right == p)
        {
            t1->right = p->left;
        }
        free(p);
        return;
    }
    // Let the node is having two child node
    else if (p->left != NULL && p->right != NULL)
    {
        t2 = root;
        if (p->right != NULL)
        {
            k = smallest(p->right);
        }
        else if (p->left != NULL)
        {
            k = largest(p->left);
        }
        search1(root, k);
        p->data = k;
    }
    
}

int smallest(struct node *p)
{
    t2 = p;
    if (p->left != NULL)
    {
        t2 = p;
        return smallest(p->left);
    }
    else
        return p->data;
}

int largest(struct node *p)
{
    if (p->right != NULL)
    {
        t2 = p;
        return largest(p->right);
    }
    else
        return p->data;
}
