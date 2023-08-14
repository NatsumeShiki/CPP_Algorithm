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
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
bool st[N][N];
vector<int> alls;
char g[N][N];
int cnt[N];

void dfs(int x, int y, int t){
  int a = x + 1, b = y + 1;
  if(a < n && b < m && g[a][b] == '#') {
    dfs(a, b, t + 1);
    st[a][b] = true;
  }
  else {
    cnt[(t - 1) / 2]++;
    // cout << x << " " << y << " " << t << endl;
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '.' || st[i][j]) continue;
      st[i][j] = true;
      dfs(i, j, 1);
      // cout << i << " " << j << endl;
    }
  }

  for(int i = 1; i <= min(n, m); i++) cout << cnt[i] << " ";
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}