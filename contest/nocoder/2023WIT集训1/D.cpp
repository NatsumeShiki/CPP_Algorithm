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

const int N = 5010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int g[N][N];

void solve(){
  cin >> n >> m;
  int r = 0;
  while(n--){
    int x, y, v;
    cin >> x >> y >> v;
    x++, y++;
    r = max(r, x), r = max(r, y);
    g[x][y] += v;
  }

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= r; j++){
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
      // cout << g[i][j] << " ";
    }
    // cout << endl;
  }

  int res = 0;
  for(int i = m; i <= r; i++)
    for(int j = m; j <= r; j++){
      int x = g[i][j] - g[i - m][j] - g[i][j - m] + g[i - m][j - m];
      res = max(res, x);
    }

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