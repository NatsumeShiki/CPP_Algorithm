#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;

void solve(){ 
  int x, y, ex, ey;
  cin >> n >> m >> x >> y >> ex >> ey >> s;
  vector<vector<int>> g(n + 1, vector<int>(m + 1));
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
  
  int dx, dy;
  if(s == "DR") dx = 1, dy = 1;
  else if(s == "DL") dx = 1, dy = -1;
  else if(s == "UR") dx = -1, dy = 1;
  else dx = -1, dy = -1;
  // int res = 0;
  // cout << n << " " << m << endl;
  // function<int(int, int, int, int, int)> dfs = [&](int x, int y, int dx, int dy, int res) -> int {
  //   if(((x == n && y == m) || (x == 1 && y == m) || (x == n && y == 1) || (x == 1 && y == 1)) && vis[x][y]) return -1;
  //   if(x == ex && y == ey) return res;
  //   vis[x][y] = true;
  //   int a = x + dx, b = y + dy;
  //     // cout << a << " " << b << endl;
  //   if(a >= 1 && a <= n && b >= 1 && b <= m){
  //     // vis[a][b] = true;
  //     return dfs(a, b, dx, dy, res);
  //   }else{
  //     if(a > n || a < 1) dx = -dx;
  //     if(b > m || b < 1) dy = -dy;
  //     // cout << dx << " " << dy << endl;
  //     a = x + dx, b = y + dy;
  //     // cout << a << " " << b << endl;
  //     // vis[a][b] = true;
  //     return dfs(a, b, dx, dy, res + 1);
  //   }
  // };

  // cout << dfs(x, y, dx, dy, 0) << endl;

  int res = 0;
  int i;
  for(i = 0; i < 4 * n * m; i++){
    // if(((x == n && y == m) || (x == 1 && y == m) || (x == n && y == 1) || (x == 1 && y == 1)) && vis[x][y]) {
    //   res = -1;
    //   break;
    // }
    if(x == ex && y == ey) break;
    int a = x + dx, b = y + dy;
      // cout << a << " " << b << endl;
    if(a >= 1 && a <= n && b >= 1 && b <= m){
      // vis[a][b] = true;
      x = a, y = b;;
    }else{
      if(a > n || a < 1) dx = -dx;
      if(b > m || b < 1) dy = -dy;
      // cout << dx << " " << dy << endl;
      a = x + dx, b = y + dy;
      // cout << a << " " << b << endl;
      // vis[a][b] = true;
      x = a, y = b, res++;
      // return dfs(a, b, dx, dy, res + 1);
    }
  }
  if(i == 4 * n * m) res = -1;
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
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}