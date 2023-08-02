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
PII p[N];
int pos[N];
int res;

void dfs(int u, int maxv){
  if(u > n){
    if(maxv != m + 1) return;
    for(int i = 0; i < k; i++){
      int a = p[i].x, b = p[i].y;
      if(pos[a] == pos[b])
          return;
    }
    res++;
    // for(int i = 1; i <= n; i++) cout << pos[i] << " \n"[i == n];
    return;
  }

  for(int i = 1; i <= maxv; i++){
    pos[u] = i;
    dfs(u + 1, max(maxv, i + 1));
  }
}

// void dfs(int u, int maxv){
//   cout << u << endl;
//   if(u == n + 1){
//     for(int i = 1; i <= n; i++) cout << pos[i] << " \n"[i == n];
//     if(maxv != m + 1) return;
//     bool ok = true;
//     for(int i = 0; i < k; i++){
//       if(pos[p[i].x] == pos[p[i].y])
//         ok = false;
//     }
//     res += ok;
//     return;
//   }
//   for(int i = 1; i <= maxv; i++){
//     pos[u] = i;
//     dfs(u + 1, max(maxv, i + 1));
//   }
// }

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++) cin >> p[i].x >> p[i].y;
  dfs(1, 1);
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