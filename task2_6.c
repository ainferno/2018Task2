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

void add(tree *a, elemtype b)//Добавляем элемент в дерево
{
    if(*a == NULL)
    {
        *a = (tree)malloc(sizeof(node));
        (*a)->elem = b;
        (*a)->left = NULL;
        (*a)->right = NULL;
        return;
    }
    ((*a)->elem > b) ? add(&(*a)->left, b) : add(&(*a)->right, b);
}

void add_t_r(tree *a, tree b)//Получает на вход 2 дерева, добавляет второе к самой правому элементу справа(используем для удаления элемента)
{
    if(*a == NULL)
    {
        *a = b;
        return;
    }
    add_t_r(&(*a)->right, b);
}

void remove_t(tree *a, elemtype b)//Удаляет элемент, если он есть, ставит на его место его левое подерево, а его правое поддерево прикрепляет к его левому поддереву справа
{
    if(*a == NULL)
        return;
    if((*a)->elem == b)
    {
        tree c = *a;
        add_t_r(&(*a)->left, (*a)->right);//Это возможно потому что все элементы правого дерева больше элементов левого
        *a = (*a)->left;
        free(c);
        return;
    }
    (*a)->elem > b ? remove_t(&(*a)->left, b) : remove_t(&(*a)->right, b);
}

int search(tree a, int b)//Поиск в бинарном дереве
{
    if(a == NULL)
        return 0;
    if(a->elem == b)
        return 1;
    return (a->elem > b) ? search(a->left, b) : search(a->right, b);
}

void show(tree a)//Вывод дерева(в случае с бинарным деревом поиска выведем осортированно)
{
    if(a == NULL)
        return;
    show(a->left);
    printf("%d ", a->elem);
    show(a->right);
}

void input()//Основная функция считывающая из входного потока
{
    tree a = NULL;
    char c;
    int x = 0;
    while(scanf("%c%d", &c, &x) == 2)
    {

        //printf("C = %c, X = %d\n", c, x);
        switch(c)
        {
            case '+':
                add(&a, x); 
                break;
            case '-':
                remove_t(&a, x);
                 break;
            case '?': 
                printf("%d %s\n", x, (search(a,x)) ? "yes" : "no");
                break;
            default:
                printf("ERROR\n");
                return;
        }
        scanf("%c", &c);
    }
}

int main()
{
    input();
    return 0;
}
