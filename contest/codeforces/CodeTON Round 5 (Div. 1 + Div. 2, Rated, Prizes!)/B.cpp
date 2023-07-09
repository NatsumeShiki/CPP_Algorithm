#include<bits/stdc++.h>
using namespace std;

#define int long long
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
int a[3][N];

bool check(int x){
  for(int i = 0; i < 32; i++){
    if((m >> i & 1) == 0 && (x >> i & 1) == 1) return false;
  }
  return true;
}

void solve(){
  cin >> n >> m;
  int res = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < n; j++){
      if(check(a[i][j])) res |= a[i][j];
      else break;
    }
  }

  if(res == m) puts("YES");
  else puts("NO");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}