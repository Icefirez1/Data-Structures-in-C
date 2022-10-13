#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int key; 
    struct node *left; 
    struct node *right;
}Node; 

typedef Node* NodePtr; 

void print_bst(NodePtr tree);
void print_bst_in_order (NodePtr tree);
void insert_bst(int value, NodePtr *treePtr);
void destroy_bst(NodePtr *treePtr);
void delete_bst(int value, NodePtr *treePtr);
NodePtr * successor_bst(NodePtr tree);

int main_bst(int argc, char argv[])
{
    NodePtr tree = NULL;
    insert_bst(50, &tree);
    insert_bst(100, &tree);
    insert_bst(0, &tree);
    insert_bst(50, &tree);
    insert_bst(1, &tree);
    // print_bst_in_order(tree);
    print_bst(tree);
    return 0;
}

void print_bst(NodePtr tree)
{
    static size_t depth = 0;
    if(tree == NULL)
    {return;}
    ++depth;
    print_bst(tree->right);
    --depth;
    for (size_t i = 0; i < depth; ++i)
    {printf("");}
    printf("%d\n", tree->key);
    ++depth;
    print_bst(tree->left);
    --depth;
}

void destroy_bst(NodePtr *treePtr)
{
    NodePtr tree = *treePtr; 
    if(tree == NULL)
    {return;}
    destroy_bst(&tree->left);
    destroy_bst(&tree->left);
    free(tree);
    *treePtr = NULL;
}

void print_bst_in_order(NodePtr tree)
{
    static size_t depth = 0;
    if(tree == NULL)
    {return;}
    ++depth;
    print_bst_in_order(tree->left);
    --depth;
    printf("%d,", tree->key);
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

void delete_bst(int value, NodePtr *treePtr)
{
    NodePtr tree = *treePtr;
    if(tree == NULL)
        {return;}
    if(value < tree->key)
        {delete_bst(value, &(tree->left));}
    else if(value > tree->key)
        {delete_bst(value, &(tree->right));}
    else
    {
        NodePtr child = tree->right ? tree->right :tree->left;
        if(tree->left && tree->right)
        {
            // we fucked fr
            //child = succesor();
        }
    }


}


NodePtr * successor_bst(NodePtr tree)
{
    tree = tree->right; 
    while(tree->left != NULL)
        {tree = tree->left;}
    return tree; 
}