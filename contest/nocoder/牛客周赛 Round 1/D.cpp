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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f ,mod = 1e9 + 7;
int n, m, k, t;
LL f[N][10];

void solve(){
  string s;
  cin >> s;
  n = s.size();
  for(int i = 1; i <= n; i++){
    int x = s[i - 1] - '0';
    for(int j = 0; j < 9; j++) {
      f[i][(j * 10 + x) % 9] = (f[i - 1][(j * 10 + x) % 9] + f[i - 1][j]) % mod;
    }
      f[i][x % 9] = (f[i][x % 9] + 1) % mod;
  }
  cout << f[n][0] << endl;
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