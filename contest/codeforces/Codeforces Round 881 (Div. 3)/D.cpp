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
int h[N], e[M], ne[M], idx;
int res[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa){
  int cnt = 0;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == fa) continue;
    dfs(j, u);
    res[u] += res[j];
    cnt++;
  }
  if(cnt == 0) res[u] = 1;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    scanf("%d", &n);
    memset(h, -1, n * 4 + 4);
    idx = 0;
    for(int i = 1; i < n; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      add(a, b), add(b, a);
    }
    dfs(1, -1);
    scanf("%d", &m);
    while(m--){
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%lld\n", (LL)res[a] * res[b]);
    }
    memset(res, 0, n * 4 + 4);
  }
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