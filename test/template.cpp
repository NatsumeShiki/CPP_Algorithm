#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
#include<unordered_map>
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

const int N = 10, M = 20;
bool col[N], row[N], deg[M], rdeg[M];
int g[N][N];
int n;
int res;

void dfs(int x, int y, int cnt){
  if(y == n) x++, y = 0;
  if(x == n){
    if(cnt == n) res++;
    return;
  }

  dfs(x, y + 1, cnt);
  if(g[x][y] == 1 && !row[x] && !col[y] && !deg[x + y] && !rdeg[x - y + n]){
    row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = true;
    dfs(x, y + 1, cnt + 1);
    row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = false;
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> g[i][j];

  dfs(0, 0, 0);
  cout << res * (res - 1) <<endl;
  cout << res << endl;
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