#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 3010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int f[N][N][4];
int w[N];
int score[N][5];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> w[i];
  for(int i = 1; i <= n; i++)
      for(int j = 1; j <= 4; j++)
          cin >> score[i][j];
    
  int res = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= m; j++){
      for(int k = 1; k <= 4; k++){
        f[i][j][k] = f[i - 1][j][k];
        res = max(res, f[i][j][k]);
        for(int u = 1; u <= k; u++)
          if(j >= w[i]) {
            f[i][j][k] = max(f[i][j][k], f[i - 1][j - w[i]][u] + score[i][k]);
            res = max(res, f[i][j][k]);
          }
      }
    }

  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}