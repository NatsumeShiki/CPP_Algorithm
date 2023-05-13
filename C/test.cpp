#include <stdio.h>
#include <malloc.h>

#define INF     32767               //定义∞
#define MAXV    100                 //最大顶点个数

// typedef char InfoType;
// /*-------------------------以下定义邻接矩阵类型---------------------------*/
// typedef struct
// {
//     int no;                         //顶点编号
//     InfoType info;                  //顶点信息
// }VertexType;                        //顶点类型

// typedef struct
// {
//     int edges[MAXV][MAXV];          //邻接矩阵数组(用一个二维数组存放顶点间关系(边或弧)的数据)
//     int n;                          //顶点数
//     int e;                          //边数
//     VertexType vexs[MAXV];          //存放顶点信息(用一个一维数组存放图中所有顶点数据)
// }MatGraph;                          //完整的图邻接矩阵类型

//邻接表表示法-将每个顶点的邻接点串成一个单链表
/*-----------以下定义邻接表类型--------------*/
typedef struct ArcNode
{
    int adjvex;                     //该边的邻接点编号
    struct ArcNode* nextarc;        //指向下一条边的指针
    int weight;                     //该边的相关信息,如权值(用整型表示)
}ArcNode;                           //边结点类型

typedef struct VNode
{
    int info;                  //顶点其他信息
    int cnt;                        //存放顶点入度,仅用于拓扑排序
    ArcNode* firstarc;              //指向第一条边
}VNode;                             //邻接表结点类型

typedef struct
{
    VNode adjlist[MAXV];            //邻接表头结点数组
    int n;                          //图中顶点数
    int e;                          //图中边数
}AdjGraph;                          //完整的图邻接表类型

/*-------------------------邻接矩阵的基本运算算法---------------------------*/
/*------------由边数组A、顶点数n和边数e创建图的邻接矩阵g--------------------*/
// void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
// {
//     int i, j;

//     g.n = n;
//     g.e = e;
//     for (i = 0; i < g.n; i++)
//         for (j = 0; j < g.n; j++)
//             g.edges[i][j] = A[i][j];
// }

/*------------输出邻接矩阵g--------------------*/
// void DispMat(MatGraph g)
// {
//     int i, j;

//     for (i = 0; i < g.n; i++)
//     {
//         for (j = 0; j < g.n; j++)
//         {
//             if (g.edges[i][j] != INF)
//                 printf("%4d", g.edges[i][j]);
//             else
//                 printf("%4s", "∞");
//         }
//         printf("\n");
//     }
// }

/*-------------------------邻接表的基本运算算法---------------------------*/
/*-------------------由边数组A、顶点数n和边数e创建图的邻接表G--------------------*/
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;

    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)                              //给邻接表中所有头结点的指针域置初值NULL
    {
        G->adjlist[i].firstarc = NULL;
    }

    for (i = 0; i < n; i++)                              //检查邻接矩阵中的每个元素
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (A[i][j] != 0 && A[i][j] != INF)          //存在一条边
            {
                p = (ArcNode*)malloc(sizeof(ArcNode)); //创建一个结点p
                p->adjvex = j;                          //邻接点编号
                p->weight = A[i][j];                    //边的权重
                p->nextarc = G->adjlist[i].firstarc;    //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

/*-------------------输出邻接表G--------------------*/
void DispAdj(AdjGraph* G)
{
    ArcNode* p;

    for (int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d]->", p->adjvex, p->weight);  //邻接点编号[权重]
            p = p->nextarc;
        }
        printf("\n");
    }
}

/*-------------------销毁图的邻接表G--------------------*/
void DestroyAdj(AdjGraph*& G)
{
    ArcNode* pre, * p;

    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;                   //pre指向第i个单链表的首结点
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL)                            //释放第i个单链表的所有边结点
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);                                            //释放头结点数组
}

#define MAX_SIZE    100

int visited[MAXV] = { 0 };                             //全局数组

/*--------------求图G从顶点v出发的深度优先生成树----------------*/
void DFSTree(AdjGraph* G, int v)
{
    ArcNode* p;

    visited[v] = 1;                                         //置已访问标记
    p = G->adjlist[v].firstarc;                             //p指向顶点v的第一个相邻点
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)                         //若p->adjvex顶点未访问,递归访问它
        {
            printf("(%d,%d) ", v, p->adjvex);
            DFSTree(G, p->adjvex);
        }
        p = p->nextarc;                                     //p指向顶点v的下一个相邻点
    }
}

/*--------------求图G从顶点v出发的广度优先生成树----------------*/
void BFSTree(AdjGraph* G, int v)
{
    int que[MAXV];                                           //定义环形队列
    int que_front = 0, que_rear = 0;
    ArcNode* p;
    int visited[MAXV];                                       //定义顶点访问标志数组
    int i;
    int adjvex;

    for (i = 0; i < G->n; i++)
        visited[i] = 0;                                      //顶点访问标志数组初始化
    visited[v] = 1;                                          //置已访问标记
    que_rear++;                                              //顶点v进队
    que[que_rear] = v;
    while (que_front != que_rear)                             //队不空循环
    {
        que_front = (que_front + 1) % MAXV;
        adjvex = que[que_front];                             //出队一个顶点adjvex
        p = G->adjlist[adjvex].firstarc;                     //p指向adjvex的第一个相邻点
        while (p != NULL)                                     //查找adjvex的所有相邻点
        {
            if (visited[p->adjvex] == 0)                      //若当前邻接点未被访问
            {
                printf("(%d,%d) ", adjvex, p->adjvex);
                visited[p->adjvex] = 1;                      //置已访问标记
                que_rear = (que_rear + 1) % MAXV;
                que[que_rear] = p->adjvex;                   //顶点p->adjvex入队
            }
            p = p->nextarc;                                  //p指向顶点v的下一个邻接点
        }
    }
    printf("\n");
}

int main(void)
{
    AdjGraph* G;
    int n = 11;                                  //图顶点数
    int e = 13;                                  //图边数
    int A[MAXV][MAXV];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 0;

    A[0][1] = 1;
    A[0][2] = 1;
    A[0][3] = 1;

    A[1][0] = 1;
    A[1][4] = 1;
    A[1][5] = 1;

    A[2][0] = 1;
    A[2][3] = 1;
    A[2][5] = 1;
    A[2][6] = 1;

    A[3][0] = 1;
    A[3][2] = 1;
    A[3][7] = 1;

    A[4][1] = 1;

    A[5][1] = 1;
    A[5][2] = 1;

    A[6][2] = 1;
    A[6][7] = 1;
    A[6][8] = 1;
    A[6][9] = 1;

    A[7][3] = 1;
    A[7][6] = 1;
    A[7][10] = 1;

    A[8][6] = 1;
    A[9][6] = 1;
    A[10][7] = 1;

    CreateAdj(G, A, n, e);
    printf("图G的邻接表:\n");
    DispAdj(G);
    int v = 3;
    printf("深度优先生成树:\n");
    DFSTree(G, v);
    printf("\n");
    printf("广度优先生成树:\n");
    BFSTree(G, v);

    printf("销毁图的邻接表\n");
    DestroyAdj(G);

    return 0;
}
