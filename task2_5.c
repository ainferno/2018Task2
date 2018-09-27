#include <stdio.h>
#include <stdlib.h>

typedef struct Node *list;

typedef struct Node
{
    char *elem;
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

void rem(list *a)
{
    if(*a == NULL)
        return;
    list c = *a;
    *a = (*a)->next;
    free(c);
}

list last(list a)
{
    if(a == NULL)
        return NULL;
    if(a->next == NULL)
        return a;
    return last(a->next);
}

void show(list a)
{
    if(a == NULL)
    {
//        printf("FIN\n");
        return;
    }
//    printf("%s ",a->elem);
    printf("%s%c",a->elem, a->next!=NULL ? ' ' : '\n');
    show(a->next);
}

int cmp_str(char *a, char *b)
{
    for(; (*a) == (*b); a++, b++)
    {
//        printf("a[i] = %c, b[i] = %c\n",(*a),(*b));
        if((*a) == '\0')
        {
//            printf("YES");
            return 1;
        }
    }
    return 0;
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
//        printf("POINT %d\n", i);
        if(i == N)
        {
            N*=2;
            str = (char*)realloc(str, N*sizeof(char));
        }
        if(c == ' ' || c == '\n' || c == '\t')
        {
            str[i] = '\0';
            add(&a, str);
            str = (char*)malloc(N*sizeof(char));
            i = -1;
        }
        str[i] = c;
    }
    return a;
}

void clean_list(list *a, list b)
{
    if(*a == NULL || (*a)->next == NULL)
        return;
    if(cmp_str((*a)->elem, b->elem))
    {
        rem(a);
        clean_list(a, b);
        return;
    }
    clean_list(&(*a)->next, b);
}

int main()
{
    list a = NULL, b = NULL;
    a = input();
    clean_list(&a, last(a));
    show(a);
//    printf("%d\n", cmp_str("a","a"));
    return 0;
}
