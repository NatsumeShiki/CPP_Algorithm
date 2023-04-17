#include<iostream>
using namespace std;

const int MaxSize = 1e6 + 10, k = 10;
int n, nowK = 0;
int train[MaxSize];
int a[10] = {0, 3, 6, 9, 2, 4, 7, 1, 8, 5};

typedef struct {
    int data[MaxSize];
    int front, rear;
}SqQueue;
SqQueue* rail[k + 1];

void InitQueue(SqQueue* &q){
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void enQueue(SqQueue* &q, int e){
    q->data[q->rear] = e;
    q->rear++;
}

void deQueue(SqQueue* &q){
    q->front++;
}

int getTop(SqQueue* &q){
    if(q->front == q->rear) return -1;
    return q->data[q->front];
}

int getBack(SqQueue* q){
    if(q->front == q->rear) return -1;
    return q->data[q->rear - 1];
}

void solve(){
    for(int i = 1; i <= k; i++) InitQueue(rail[i]);
    int nowout = 1;
    int i = 1;
    while(nowout <= n){
        bool flag = true;
        if(train[i] == nowout){
            printf("%d号车厢从H%d号轨道出轨\n", train[i], n);
            i++, nowout++;
            flag = false;
        }else{
            for(int j = 1; j <= nowK; j++){
                int c = getTop(rail[j]);
                if(c == nowout){
                    printf("%d号车厢从%d号缓冲轨道出轨\n", c, j);
                    deQueue(rail[j]);
                    nowout++;
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
                int j = 1;
                for(; j <= nowK; j++){
                    int c = getBack(rail[j]);
                    if(c != -1 && c < train[i]) break;
                }
                if(j == nowK + 1){
                    if(j <= k){
                        printf("%d号车厢进入%d号缓冲轨道\n", train[i], j);
                        enQueue(rail[j], train[i]);
                        nowK++, i++;
                    }else{
                        printf("车厢无法重排\n");
                        return;
                    }
                }else{
                    printf("%d号车厢进入%d号缓冲轨道\n", train[i], j);
                    enQueue(rail[j], train[i]);
                    i++;
                }
            }
    }
}

int main(){
    printf("请输入一共多少个车厢？\n");
    scanf("%d", &n);
    printf("火车车厢节数为%d节\n", n);
    printf("请输入进入H3轨道的火车序列\n");
    for(int i = 1; i <= n; i++) scanf("%d", &train[i]);
    printf("进入H3号轨车厢序列为：");
    for(int i = n; i >= 1; i--) printf("%d ", train[i]);
    puts("");
    solve();

    return 0;
}