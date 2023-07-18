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

const int N = 510, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
char g[N][N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];

  int lh = INF, ll = INF, rr = 0, rd = 0;
  for(int i = 0; i < n; i++)
    for(int j= 0; j < m; j++){
      if(g[i][j] == '#'){
        lh = min(lh, j);
        ll = min(ll, i);
        rr = max(rr, i);
        rd = max(rd, j);
      }
    }
  // cout << ll << rr << endl;
  // cout << lh << rd << endl;
  for(int i = ll; i <= rr; i++)
    for(int j = lh; j <= rd; j++){
      if(g[i][j] != '#'){
        cout << i + 1 << " " << j + 1 << endl;
        return;
      }
    }
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