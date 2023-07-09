#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {2, 1, -1, -2}, dy[4] = {1, 2, 2, 1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 20, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int res;
bool st[N][N];

void dfs(int x, int y){
  if(x == n && y == m) {
    res++;
    return;
  }
  for(int i = 0; i < 4; i++){
    int a = x + dx[i], b = y + dy[i];
    if(a < 1 || a > n || b < 1 || b > m) continue;
    if(st[a][b]) continue;
    st[a][b] = true;
    dfs(a, b);
    st[a][b] = false;
  }
}

void solve(){
  cin >> n >> m;
  st[1][1] = true;
  dfs(1, 1);
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}