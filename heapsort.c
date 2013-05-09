#include <stdio.h>

void swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

void max_heap_adj(char list[], int length, int i)
{
    char root;
    int flag = 1;
    int left = 2*i; //左孩子结点
    root = list[i]; //暂存根记录

    while((left <= length) && (flag == 1))
    {

        if(((left + 1) <= length) && (list[left] < list[left+1]))
            left++; //若存在右子树，且右子树根的关键字大，则沿右分支"筛选"

        if(root >= list[left])
            flag = 0; //筛选完毕
        else
        {
            printf("i : %d, %d, left : %d, %d\n", i, list[i], left, list[left]);
            list[i] = list[left];
            i = left;
            left = 2*i;
        } //继续筛选
    }

    list[i] = root; //将list[i]填入恰当的位置

    return;
}

void max_heap_create(char list[], int n)
{
    int i = 0;

    for(i = n/2; i > 0; i--)
    {
        printf("index : %d, %d\n", i, list[i]);
        max_heap_adj(list, n, i);
    }

    return;
}

void max_heap_print(char list[], int n)
{
    int i = 0;
    printf("\n===========================\n");
    for (; i < n; i++)
        printf("%d ", list[i]);

    printf("\n===========================\n");
    return;
}

void max_heap_sort(char list[], int n)
{
    int i = 0;

    for(i = n-1; i > 0; i--)
    {
        printf("sort : %d, %d\n", list[i], list[1]);
        swap(&list[i], &list[1]);
        max_heap_adj(list, i-1, 1);
        max_heap_print(list, n);
    }

    return;
}


int main(void)
{
    char list[] = {0, 9, 12, 19, 89, 11, 21, 1};

    int n = sizeof(list);

    printf("list length : %d\n", sizeof(list));

    max_heap_create(list, n);

    max_heap_print(list, n);

    max_heap_sort(list, n);

    max_heap_print(list, n);

    return 0;
}
