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
int p[N];
bool st[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}

bool dfs(int u, int v, int& cnt){
  st[u] = true;
  cnt++;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == v) return true;
    if(!st[j])
      if(dfs(j, v, cnt)) return true;
  }
  return false;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    memset(st, 0, sizeof st);
    idx = 0;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++){
      int x;
      scanf("%d", &x);
      add(i, x);
      p[find(i)] = find(x);
    }

    int maxd = 0, mind = 0;
    set<int> S;
    for(int i = 1; i <= n; i++){
      int x = find(i);
      S.insert(x);
    }
    maxd = S.size();

    int minda = 0, mindb = 0;
    for(int i = 1; i <= n; i++)
      if(!st[i]){
        int cnt = 0;
        if(dfs(i, i, cnt)){
          if(cnt > 2) minda++;
          else mindb++;
        }
      }
    mind = minda;
    if(mindb) mind++;
    if(!minda) mind = 1;

    cout << mind << " " << maxd << endl;
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