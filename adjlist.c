#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 图的邻接表存储表示 */
#define MAX_VERTEX_NUM 5

#if 0
typedef enum{DG,DN,UDG,UDN}GraphKind; /* {有向图,有向网,无向图,无向网} */

typedef struct ArcNode
{
    int adjvex; /* 该弧所指向的顶点的位置 */
    struct ArcNode *nextarc; /* 指向下一条弧的指针 */
    InfoType *info; /* 网的权值指针） */
}ArcNode; /* 表结点 */

typedef struct
{
    VertexType data; /* 顶点信息 */
    /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM]; /* 头结点 */

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; /* 图的当前顶点数和弧数 */
    GraphKind kind; /* 图的种类标志 */
}ALGraph;
#endif

typedef struct ADJLIST_NODE
{
    unsigned int key;
    struct ADJLIST_NODE *link;
}AdjListNode;

typedef struct ADJLIST
{
    unsigned int key;
    AdjListNode *first;
}AdjList;

AdjList* create_empty_adjlist(AdjList **list, unsigned int size)
{
    AdjList *p = *list;

    p = (AdjList *)malloc(sizeof(AdjList)*size);
    if (NULL == p)
    {
        return NULL;
    }

    memset(p, 0, sizeof(AdjList)*size);

    return p;
}

AdjListNode* create_adjlist_node()
{
    AdjListNode *node = (AdjListNode *)malloc(sizeof(AdjListNode));
    if (NULL == node)
    {
        return NULL;
    }

    memset(node, 0, sizeof(*node));
    return node;
}

int create_adjlist(AdjList *list, unsigned int size)
{
    AdjList *p = list;

    int i = 0;
    for (; i < size; i++)
    {
        p[i].key = i;
    }

    AdjListNode *node = NULL;
    p[0].first = create_adjlist_node();
    node = p[0].first;
    node->key = p[1].key;
    node->link = create_adjlist_node();
    node = node->link;
    node->key = p[2].key;

    p[1].first = create_adjlist_node();
    node = p[1].first;
    node->key = p[3].key;

    p[2].first = create_adjlist_node();
    node = p[2].first;
    node->key = p[3].key;

    p[3].first = create_adjlist_node();
    node = p[3].first;
    node->key = p[4].key;

    return 0;
}

void bfs_adjlist(AdjList *list, unsigned int size)
{
    return;
}

static int token[MAX_VERTEX_NUM];

void dfs_adjlist(AdjList *list, unsigned int v)
{
    AdjListNode *node = list[v].first;
    unsigned int key = v;

    token[key] = 0;
    printf("key : %d\n", key);
    /*printf("key : %d\n", key);*/

    for(; node != NULL; node = node->link)
    {
        key = node->key;
        if(token[key] < 0)
        {
            dfs_adjlist(list, key);
        }
    }

    return;
}

void print_adjlist(AdjList *list, unsigned int size)
{
    int i = 0;
    AdjListNode *node = NULL;

    for(; i < size; i++)
    {
        printf("\nhead node : %d\n", list[i].key);
        node = list[i].first;
        while(NULL != node)
        {
            printf(" -> %d ", node->key);
            node = node->link;
        }
    }

    return;
}

int main(int argc, char *argv[])
{
    AdjList *base = NULL;
    unsigned int size = MAX_VERTEX_NUM;

    if (NULL == (base = create_empty_adjlist(&base, size)))
    {
        return -1;
    }

    memset(token, -1, MAX_VERTEX_NUM);
    create_adjlist(base, size);

    printf("++++++++++++++++++\n");
    print_adjlist(base, size);
    printf("++++++++++++++++++\n");

    printf("\n-------------------\n");
    dfs_adjlist(base, 0);
    printf("\n-------------------\n");

    return 0;
}
