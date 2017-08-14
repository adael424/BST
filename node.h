#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include <stdlib.h>


// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;


};
int max(int a, int b);

int height(struct node *N);

struct node *newNode(int key);


struct node *rightRotate(struct node *y);

struct node *leftRotate(struct node *x);

int getBalance(struct node *N);

struct node* insert(struct node* node, int key);

void preOrder(struct node *root);


#endif // AVL_H
