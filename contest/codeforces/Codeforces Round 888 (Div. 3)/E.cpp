#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int c[N];
bool st[N];
int h[N], e[M], ne[M], idx;
int res[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
  if(st[u]) return res[u];
  int ans = 0;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    ans += dfs(j);
  }
  res[u] = min(c[u], ans);
  st[u] = true;
  return res[u];
}

void solve(){
  cin >> n >> k;
  idx = 0;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
    h[i] = -1, st[i] = false, res[i] = 0;
  }
  while(k--){
    int x;
    cin >> x;
    c[x] = 0;
  }
  for(int i = 1; i <= n; i++){
    cin >> m;
    if(m == 0) {
      st[i] = true;
      res[i] = c[i];
    }
    while(m--){
      int x;
      cin >> x;
      add(i, x);
    }
  }

  for(int i = 1; i <= n; i++){
    if(!st[i])
      dfs(i);
  }

  for(int i = 1; i <= n; i++) cout << res[i] << " ";
  cout << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}