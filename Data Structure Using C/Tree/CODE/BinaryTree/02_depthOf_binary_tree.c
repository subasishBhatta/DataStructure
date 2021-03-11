#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
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

int findHeight(struct node *temp)
{
    //Check whether tree is empty
    if (temp == NULL)
    {
        printf("Tree is empty\n");
        return 0;
    }
    else
    {
        int leftHeight = 0, rightHeight = 0;

        //Calculate the height of left subtree
        if (temp->left != NULL)
            leftHeight = findHeight(temp->left);

        //Calculate the height of right subtree
        if (temp->right != NULL)
            rightHeight = findHeight(temp->right);

        //Compare height of left subtree and right subtree
        //and store maximum of two in variable max
        int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;

        //Calculate the total height of tree by adding height of root
        return (max + 1);
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

    printf("The height of the tree is %d\n.", findHeight(root));
    return 0;
}