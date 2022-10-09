// 在给定的 N 个整数 A1，A2……AN 中选出两个进行 xor（异或）运算，得到的结果最大是多少？

// 输入格式
// 第一行输入一个整数 N。

// 第二行输入 N 个整数 A1～AN。

// 输出格式
// 输出一个整数表示答案。

// 数据范围
// 1≤N≤105,
// 0≤Ai<231
// 输入样例：
// 3
// 1 2 3
// 输出样例：

#include<iostream>
using namespace std;

const int N = 100010, M = 31 * N;
int idx, a[N], son[M][2];

void insert(int x){
  int p = 0;
  for(int i = 30; i >= 0; i--){
    int u = x >> i & 1;
    if(!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
}

int query(int x){
  int p = 0, res = 0;
  for(int i = 30; i >= 0; i--){
    int u = x >> i & 1;
    if(son[p][!u]){ // 如果有相反的，就去相反的分支
      p = son[p][!u];
      res = res * 2 + !u; // 表示将当前res全部向左移一位，再将!u 或 u放到最后
    }else{
      p = son[p][u];
      res = res * 2 + u;
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  for(int i = 0; i < n; i++){
    // 先插入再查询是为了减少代码量，因为这样不用处理边界情况
    insert(a[i]);
    int x = query(a[i]);
    res = max(res, a[i] ^ x);
  }
  cout << res << endl;
  return 0;
}