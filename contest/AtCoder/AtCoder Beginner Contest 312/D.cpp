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

const int N = 3010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int dp[N][N];

// void solve(){
//   string s;
//   cin >> s;
//   int n = s.size();
//   s = ' ' + s;
//   vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//   dp[0][0] = 1;
//   for(int i = 1; i <= n; i ++ ){
//     for(int j = (i + 1) / 2; j <= n; j ++ ){
//       if(s[i] == ')') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
//       else if(s[i] == '(') dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
//       else{
//         dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
//         dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
//       }
//     }
//   }
//   cout << dp[n][n / 2] << endl;
// }

void solve(){
  string s;
  cin >> s;
  n = s.size();
  s = " " + s;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = (i + 1) / 2; j <= i; j++){
      if(s[i] == '(') dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      else if(s[i] == ')') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      else dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
    // cout << endl;
  }
  cout << dp[n][n / 2] << endl;
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