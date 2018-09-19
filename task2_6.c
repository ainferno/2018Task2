#include <stdio.h>
#include <stdlib.h>

typedef struct Node *tree;
typedef int elemtype;

typedef struct Node
{
    elemtype elem;
    tree left,right;
} node;
typedef tree Node;

void add(elemtype *a)
{
    if(!a)
    {
        *a = (tree)malloc(node);
        (*a)->elem = a;
        return;
    }
    ((*a)->elem < a) ? add((*a)->left) : add((*a)->right)
}

int main()
{
    
    
    return 0;
}
