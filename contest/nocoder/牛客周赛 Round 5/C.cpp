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
int h[N], e[M], ne[M], idx;
int w[N];
int l, r;
int res;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}

void dfs(int u, int fa, int sum, int deep){
  if(sum > r) return;
  if(deep && sum >= l && sum <= r) res++;
  // cout << u << " " << sum << endl;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == fa) continue;
    dfs(j, u, sum * 2 + w[j], deep + 1);
  }
}

void solve(){
  cin >> n >> l >> r;
  for(int i = 1; i <= n; i++){
    char c;
    cin >> c;
    w[i] = c - '0';
  }
  memset(h, -1, sizeof h);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  for(int i = 1; i <= n; i++){
    dfs(i, -1, w[i], 0);
  }
  cout << res << endl;
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
  while(T--){
    solve();
  }

  return 0;
}