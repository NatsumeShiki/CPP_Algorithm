// 给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。

// 请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

// 重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

// 输入格式
// 第一行包含整数 n，表示树的结点数。

// 接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

// 输出格式
// 输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

// 数据范围
// 1≤n≤105
// 输入样例
// 9
// 1 2
// 1 7
// 1 4
// 2 8
// 2 5
// 4 3
// 3 9
// 4 6
// 输出样例：
// 4

#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx; // 因为是无向图，方向是双向的，所以需要N的两倍来存储
int n, ans = N; // ans就是要求的最小节点数
bool st[N]; // 记录节点是否已经遍历

void add(int a, int b){
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

int dfs(int u){
  st[u] = true; // 将当前节点设置为已经遍历
  int sum = 1, res = 0; // sum是求当前节点+子节点数目，res是求是求子节点数目
  for(int i = h[u]; i != -1; i = ne[i]){
    int j = e[i];
    if(!st[j]){ // 向下遍历
      int s = dfs(j); // 这一步求出子树的节点数目
      res = max(res, s); // 计算当删除该节点后，节点数最多是多少
      sum += s; // 计算包括当前节点在内的数的节点数
    }
  }
  res = max(res, n - sum); // 这一步是为了求该子树上面部分的节点数目，然后与res取大
  ans = min(ans, res); // 与ans比较，取小
  return sum; // 返回当前子树节点数目
}

int main(){
  cin >> n;
  memset(h, -1, sizeof h);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}