#include<iostream>
using namespace std;

const int N = 1e5 + 10;
struct List{
  int data[N];
  int length;
};

void josephus(int n, int m){
  List* list = (List*)malloc(sizeof(List));
  list->length = n;
  for(int i = 0; i < n; i++) list->data[i] = i + 1;
  printf("出列顺序：");
  int cur = 0;
  for(int i = 0; i < n;i ++){
    cur = (cur + m - 1) % list->length;
    cout << list->data[cur] << " ";
    for(int j = cur; j < list->length - 1; j++) list->data[j] = list->data[j + 1];
    list->length--;
  }
}

int main(){
  int n, m;
  printf("请输入n和m：");
  scanf("%d%d", &n, &m);
  josephus(n, m);

  return 0;
}