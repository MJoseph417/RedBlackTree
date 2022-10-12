#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum colors{BLACK, RED};

typedef struct tree {
    int key;
    int color; // 0 is black, 1 is red

    struct tree *left, *right, *parent;
} Tree;

void insert(Tree **root, int key);
void insertFixUp(Tree **root, Tree *z);
void leftRotate(Tree **root, Tree *x);
void rightRotate(Tree **root, Tree *x);
Tree *createNode(int key);

void runProgram(char **numbers, int size);
void inOrderTraversal(Tree *t);
int findHeight(Tree *t);
int findBlackHeight(Tree *t);
int findSecondLargest(Tree *t);
Tree *findFarRight(Tree *t);