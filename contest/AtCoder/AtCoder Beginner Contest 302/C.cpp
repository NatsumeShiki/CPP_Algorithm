#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char a[10][10];
int res[10][10];
int h[10], ne[100], e[100], idx;
bool st[10];
bool flag = false;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa, int cnt){
  // if(cnt + 1 >= n) {
  //   flag = true;
  //   return;
  // }
  // cout << "cnt = " << cnt << endl;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == fa) continue;
    if(st[j]) continue;
    st[j] = true;
    // cout << j << endl;

    if(cnt + 1 == n) flag = true;
    dfs(j, u, cnt + 1);
    st[j] = false;
  }
}

void solve(){
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      int cnt = 0;
      for(int k = 0; k < m; k++)
        if(a[i][k] != a[j][k])
          cnt++;
      if(cnt == 1)
        add(i, j);
      // cout << cnt << " ";
    }
    // cout << endl;
  }

  // for(int i = 0; i < n; i++)
  //   for(int j = 0; j < n; j++)
  //     if(res[i][j] == 1)
  //       add(i, j);

  // st[0] = true;
  for(int i = 0; i < n; i++){
    st[i] = true;
    dfs(i, -1, 1);
    st[i] = false;
  }
    // dfs(7, -1, 1);

  if(flag) puts("Yes");
  else puts("No");

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}