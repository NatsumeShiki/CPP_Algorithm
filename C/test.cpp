#include <stdio.h>
#include <malloc.h>

#define INF     32767               //�����
#define MAXV    100                 //��󶥵����

// typedef char InfoType;
// /*-------------------------���¶����ڽӾ�������---------------------------*/
// typedef struct
// {
//     int no;                         //������
//     InfoType info;                  //������Ϣ
// }VertexType;                        //��������

// typedef struct
// {
//     int edges[MAXV][MAXV];          //�ڽӾ�������(��һ����ά�����Ŷ�����ϵ(�߻�)������)
//     int n;                          //������
//     int e;                          //����
//     VertexType vexs[MAXV];          //��Ŷ�����Ϣ(��һ��һά������ͼ�����ж�������)
// }MatGraph;                          //������ͼ�ڽӾ�������

//�ڽӱ��ʾ��-��ÿ��������ڽӵ㴮��һ��������
/*-----------���¶����ڽӱ�����--------------*/
typedef struct ArcNode
{
    int adjvex;                     //�ñߵ��ڽӵ���
    struct ArcNode* nextarc;        //ָ����һ���ߵ�ָ��
    int weight;                     //�ñߵ������Ϣ,��Ȩֵ(�����ͱ�ʾ)
}ArcNode;                           //�߽������

typedef struct VNode
{
    int info;                  //����������Ϣ
    int cnt;                        //��Ŷ������,��������������
    ArcNode* firstarc;              //ָ���һ����
}VNode;                             //�ڽӱ�������

typedef struct
{
    VNode adjlist[MAXV];            //�ڽӱ�ͷ�������
    int n;                          //ͼ�ж�����
    int e;                          //ͼ�б���
}AdjGraph;                          //������ͼ�ڽӱ�����

/*-------------------------�ڽӾ���Ļ��������㷨---------------------------*/
/*------------�ɱ�����A��������n�ͱ���e����ͼ���ڽӾ���g--------------------*/
// void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
// {
//     int i, j;

//     g.n = n;
//     g.e = e;
//     for (i = 0; i < g.n; i++)
//         for (j = 0; j < g.n; j++)
//             g.edges[i][j] = A[i][j];
// }

/*------------����ڽӾ���g--------------------*/
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
//                 printf("%4s", "��");
//         }
//         printf("\n");
//     }
// }

/*-------------------------�ڽӱ�Ļ��������㷨---------------------------*/
/*-------------------�ɱ�����A��������n�ͱ���e����ͼ���ڽӱ�G--------------------*/
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;

    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)                              //���ڽӱ�������ͷ����ָ�����ó�ֵNULL
    {
        G->adjlist[i].firstarc = NULL;
    }

    for (i = 0; i < n; i++)                              //����ڽӾ����е�ÿ��Ԫ��
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (A[i][j] != 0 && A[i][j] != INF)          //����һ����
            {
                p = (ArcNode*)malloc(sizeof(ArcNode)); //����һ�����p
                p->adjvex = j;                          //�ڽӵ���
                p->weight = A[i][j];                    //�ߵ�Ȩ��
                p->nextarc = G->adjlist[i].firstarc;    //����ͷ�巨������p
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

/*-------------------����ڽӱ�G--------------------*/
void DispAdj(AdjGraph* G)
{
    ArcNode* p;

    for (int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d]->", p->adjvex, p->weight);  //�ڽӵ���[Ȩ��]
            p = p->nextarc;
        }
        printf("\n");
    }
}

/*-------------------����ͼ���ڽӱ�G--------------------*/
void DestroyAdj(AdjGraph*& G)
{
    ArcNode* pre, * p;

    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;                   //preָ���i����������׽��
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL)                            //�ͷŵ�i������������б߽��
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);                                            //�ͷ�ͷ�������
}

#define MAX_SIZE    100

int visited[MAXV] = { 0 };                             //ȫ������

/*--------------��ͼG�Ӷ���v�������������������----------------*/
void DFSTree(AdjGraph* G, int v)
{
    ArcNode* p;

    visited[v] = 1;                                         //���ѷ��ʱ��
    p = G->adjlist[v].firstarc;                             //pָ�򶥵�v�ĵ�һ�����ڵ�
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)                         //��p->adjvex����δ����,�ݹ������
        {
            printf("(%d,%d) ", v, p->adjvex);
            DFSTree(G, p->adjvex);
        }
        p = p->nextarc;                                     //pָ�򶥵�v����һ�����ڵ�
    }
}

/*--------------��ͼG�Ӷ���v�����Ĺ������������----------------*/
void BFSTree(AdjGraph* G, int v)
{
    int que[MAXV];                                           //���廷�ζ���
    int que_front = 0, que_rear = 0;
    ArcNode* p;
    int visited[MAXV];                                       //���嶥����ʱ�־����
    int i;
    int adjvex;

    for (i = 0; i < G->n; i++)
        visited[i] = 0;                                      //������ʱ�־�����ʼ��
    visited[v] = 1;                                          //���ѷ��ʱ��
    que_rear++;                                              //����v����
    que[que_rear] = v;
    while (que_front != que_rear)                             //�Ӳ���ѭ��
    {
        que_front = (que_front + 1) % MAXV;
        adjvex = que[que_front];                             //����һ������adjvex
        p = G->adjlist[adjvex].firstarc;                     //pָ��adjvex�ĵ�һ�����ڵ�
        while (p != NULL)                                     //����adjvex���������ڵ�
        {
            if (visited[p->adjvex] == 0)                      //����ǰ�ڽӵ�δ������
            {
                printf("(%d,%d) ", adjvex, p->adjvex);
                visited[p->adjvex] = 1;                      //���ѷ��ʱ��
                que_rear = (que_rear + 1) % MAXV;
                que[que_rear] = p->adjvex;                   //����p->adjvex���
            }
            p = p->nextarc;                                  //pָ�򶥵�v����һ���ڽӵ�
        }
    }
    printf("\n");
}

int main(void)
{
    AdjGraph* G;
    int n = 11;                                  //ͼ������
    int e = 13;                                  //ͼ����
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
    printf("ͼG���ڽӱ�:\n");
    DispAdj(G);
    int v = 3;
    printf("�������������:\n");
    DFSTree(G, v);
    printf("\n");
    printf("�������������:\n");
    BFSTree(G, v);

    printf("����ͼ���ڽӱ�\n");
    DestroyAdj(G);

    return 0;
}
