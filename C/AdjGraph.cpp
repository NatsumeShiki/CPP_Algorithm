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

int visited[MAXV] = {0};
void DFSTree(AdjGraph* G, int v){
    ArcNode* p;
    visited[v] = 1;
    p = G->adjlist[v].firstarc;
    while(p){
        if(visited[p->adjvex] == 0){
            printf("(%d,%d) ", v, p->adjvex);
            DFSTree(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void BFSTree(AdjGraph *G, int v){
    int q[MAXV];
    int front = 0, rear = 0;
    ArcNode* p;
    int visited[MAXV];
    int i, adjvex;
    for(i = 0; i < G->n; i++) visited[i] = 0;
    visited[v] = 1;
    rear++;
    q[rear] = v;
    while(rear != front){
        front = (front + 1) % MAXV;
        adjvex = q[front];
        p = G->adjlist[adjvex].firstarc;
        while(p){
            if(visited[p->adjvex] == 0){
                // printf("(%d,%d) ", adjvex, p->adjvex);
                visited[p->adjvex] = 1;
                rear = (rear + 1) % MAXV;
                q[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    cout << q[rear];
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
    int n = 11;
    int e = 13;
    int A[MAXV][MAXV];

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
    puts("");
    printf("广度优先生成树:\n");
    BFSTree(G, v);
    printf("销毁图的邻接表\n");
    DestroyAdj(G);

  return 0;
}