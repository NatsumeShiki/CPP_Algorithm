#include<iostream>
using namespace std;

const int MaxSize = 100;

struct SeQueue{
  int data[MaxSize];
  int front, cnt;
};

void InitQueue(SeQueue* &q){
  q = (SeQueue*)malloc(sizeof(SeQueue));
  q->front = 0;
  q->cnt = 0;
}

bool EnQueue(SeQueue* &q, int x){
  int rear;
  if(q->cnt == MaxSize) return false;
  else {
    rear = (q->front + q->cnt) % MaxSize;
    rear = (rear + 1) % MaxSize;
    q->data[rear] = x;
    q->cnt++;
    return true;
  }
}

bool DeQueue(SeQueue* q, int& x){
  if(q->cnt == 0) return false;
  else{
    q->front = (q->front + 1) % MaxSize;
    x = q->data[q->front];
    q->cnt--;
    return true;
  }
}

bool QueueEmpty(SeQueue* &q){
  return q->cnt == 0;
}

int main(){


  return 0;
}