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
NodePtr * successor_bst(NodePtr * treePtr);

//merging 
size_t size_bst(NodePtr tree);
Node * bst_to_list(NodePtr tree , size_t size);
Node * merge_arr_list(Node * listA, Node *listB, size_t sizeA , size_t sizeB);
NodePtr list_to_bst (Node *list, size_t size);
NodePtr merge_bst(NodePtr treeA, NodePtr treeB);


int main_bst(int argc, char argv[])
{
    NodePtr tree = NULL;
    insert_bst(100, &tree);
    insert_bst(50, &tree);
    insert_bst(25, &tree);
    insert_bst(75, &tree);
    insert_bst(200, &tree);

    NodePtr merged = merge_bst(tree, tree);
    print_bst(merged);

    destroy_bst(&tree);
    destroy_bst(&merged);

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
    {printf(" ");}
    printf("%d\n", tree->key);
    ++depth;
    print_bst(tree->left);
    --depth;
    if(depth == 0)
    {puts("");}
}

void destroy_bst(NodePtr *treePtr)
{
    NodePtr tree = *treePtr; 
    if(tree == NULL)
        {return;}
    destroy_bst(&(tree->left));
    destroy_bst(&(tree->left));
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
        tree = malloc(sizeof(Node));
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
        NodePtr replacement = tree->right ? tree->right :tree->left;
        if(tree->left && tree->right)
        {
            // Get pointer to pointer to successor
            NodePtr *replacementPtr = successor_bst(&(tree->right));
            //Get pointer to successor
            replacement = *replacementPtr;
            //MOve sucessor's child to successor's parent
            *replacementPtr = replacement -> right;
            //Move node for deletions children to successor
            replacement->left = tree->left;
            replacement->right = tree->right;
            // move replacemnts parent point to replacement's right child
        }
        // replace tree\

        free(tree);

        *treePtr = replacement;
    }
}


NodePtr * successor_bst(NodePtr * treePtr)
{
    NodePtr tree = *treePtr;
    if(tree->left)
        {successor_bst(&(tree->left));}
    else
        {return treePtr;}
}

size_t find_depth_bst(NodePtr tree)
{
    static size_t depth = 0;
    static size_t max_depth = 0;

    if (tree == NULL)
        return 0;

    if (depth > max_depth)
        max_depth = depth;

    ++depth;
    find_depth_bst(tree->left);
    --depth;

    ++depth;
    find_depth_bst(tree->right);
    --depth;

    if (depth == 0)
    {
        size_t d = max_depth;
        max_depth = 0;
        return d;
    }
}
void print_bst_vertical(NodePtr tree)
{
    if (tree == NULL)
        return;
    size_t depth = find_depth_bst(tree);
    if (depth == 0)
    {
        printf("%d\n", tree->key);
        return;
    }
    // NodePtr treeList[depth][];
}

//# merge 
// flatten both trees into arrays 
// merge both arrays 
// arrays to binary search tree 
// slay slay slay 

// Kleiner explanation 
// Count nodes -> Flatten trees -> merge lists -> create new tree

size_t size_bst(NodePtr tree)
{
    if(tree == NULL);
    {return 0;}
    return size_bst(tree->left) + 1 + size_bst(tree ->right);
}


Node * bst_to_list(NodePtr tree , size_t size)
{
    static Node *list = NULL;
    if(tree == NULL)
    {return NULL;}
    if(list == NULL)
    {list = calloc(size, sizeof(Node));}
    
    bst_to_list(tree->left, 0);
    *list++ = *tree;
    bst_to_list(tree->right, 0);
    if(size != 0)
    {
        Node *out = list-size;
        list = NULL;
        return out;
    } else return NULL;
    
}
Node * merge_arr_list(Node * listA, Node *listB, size_t sizeA , size_t sizeB)
{
    Node *merged = calloc(sizeA + sizeB, sizeof(Node));
    size_t indexA = 0, indexB = 0;

    while (indexA < sizeA && indexB < sizeB)
    {
        if (listA->key < listB->key)
            merged[(indexA++) + indexB] = *listA++;
        else
            merged[indexA + indexB++] = *listB++;
    }
    for (; indexA < sizeA; indexA++)
        merged[indexA + indexB] = *listA++;
    for (; indexB < sizeB; indexB++)
        merged[indexA + indexB] = *listB++;
    return merged;
}
NodePtr list_to_bst (Node *list, size_t size)
{
    if(size ==0)
        {return NULL;}
    Node * root = malloc(sizeof(Node));
    root->key = list[size/2].key;
    root->left = list_to_bst(list, size/2);
    root->right = list_to_bst(list+size/2 + 1, size/2-(size%2==0));
    return root;
}

NodePtr merge_bst(NodePtr treeA, NodePtr treeB)
{
    size_t sizeA = size_bst(treeA);
    size_t sizeB = size_bst(treeB);
    Node * listA = bst_to_list(treeA, sizeA);
    Node * listB = bst_to_list(treeB, sizeB);
    Node * merged = merge_arr_list(listA, listB, sizeA, sizeB);
    NodePtr tree = list_to_bst(merged, sizeA+sizeB);
    free(listA);
    free(listB);
    free(merged); 
    return tree;
}