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

void merge(LinkList* &h, LinkList* &h1, LinkList* &h2, LinkList* &h3){
  LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
  newnode->data = 0;
  newnode->next = NULL;
  h = newnode;
  LinkList* cur = h;
  int a, b, c;
  while(h1 != NULL || h2 != NULL || h3 != NULL){
    a = h1 == NULL ? 0x3f3f3f3f : h1->data;
    b = h2 == NULL ? 0x3f3f3f3f : h2->data;
    c = h3 == NULL ? 0x3f3f3f3f : h3->data;

    if(a < b){
      if(a < c){
        cur->next = h1;
        h1 = h1->next;
      }else{
        cur->next = h3;
        h3 = h3->next;
      }
    }else{ // b <= a
      if(b < c){
        cur->next = h2;
        h2 = h2->next;
      }else{
        cur->next = h3;
        h3 = h3->next;
      }
    }

    cur = cur->next;
  }
  LinkList* head = h->next;
  h->next = NULL;
  free(h);
  h = head;
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

int main(){
  LinkList* h = NULL, *h1 = NULL, *h2 = NULL, *h3 = NULL;
  InsertPushBack(h1, 1);
  InsertPushBack(h1, 6);
  InsertPushBack(h1, 9);
  InsertPushBack(h2, 3);
  InsertPushBack(h2, 4);
  InsertPushBack(h2, 8);
  InsertPushBack(h3, 0);
  InsertPushBack(h3, 2);
  InsertPushBack(h3, 5);
  InsertPushBack(h3, 7);
  
  merge(h, h1, h2, h3);
  PrintList(h);

  DestoryList(h);
  DestoryList(h1);
  DestoryList(h2);
  DestoryList(h3);
  return 0;
}