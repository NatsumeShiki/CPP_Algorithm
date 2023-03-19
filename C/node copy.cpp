#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node{
  int data;
  struct node* next;
}LinkList;

LinkList* CreateNode(int x){
  LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));

  if(newnode == NULL){
    puts("malloc newnode fail");
    return NULL;
  }

  newnode->data = x;
  newnode->next = NULL;

  return newnode;
}

void InsertPushBack(LinkList* &pphead, int x){
  LinkList* newnode = CreateNode(x);
  if(pphead == NULL) pphead = newnode;
  else if(pphead->next == NULL) pphead->next = newnode;
  else{
    LinkList* cur = pphead;
    while(cur->next != NULL) cur = cur->next;
    cur->next = newnode;
  }
}

void PrintList(LinkList* pphead){
  LinkList* cur = pphead;
  while(cur != NULL) {
    printf("%d->", cur->data);
    cur = cur->next;
  }
  printf("NULL\n");
}

void DestoryList(LinkList* head){
  if(head == NULL)
    return;

  LinkList* cur = head;
  while(cur){
    LinkList* next = cur->next;
    free(cur);
    cur = next;
  }
  head = NULL;
}

void Merge(LinkList* &A, LinkList* &B){
  LinkList* cur = NULL;
  LinkList* head = NULL;
  while(A != NULL && B != NULL){
    int a = A->data;
    int b = B->data;
    if(a < b) A = A->next;
    else if(b < a) B = B->next;
    else{
      LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
      newnode->data = a;
      newnode->next = NULL;
      if(cur == NULL){
        cur = newnode;
        head = cur;
      }else{
        cur->next = newnode;
        cur = cur->next;
      }
      A = A->next;
      B = B->next;
    }
  }
  cur->next = NULL;
  A = head;
}

int main(){
  LinkList* A = NULL, *B = NULL;
  InsertPushBack(A, 0);
  InsertPushBack(A, 3);
  InsertPushBack(A, 4);
  InsertPushBack(A, 6);
  InsertPushBack(A, 7);
  InsertPushBack(A, 9);
  InsertPushBack(B, 1);
  InsertPushBack(B, 2);
  InsertPushBack(B, 3);
  InsertPushBack(B, 5);
  InsertPushBack(B, 7);
  InsertPushBack(B, 8);
  InsertPushBack(B, 10);

 Merge(A, B);
  PrintList(A);

  return 0;
}