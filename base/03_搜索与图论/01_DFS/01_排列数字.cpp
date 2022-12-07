// 给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

// 现在，请你按照字典序将所有的排列方法输出。

// 输入格式
// 共一行，包含一个整数 n。

// 输出格式
// 按字典序输出所有排列方案，每个方案占一行。

// 数据范围
// 1≤n≤7
// 输入样例：
// 3
// 输出样例：
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

#include<iostream>
using namespace std;

const int N = 10;
int path[N]; // 用来保存当前路径
int st[N]; // 用来保存某个数是否已经使用过了
int n;

void dfs(int u){
  if(n == u){
    for(int i = 0; i < n; i++) cout << path[i] << " "; 
    cout << endl;
    return;
  }
  for(int i = 1; i <= n; i++){ // 这里i从1开始是因为保存的整数是从1开始的
    if(!st[i]){
      path[u] = i; // 如果整数i还没被使用过，就把i填充到path[u]的位置
      st[i] = true;  // 将当前整数设置为已经使用过
      dfs(u + 1); // 继续填充下一个数
      st[i] = false; // 回溯后要把这个数设置为未使用
    }
  }
}

int main(){
  cin >> n;
  dfs(0);

  return 0;
}