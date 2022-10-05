// 输入一个长度为 n 的整数序列。

// 接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

// 请你输出进行完所有操作后的序列。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 第二行包含 n 个整数，表示整数序列。

// 接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

// 输出格式
// 共一行，包含 n 个整数，表示最终序列。

// 数据范围
// 1≤n,m≤100000,
// 1≤l≤r≤n,
// −1000≤c≤1000,
// −1000≤整数序列中元素的值≤1000
// 输入样例：
// 6 3
// 1 2 2 1 2 1
// 1 3 1
// 3 5 1
// 1 6 1
// 输出样例：
// 3 4 5 3 4 2

#include<iostream>
using namespace std;

void insert(int b[], int l, int r, int c){
  b[l] += c;
  b[r + 1] -= c; 
}

int main(){
  const int N = 100010;
  int a[N], b[N];
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]); // 从控制台读取数据
  for(int i = 1; i <= n; i++) insert(b, i, i, a[i]); // 根据a数组求出它的差分数组b

  while(m--){
    int l, r, c; // 从控制台读取区间以及加的那个数
    scanf("%d%d%d", &l, &r, &c);
    insert(b, l, r, c);
  }
  for(int i = 1; i <= n; i++){
    b[i] += b[i - 1]; // 再根据b数组求出差分数组，直接输出
    cout << b[i] << " ";
  }
  return 0;
}