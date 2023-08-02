#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 210, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
char g[N][N];
bool vis[N][N];
int cnt[N][N];
int ans = 0;

void dfs(int x, int y, int u){
  while(true){
    int a = x + dx[u], b = y + dy[u];
    if(g[a][b] == '#') break;
    cnt[a][b]++;
    x = a, y = b;
  }

  if(!vis[x][y]){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
      int a = x + dx[i], b = y + dy[i];
      if(g[a][b] == '#') continue;
      cnt[a][b]++;
      dfs(a, b, i);
    }
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];

  for(int i = 0; i < 4; i++){
    int a = 1 + dx[i], b = 1 + dy[i];
    if(g[a][b] == '#') continue;
    vis[1][1] = true;
    cnt[1][1]++;
    dfs(1, 1, i);
  }

  int res = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(cnt[i][j])
        res++;

  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}