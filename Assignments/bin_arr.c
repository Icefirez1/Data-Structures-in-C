#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/////////////////////////////////////////////////
size_t INITIAL_CAPACITY = 8;
typedef struct node
{
    int key; 
    bool exist;

}Node;

typedef struct array_list_bst
{
    Node *array;
    size_t capacity;

} ArrBst;





/////////////////////////////


ArrBst* initialize_ab();
void print_in_level_order(ArrBst list);
void resize(ArrBst *listPtr);
void insert(int value, ArrBst *listPtr);
void print_in_order(ArrBst list);
size_t left_child(size_t parent);
size_t right_child(size_t parent);
size_t parent(size_t child);
void delete(size_t value, ArrBst *listPtr);
size_t predecessor(size_t index, ArrBst *listPtr);
size_t successor(size_t index, ArrBst *listPtr);

//merging 
ArrBst *merge_arr(ArrBst *listPtr1, ArrBst *listPtr2);
size_t node_amount(ArrBst list);
Node * flatten_bst(ArrBst list, size_t length);
Node *merge_lists(Node *listA, Node *listB, size_t sizeA, size_t sizeB);
ArrBst *list_to_bst(Node *list, size_t size);


//////////////////////

int main(int argc, char *argv[])
{
    //Initalize
    ArrBst * listPtr = initialize_ab();

    //print without stuff
    print_in_level_order(*listPtr);
    print_in_order(*listPtr);

    //Inserting
    insert(8, listPtr);
    insert(10, listPtr);
    insert(3, listPtr);
    insert(1, listPtr);
    insert(6, listPtr);
    insert(14, listPtr);
    insert(4, listPtr);
    insert(7, listPtr);
    insert(13, listPtr);

    // insert(8, listPtr);
    // insert(10, listPtr);
    // insert(3, listPtr);
    // insert(1, listPtr);
    // insert(6, listPtr);
    // insert(15, listPtr);
    // insert(4, listPtr);
    // insert(7, listPtr);
    // insert(13, listPtr);
    // insert(14, listPtr);

    //printing in order and in level order
    print_in_level_order(*listPtr);
    print_in_order(*listPtr);

    //delete

    //two children
    // delete(8, listPtr);
    // print_in_level_order(*listPtr);

    //one child 
    // delete(10, listPtr);
    // print_in_level_order(*listPtr);
    // print_in_order(*listPtr);

    // //no children
    // delete(13, listPtr);
    // print_in_level_order(*listPtr);
    // insert(13, listPtr);



    // combining
    ArrBst * listPtr1 = initialize_ab();
    insert(8, listPtr1);
    insert(10, listPtr1);
    insert(3, listPtr1);
    insert(1, listPtr1);
    insert(6, listPtr1);
    insert(14, listPtr1);
    insert(4, listPtr1);
    insert(7, listPtr1);
    insert(13, listPtr1);
    print_in_order(*listPtr1);


    ArrBst * comb = merge_arr(listPtr1, listPtr);
    print_in_order(*comb);

    
    return 0;
}


void print_in_level_order(ArrBst list)
{
    size_t i = 0, last_print = 0;
    for (; i < list.capacity;)
    {
        if(list.array[i].exist)
            {printf("%d,", list.array[i]);}
        else
            {printf("NULL,");}
        ++i;
        if (i == (last_print * 2 + 1))
        {
            last_print = i;
            puts("");
        }
    }
    puts("");
}   

void print_in_order(ArrBst list)
{
    static size_t index = 0;

    if(index > list.capacity || !list.array[index].exist)
        {return;}
    index = left_child(index);
    print_in_order(list);
    index = parent(index);

    printf("%d,", list.array[index].key);

    index = right_child(index);
    print_in_order(list);
    index = parent(index);

    if(index == 0)
        {puts("");}

}


void destroy(ArrBst *list)
{
    free(list->array);
    free(list);
}

size_t left_child(size_t parent)
{
    return 2* parent + 1;
}

size_t right_child(size_t parent)
{
    return 2* parent + 2;
}

size_t parent(size_t child)
{
    return (child-1)/2; 
}

void resize(ArrBst *listPtr)
{
    listPtr->array = realloc(listPtr->array, sizeof(Node) * (listPtr->capacity * 2 + 1));
    memset(listPtr->array + listPtr->capacity, 0, sizeof(Node) * ((listPtr->capacity *2 + 1) - listPtr->capacity));
    listPtr->capacity = (listPtr->capacity * 2) + 1;
}

ArrBst* initialize_ab()
{
    ArrBst *arrPtr = malloc(sizeof(ArrBst));
    arrPtr->capacity = 1;
    arrPtr->array = calloc(arrPtr->capacity, sizeof(Node));
    return arrPtr;
}

void insert(int value, ArrBst *listPtr)
{
    static size_t index = 0;
    if(!((listPtr->array)+index)->exist)
    {
        ((listPtr->array)+index)->key = value;
        ((listPtr->array)+index)->exist = true;
        index = 0;
    }
    else if(value > ((listPtr->array)+index)->key)
    {
        size_t right_child_index = right_child(index);
        index = right_child_index;
        if(right_child_index >= listPtr-> capacity)
            {resize(listPtr);}
        insert(value, listPtr);
    }
    else
    {
        size_t left_child_index = left_child(index);
        index = left_child_index; 
        if(left_child_index >= listPtr-> capacity)
            {resize(listPtr);}
        insert(value, listPtr);
    }
}

void delete(size_t value, ArrBst *listPtr)
{
    // traveses 
    static size_t index = 0;
    if(index >= listPtr->capacity)
    {
        return;
    }
    if(((listPtr->array)+index)->key == value && ((listPtr->array)+index)->exist)
    {
        //this is where i do stuff i think
        
        //no children
        if(right_child(index) > listPtr->capacity && left_child(index) > listPtr-> capacity)
        {
            ((listPtr->array)+index)->exist = false;
            ((listPtr->array)+index)->key = 0;
            index = 0;
        }
        else if(!(((listPtr->array)+right_child(index))->exist) && !(((listPtr->array)+left_child(index))->exist))
        {
            ((listPtr->array)+index)->exist = false;
            ((listPtr->array)+index)->key = 0;
            index = 0;
        }
        // one child 
        else if((((listPtr->array)+right_child(index))->exist))
        {
            size_t successor_index = successor(right_child(index), listPtr);
            listPtr->array[index].key = listPtr->array[successor_index].key;
            index = right_child(index);
            delete(listPtr->array[successor_index].key, listPtr);
        }
        else if((((listPtr->array)+left_child(index))->exist))
        {
            size_t successor_index = predecessor(left_child(index), listPtr);
            listPtr->array[index].key = listPtr->array[successor_index].key;
            index = left_child(index);
            delete(listPtr->array[successor_index].key, listPtr);
        }
        //two children
        else if((((listPtr->array)+right_child(index))->exist) && (((listPtr->array)+left_child(index))->exist))
        {
            //predecessor
            size_t pindex = predecessor(left_child(index), listPtr);
            ((listPtr->array)+index)->key = ((listPtr->array)+pindex)->key;
            index = pindex;
            delete(((listPtr->array)+pindex)->key, listPtr);
        }
        return;
    }
    else if(value > ((listPtr->array)+index)->key)
    {
        size_t right_child_index = right_child(index);
        index = right_child_index;
        delete(value, listPtr);
    }
    else
    {
        size_t left_child_index = left_child(index);
        index = left_child_index; 
        delete(value, listPtr);
    }
    return;
    

}

size_t predecessor(size_t index, ArrBst *listPtr)
{
    if(!((listPtr->array)+right_child(index))->exist)
    {
        return index;
    }
    else
    {
        predecessor(right_child(index), listPtr);
    }

}


size_t successor(size_t index, ArrBst *listPtr)
{
    if(!((listPtr->array)+left_child(index))->exist)
    {
        return index;
    }
    else
    {
        successor(left_child(index), listPtr);
    }

}



// merge cuz it gets it own little section


ArrBst *merge_arr(ArrBst *listPtr1, ArrBst *listPtr2)
{
    size_t length1 = node_amount(*listPtr1);
    size_t length2 = node_amount(*listPtr2);
    Node *list1 = flatten_bst(*listPtr1, length1);
    Node *list2 = flatten_bst(*listPtr2, length2);
    Node *mergin = calloc(length1 + length2, sizeof(Node));
    Node *merged = merge_lists(list1, list2, length1, length1);
    ArrBst *bst_merged = list_to_bst(merged, length1 + length2);
    return bst_merged;
}

size_t node_amount(ArrBst list)
{
    size_t amount = 0;
    for (size_t i = 0; i < list.capacity; i++)
    {
        if(list.array[i].exist)
            {++amount;}
    }
    return amount;
}

Node * flatten_bst(ArrBst list, size_t length)
{
    static size_t index = 0;
    static Node * out = NULL;
    static size_t place = 0;

    if(index > list.capacity || !list.array[index].exist)
        {return NULL;}
    if(out == NULL)
        {out = calloc(length, sizeof(Node));}
    index = left_child(index);
    flatten_bst(list, length);
    index = parent(index);

    out[place] = list.array[index];
    ++place;

    index = right_child(index);
    flatten_bst(list, length);
    index = parent(index);

    if(index == 0)
        {
            Node* tmpout = out; 
            out = NULL;
            place = 0; 
            index = 0;
            return tmpout;}
}

Node * merge_lists(Node * listA, Node *listB, size_t sizeA , size_t sizeB)
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

ArrBst *list_to_bst(Node *list, size_t size)
{
    static ArrBst *new = NULL;
    if (new == NULL)
        {new = initialize_ab();}
    if (size == 0)
        {return NULL;}

    insert(list[size / 2].key, new);
    list_to_bst(list, size / 2);
    list_to_bst(list + size / 2 + 1, size / 2 + (size % 2 - 1));


    return new;
}



