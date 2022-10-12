#include "redBlackTree.h"

void insert(Tree **root, int key)
{
    Tree *z = createNode(key);
    Tree *x = *root;
    Tree *y = NULL;

    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NULL)
    {
        z->color = BLACK;
        *root = z;
    }
    else
    {
        if(z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }

    insertFixUp(root, z);
}

void insertFixUp(Tree **root, Tree *z)
{
    while(z != *root && z->parent->color == RED)
    {
        Tree *y = NULL;
        if(z->parent == z->parent->parent->left) // if the parent is a left child
        {
            y = z->parent->parent->right; // y = uncle of z

            if(y != NULL && y->color == RED) // if uncle is red
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else 
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(root, z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        }
        else
        {
            if(z->parent == z->parent->parent->right)
            {
                y = z->parent->parent->left; // y = uncle of z

                    if(y != NULL && y->color == RED) // if uncle is red
                    {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    }
                    else 
                    {
                        if(z == z->parent->left)
                        {
                            z = z->parent;
                            rightRotate(root, z);
                        }

                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(root, z->parent->parent);
                    }
            }
        }
    }

    if((*root)->color == RED)
    {
        (*root)->color = BLACK;
    }
}

void leftRotate(Tree **root, Tree *x)
{
    Tree *y;
    y = x->right;
    x->right = y->left;
    if(y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL)
    {
        *root = y;
    }
    else
    {
        if(x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(Tree **root, Tree *x)
{
    Tree *y;
    y = x->left;
    x->left = y->right;
    if(y->right != NULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL)
    {
        *root = y;
    }
    else
    {
        if(x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
    }

    y->right = x;
    x->parent = y;
}

Tree *createNode(int key)
{
    Tree *t;
    t = malloc(sizeof(Tree));
    if(t)
    {
        t->key = key;
        t->color = RED;
        t->left = NULL;
        t->right = NULL;
        t->parent = NULL;
    }

    return t;
}