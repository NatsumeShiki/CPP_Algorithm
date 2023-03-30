#include<iostream>
using namespace std;

const int n = 100;

typedef struct{
  int A[n];
  int front, rear;
}SqQueue;

void Init(SqQueue* &q){ // 初始化队列
  q = (SqQueue*)malloc(sizeof(SqQueue));
  q->front = 0;
  q->rear = 0; // 将队头和队尾下标都设置为0
}
bool QueueEmpty(SqQueue* &q){
  return q->front == q->rear; // 如果头指针和尾指针下标相同，则队列为空
}

bool QueueFull(SqQueue* &q){ // 判断队列是否已满
  // 如果尾指针在头指针后面，只有当头指针为0，尾指针为n-1时，队列才是满的
  // 如果尾指针在头指针前面，那么当尾指针下标在头指针下标前一位时，队列是满的
  if((q->rear + 1) % n == q->front) return true; 
  return false;
}

bool EnQueue(SqQueue* &q, int x){
  if(QueueFull(q)) return false; // 如果队列已经满了，返回false
  q->A[q->rear] = x; // 队尾插入元素
  q->rear = (q->rear + 1) % n; // 尾指针向后移动一位，如果到了下标为n，尾指针下标返回到0
}

bool DeQueue(SqQueue* &q){
  if(QueueEmpty(q)) return false; // 如果队列为空，返回false
  q->front = (q->front + 1) % n; // 头指针向后移动一位
  return true;
}

int main(){
  SqQueue *q;
  Init(q);


  return 0;
}