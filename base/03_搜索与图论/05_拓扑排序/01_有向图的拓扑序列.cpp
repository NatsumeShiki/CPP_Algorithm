// 给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。

// 请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

// 若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

// 输出格式
// 共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

// 否则输出 −1。

// 数据范围
// 1≤n,m≤105
// 输入样例：
// 3 3
// 1 2
// 2 3
// 1 3
// 输出样例：
// 1 2 3

#include<iostream>
#include<cstring>
using namespace std;

int n, m;
const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b){
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

// 思路是不断把 入度 减去，直到hh > tt，此时判断tt和n的关系，如果tt == n，表明这个图是有向无环图，否则，说明途中肯定有环，也就是说不是拓扑序列
bool topsort(){
  int hh = 0, tt = 0;
  for(int i = 1; i <= n; i++)
    if(d[i] == 0)
      q[++tt] = i; // 把所有入度为0的点都存进队列中，因为它们是入口
  while(hh <= tt){
    int t = q[hh++];
    for(int i = h[t]; i != -1; i = ne[i]){
      int j = e[i];
      d[j]--;
      if(d[j] == 0) q[++tt] = j; // 入度减1后入度为0，此时再以它为起点继续向后走
    }
  }
  return tt == n;
}

int main(){
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    add(a, b);
    d[b]++;
  }

  if(topsort()){
    for(int i = 1; i <= n; i++) cout << q[i] << " ";
    cout << endl;
  }else{
    cout << "-1" << endl;
  }
}