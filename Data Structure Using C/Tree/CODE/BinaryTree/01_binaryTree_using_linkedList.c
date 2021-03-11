#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create()
{
    int val;
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for the node (Enter -1 to stop): ");
    scanf("%d", &val);

    if (val == -1)
    {
        return NULL;
    }
    else
    {
        ptr->data = val;
        printf("Enter the left child of %d: \n", val);
        ptr->left = create();
        printf("Enter the right child for %d: \n", val);
        ptr->right = create();

        return ptr;
    }
    
}

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
    
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
    
}

int main()
{
    struct node *root = NULL;
    root = create();

    printf("The preorder of the root is : ");
    preOrder(root);
    printf("\n");
    
    printf("The inorder of the root is : ");
    inOrder(root);
    printf("\n");

    printf("The postorder of the root is : ");
    postOrder(root);
    printf("\n");

    return 0;
}