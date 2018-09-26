#include <stdio.h>
#include <stdlib.h>

typedef struct Node *list;

typedef struct Node
{
    char* elem;
    list next;
} node;
typedef list Node;

int cmp_str(char*,char*);

void add(list *a, char *b)
{
    if(*a == NULL)
    {
        *a = (list)malloc(sizeof(node));
        (*a)->elem = b;
        (*a)->next = NULL;
        return;
    }
    add(&(*a)->next, b);
}

void rem_first_srch(list *a, char *b)
{
    if(*a == NULL)
        return;
    if((*a)->next == NULL)
    {
        if(cmp_str((*a)->elem, b))
        {
            free((*a)->elem);
            free(*a);
            a = NULL;
        }
        return;
    }
    if(cmp_str((*a)->next->elem, b))
    {
        list c = (*a)->next->next;
        free((*a)->next->elem);
        free((*a)->next);
        (*a)->next = c;
        return;
    }
    rem_first_srch(&(*a)->next, b);
}

void show(list a)
{
    if(a == NULL)
        return;
    printf("%s%c",a->elem, a->next!=NULL ? ' ' : '\n');
    show(a->next);
}

list input()
{
    list a = NULL;
    char *str = NULL;
    char c;
    int N = 10, i = 0;
    str = (char*)malloc(N*sizeof(char));

    for(;scanf("%c",&c)==1;i++)
    {
        if(i == N)
        {
            N*=2;
            str = (char*)realloc(str, N*sizeof(char));
        }
        if(c == ' ' || c == '\n')
        {
            add(&a, str);
            str = (char*)malloc(N*sizeof(char));
            i = 0;
        }
        str[i] = c;
    }
    return a;
}

int cmp_str(char *a, char *b)
{
    for(; (*a) == (*b); a++, b++)
        if((*a) == '\n')
            return 1;
    return 0;
}

int main()
{
    list a = NULL;
    a = input();
    show(a);
    rem_first_srch(&a, "abc");
    show(a);
    //printf("%d\n", cmp_str("a","a"));
    return 0;
}
