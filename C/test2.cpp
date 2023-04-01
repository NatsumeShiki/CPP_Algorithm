#include<iostream>
#include<cstring>
using namespace std;

struct node{
  int coef; // 系数
  int exp; // 指数
  node* next; 
};

node* CreateNode(int coef, int exp){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->coef = coef;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

void ListCreate(node* &p){
  int cnt;
  printf("请输入多项式的项数：");
  scanf("%d", &cnt);
  int a, b;
  p = (node*)malloc(sizeof(node));
  node* cur = p;
  for(int i = 1; i <= cnt; i++){
    printf("请输入第%d项的系数和指数(空格隔开)：", i);
    scanf("%d%d", &a, &b);
    cur->next = CreateNode(a, b);
    cur = cur->next;
  }
}

void ListDisplay(node* &p){
  node* cur = p->next;
  while(cur != NULL && cur->next != NULL){
    printf("%dX^%d+", cur->coef, cur->exp);
    cur = cur->next;
  }
  printf("%dX^%d\n", cur->coef, cur->exp);
}

void ListSort(node* &L){
  node* p, *pre, *q;
  p = L->next->next;
  L->next->next = NULL;
  while(p != NULL){
    q = p->next;
    pre = L;
    while(pre->next != NULL && pre->next->exp > p->exp)
      pre = pre->next;
    p->next = pre->next;
    pre->next = p;
    p = q;
  }
}

void ListAdd(node* p, node* q){
  node* ph = p->next, *pPre = p;
  node* qh = q->next;
  while(ph != NULL && qh != NULL){
    if(ph->exp < qh->exp) {
      pPre->next = qh;
      node* cur = qh->next;
      qh->next = ph;
      qh = cur;
    }
    else if(ph->exp > qh->exp) ph = ph->next, pPre = pPre->next;
    else{
      ph->coef = ph->coef + qh->coef;
      if(ph->coef == 0){
        pPre->next = ph->next;
        free(ph);
        ph = pPre->next;
      }else ph = ph->next, pPre = pPre->next;
      node* cur = qh;
      qh = qh->next;
      free(cur);
    }
  }
  if(qh != NULL){
    pPre->next = qh;
  }
}

void DestoryList(node* &p){
  node* cur = p;
  while(p != NULL){
    p = p->next;
    cur->next = NULL;
    free(cur);
    cur = p;
  }
}

int main(){
  node *p, *q;
  puts("请输入第一个多项式P(x)");
  ListCreate(p);
  ListSort(p);
  ListDisplay(p);
  puts("");
  puts("请输入第二个多项式Q(x)");
  ListCreate(q);
  ListSort(q);
  ListDisplay(q);

  puts("");
  printf("相加后多项式为：");
  ListAdd(p, q);
  ListDisplay(p);

  DestoryList(p);
  DestoryList(q);
  return 0;
}