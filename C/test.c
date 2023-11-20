#include<stdio.h>

int find(int *arry, int leng, int key){ 
  int low = 1;
  int mid;
  int high = leng;
  while(low <= high){ 
    mid = (low + high) / 2;
    if(key > arry[mid - 1])
      low = mid;
    else if(key < arry[mid - 1])
      high = mid;
    else
      return mid;
  }
  return 0;
}

int main(){
  int a[10];
  int i, m, n;
  for(i = 0; i < 10; i++)
  a[i] = i + 1;
  do{ 
    printf("请输入查找数(1~10!):");
    scanf("%d",&m);
  } while(m > 10 || m < 1);
  n = find(a, 10, m);
  printf("查询值为 a[%d]\n", n - 1);
  return 0;
}
