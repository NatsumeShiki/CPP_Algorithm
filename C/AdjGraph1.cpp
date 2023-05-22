#include<iostream>
#include<cstring>
using namespace std;

#define MAXV 100
#define INF 32767

typedef struct ANode{
    int adjvex;
    struct ANode* nextarc;
    int weight;
}ArcNode;
typedef struct Vnode{
    int info;
    ArcNode* firstarc;
}VNode;
typedef struct{
    Vnode adjlist[MAXV];
    int n, e;
}AdjGraph;
struct SqQueue{
    int data[MAXV];
    int front, rear;
};

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e){
    int i, j = 0;
    ArcNode *p;
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for(i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;
    for(i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--)
        if(A[i][j] != 0 && A[i][j] != INF){
            p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = j;
            p->weight = A[i][j];
            p->nextarc = G->adjlist[i].firstarc;
            G->adjlist[i].firstarc = p;
        }
    }
    G->n = n,G->e = e;
}

void DispAdj(AdjGraph *G){
    ArcNode* p;
    for(int i = 0; i < G->n; i++){
        p = G->adjlist[i].firstarc;
        printf("%d: ", i);
        while(p){
            printf("%3d[%d]->", p->adjvex, p->weight);
            p = p->nextarc;
        }
        puts("");
    }
}

void TopSort(AdjGraph* G){
    printf("��������Ϊ��");
    int st[100];
    int hh = 0, tt = -1;
    int din[100];
    for(int i = 0; i < G->n; i++) din[i] = 0;
    for(int i = 0; i < G->n; i++){
        ArcNode* p = G->adjlist[i].firstarc;
        while(p){
            int w = p->adjvex;
            din[w]++;
            p = p->nextarc;
        }
    }
    for(int i = 0; i < G->n; i++)
        if(din[i] == 0)
            st[++tt] = i;
    while(hh <= tt){
        int t = st[tt--];
        printf("%d ", t);
        ArcNode* p = G->adjlist[t].firstarc;
        while(p){
            int w = p->adjvex;
            if(--din[w] == 0) st[++tt] = w;
            p = p->nextarc;
        }
    }
    puts("");
}

void DestroyAdj(AdjGraph* &G){
    int i;
    ArcNode* pre, *p;
    for(i = 0; i < G->n; i++){
        pre = G->adjlist[i].firstarc;
        if(pre){
            p = pre->nextarc;
            while(p){
                free(pre);
                pre = p, p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

int main(){
    AdjGraph* G;
    int n = 7;
    int e = 8;
    int A[100][100] = {{0, 0, 1}, {0, 0, 0, 1, 1, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0, 1, 1}, {0}, {0}, {0, 0, 0, 0, 0, 1} };


    CreateAdj(G, A, n, e);
    printf("ͼG���ڽӱ�:\n");
    DispAdj(G);
    TopSort(G);
    printf("����ͼ���ڽӱ�\n");
    DestroyAdj(G);

  return 0;
}

/*
������������������Ȱ����ж���������ȵĸ����������������Ϊ0��ֱ�Ӵ��ջ�У����ÿ�δ�ջ��ȡ����һ�����㣬�������Ȼ���ٽ�����������ܵ��Ķ����
��ȼ�1�����Ϊ0���Ͱ���push��ջ�У�ֱ��ջΪ�գ�ϸ�ڲ��־�����α����������

ͨ������ʵ�飬ѧϰ�˱���ͼ�����ͼ�Լ���ͼ������������ķ�ʽ��������������ںܶ��㷨���ж���ʹ�ã��к���Ҫ�����壬��������ʵ�飬����˴���������
������Ժ�ѧϰ�㷨�������������Ĺ����л������С������
*/