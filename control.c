#include "redBlackTree.h"

void runProgram(char **numbers, int size)
{
    Tree *root = NULL;
    int a[size];

    for(int i = 0; i<size; i++)
    {
        // insert(root, atoi(numbers[i]));
        a[i] = atoi(numbers[i]);
    }

    for(int j = 0; j< size; j++)
    {
        insert(&root,a[j]);
    }

    printf("\n\n");
    printf("In-order traversal of the tree:\n");
    inOrderTraversal(root);
    printf("\n\n");
    printf("The height of the red and black tree is %d\n\n", findHeight(root));
    printf("The black height of the red and black tree is %d\n\n", findBlackHeight(root));
    printf("The second largest element of the tree is %d\n", findSecondLargest(root));
}

void inOrderTraversal(Tree *t)
{
    if(t != NULL)
    {
        inOrderTraversal(t->left);
        printf("%d-", t->key);
        if(t->color == BLACK)
        {
            printf("B; ");
        }
        else
        {
            printf("R: ");
        }
        inOrderTraversal(t->right);
    }
}

int findHeight(Tree *t)
{
    if(t == NULL)
    {
        return 0;
    }

    int leftHeight = findHeight(t->left);
    int rightHeight = findHeight(t->right);

    if(leftHeight >= rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

int findBlackHeight(Tree *t)
{
    int blackHeight = 0;

    while(t != NULL)
    {
        if(t->color == BLACK)
        {
            blackHeight++;
        }
        t = t->left;
    }

    return blackHeight;
}

int findSecondLargest(Tree *t)
{
    if(t == NULL)
    {
        return -1;
    }

    t = findFarRight(t);

    if(t->left != NULL)
    {
        t = findFarRight(t->left);
        return t->key;
    }

    return t->parent->key;
}

Tree *findFarRight(Tree *t)
{
    if(t == NULL)
    {
        return NULL;
    }

    while(t->right != NULL)
    {
        t = t->right;
    }

    return t;
}