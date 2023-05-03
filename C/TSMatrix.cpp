#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
 
#define M 3
#define N 5
#define MaxSize 5

typedef struct {
  int r, c, d;
}TupNode;
typedef struct {
  int rows, cols, nums;
  TupNode data[MaxSize];
}TSMatrix;
int A[M][N], TA[N][M];

void CreateMat(TSMatrix &t, int A[M][N]){
  t.rows = M, t.cols = N, t.nums = 0;
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      if(A[i][j] != 0){
        t.data[t.nums].r = i, t.data[t.nums].c = j;
        t.data[t.nums].d = A[i][j], t.nums++;
      }
}

void TranTat(TSMatrix t, TSMatrix &tb){
  int k, kl = 0, v;
  tb.rows = t.cols, tb.cols = t.rows, tb.nums = t.nums;
  if(t.nums != 0)
    for(v = 0; v < t.cols; v++)
      for(k = 0; k < t.nums; k++)
        if(t.data[k].c == v){
          tb.data[kl].r = t.data[k].c;
          tb.data[kl].c = t.data[k].r;
          tb.data[kl].d = t.data[k].d;
          kl++;
        }
}

void TranMatrix(int A[M][N], int TA[N][M]){
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)  
      TA[j][i] = A[i][j];
}

void DispMatrix(int A[M][N], int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)  
      printf("\t%2d", A[i][j]);
    printf("\n");
  }
}

void DispMart(TSMatrix t){
  if(t.nums <= 0) return;
  printf("\t%2d\t%2d\t%2d\n", t.rows, t.cols, t.nums);
  printf("\t-------------------\n");
  for(int k = 0; k < t.nums; k++)
    printf("\t%2d\t%2d\t%2d\n", t.data[k].r, t.data[k].c, t.data[k].d);
}

int main(){
A[0][1] = 14;
  A[0][4] = -5;
  A[1][1] = -7;
  A[2][0] = 16;
  A[2][3] = 28;
  TSMatrix t;
  CreateMat(t, A);
  printf("转置前的矩阵为\n");
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++)  
      printf("\t%2d", A[i][j]);
    printf("\n");
  }
  printf("原始矩阵对应的三元组顺序表\n");
  DispMart(t);

  TSMatrix tb;
  TranMatrix(A, TA);
  TranTat(t, tb);
  printf("转置后的矩阵为\n");
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++)  
      printf("\t%2d", TA[i][j]);
    printf("\n");
  }
  printf("对应的三元组顺序表\n");
  DispMart(t);

  return 0;
}