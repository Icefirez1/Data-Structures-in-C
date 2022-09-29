#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int key; 
    struct node *left; 
    struct node *right;
}Node; 

typedef Node *NodePtr; 

void print_bst(NodePtr tree);
void print_bst_in_order (NodePtr tree);
void insert_bst(int value, NodePtr *treePtr);

int main_bst(int argc, char argv[])
{
    NodePtr tree = NULL;
    return 0;
}

void print_bst(NodePtr tree)
{

}

void print_bst_in_order(NodePtr tree)
{
    static size_t depth = 0;
    if(tree == NULL)
    {return;}
    ++depth;
    print_bst_in_order(tree->left);
    --depth;
    printf("&d,", tree->key);
    ++depth;
    print_bst_in_order(tree->right);
    --depth;
    if(depth==0)
    {puts("");}
}

void insert_bst(int value, NodePtr *treePtr)
{
    NodePtr tree = *treePtr;
    if(tree == NULL)
    {
        NodePtr tree = malloc(sizeof(Node));
        tree->key = value;
        tree->left = tree->right = NULL; 
        *treePtr = tree;
    }
    else if(value < tree->key)
    {insert_bst(value, &(tree->left));}
    else
    {insert_bst(value, &(tree->right));}
}