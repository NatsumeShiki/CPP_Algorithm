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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
int res;
bool st[N];
int ans[N];

void dfs(int u, int sum, int maxv){
  if(u == n + 1){
    if(sum - maxv > res){
      res = sum - maxv;
      for(int i = 1; i <= n; i++)
        ans[i] = arr[i];
    }
    return;
  }

  for(int i = 1; i <= n; i++){
    if(!st[i]){
      st[i] = true;
      arr[u] = i;
      dfs(u + 1, sum + i * u, max(maxv, i * u));
      st[i] = false;
    }
  }
}

void solve(){
  cin >> n;
  // res = 0;
  // memset(st, 0, sizeof st);
  // dfs(1, 0, 0);
  // cout << n << " " << res << endl;
  // for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];

  int ans = 0;
  for(int t = 1; t <= n; t++){
    for(int i = 1; i <= n - t; i++) arr[i] = i;
    for(int i = n - t + 1, j = n; i <= n; i++, j--) arr[i] = j;

    int res = 0, maxv = 0;
    for(int i = 1; i <= n; i++){
      res += i * arr[i];
      maxv = max(maxv, i * arr[i]);
      // cout << arr[i] << " \n"[i == n];
    }
    ans = max(ans, res - maxv);
  }
  cout << ans << endl;
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