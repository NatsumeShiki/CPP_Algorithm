#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
bool st[N];
int a[N];

void dfs(int u, int s, int cnt){
    if(cnt == m){
      for(int i = 1; i <= m; i++)
        cout << a[i] << " ";
      cout << endl;
      return;
    }
  if(u == N + 1){
    return;
  }

  for(int i = s; i <= n; i++){
    if(!st[i]){
      st[i] = true;
      a[u] = i;
      dfs(u + 1, i + 1, cnt + 1);
      st[i] = false;
    }
  }
}

void solve(){
  cin >> n >> m;
  dfs(1, 1, 0);
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}