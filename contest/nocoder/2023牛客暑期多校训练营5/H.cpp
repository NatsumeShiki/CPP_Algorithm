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

void solve(){
  cin >> n >> m;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  vector<int> sz(m);
  for(int i = 0; i < m; i++) cin >> sz[i];
  if(m > n){
    sz.erase(sz.begin(), sz.end() - n);
    m = n;
  }

  vector<vector<int>> dp(m, vector<int>(201));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = sz[j]; k >= a[i]; k--){
        dp[j][k] = max(dp[j][k], dp[j][k - a[i]] + b[i]);
      }
    }

    for(int j = 0; j < m - 1; j++){
      for(int k = 0; k <= sz[j]; k++){
        dp[j + 1][0] = max(dp[j + 1][0], dp[j][k]);
      }
    }
  }

  cout << *max_element(dp[m - 1].begin(), dp[m - 1].end()) << endl;
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