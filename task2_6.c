#include <stdio.h>
#include <stdlib.h>

typedef struct Node *tree;
typedef int elemtype;

typedef struct Node// Предположим что нам не надо балансировать дерево поиска.
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

void show(tree a)
{
    if(a == NULL)
        return 0;
    show(a->left);
    printf("%d ", a->elem);
    show(a->right);
}

int main()
{
    tree a = NULL;
    add(&a,3);
    add(&a,1);
    add(&a,2);
    add(&a,5);
    show(a);
    return 0;
}
