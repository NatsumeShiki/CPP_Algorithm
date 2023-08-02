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

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
char g[N][N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];
  int res = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      if(g[i][j] == '1' || g[i][j] == '2') continue;
      int cnt = 0;
      bool flag = false;
      for(int u = 0; u < 4; u++){
        int a = i + dx[u], b = j + dy[u];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(g[a][b] == '1') cnt++;
        if(g[a][b] == '2') flag = true;
      }
      if(cnt == 3 && !flag) res++;
    }
  if(!res) puts("NO");
  else cout << "YES" << endl << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}