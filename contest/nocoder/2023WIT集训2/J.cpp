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

const int N = 30, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
bool row[N], col[N], deg[N], rdeg[N];
int res;

// void dfs(int x, int y, int cnt){
//   if(y == n){
//     y = 0;
//     x++;
//   }
//   if(x == n){
//     if(cnt == n) res++;
//     return;
//   }

//   dfs(x, y + 1, cnt);

//   if(!row[x] && !col[y] && !deg[x + y] && !rdeg[x - y + n]){
//     row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = true;
//     dfs(x, y + 1, cnt + 1);
//     row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = false;
//   }
// }

void dfs(int u){
  if(u == n){
    res++;
    return;
  }

  for(int i = 0; i < n; i++){
    if(!col[i] && !deg[i + u] && !rdeg[i - u + n]){
      col[i] = deg[i + u] = rdeg[i - u + n] = true;
      dfs(u + 1);
      col[i] = deg[i + u] = rdeg[i - u + n] = false;
    }
  }
}

void solve(){
  cin >> n;

  dfs(0);

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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}