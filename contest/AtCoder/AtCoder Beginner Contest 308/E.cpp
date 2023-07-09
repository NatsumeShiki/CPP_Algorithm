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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N];
int l[N][3], r[N][3];
char g[N];
int f[3];
LL res;

void solve(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", g + 1);

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++) l[i][j] = l[i - 1][j];
    if(g[i] == 'M') l[i][a[i]]++;
  }
  for(int i = n; i; i--){
    for(int j = 0; j < 3; j++) r[i][j] = r[i + 1][j];
    if(g[i] == 'X') r[i][a[i]]++;
  }

  LL res = 0;
  for(int i = 1; i <= n; i++){
    if(g[i] != 'E') continue;
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        LL ans = (LL)l[i][j] * r[i][k];
        int mex = 1 << j | 1 << k | 1 << a[i];
        int m = 0;
        while(mex >> m & 1) m++;
        res += ans * m;
      }
    }
  }

  printf("%lld\n", res);
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