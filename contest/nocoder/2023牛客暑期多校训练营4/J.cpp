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
int res = 0;
set<string> S;

void dfs(int u, int sum, int minv){
  if(sum < 0) return;
  if(minv < 0) return;
  if(u == n){
    res++;
    for(int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
    return;
  }
  for(int i = -m; i <= m; i++){
    arr[u] = i;
    dfs(u + 1, sum + i, min(minv, minv + i));
  }
  return;
}

void solve(){
  cin >> n >> m;
  res = 0;
  dfs(0, 0, INF);
  cout << n << " " << m << " " << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // for(int i = 1; i <= 10; i++)
  //   for(int j = 1; j <= 10; j++)
  //     cout << i << " " << j << endl;

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}