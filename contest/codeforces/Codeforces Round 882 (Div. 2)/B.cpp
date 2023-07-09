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
int a[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = a[0];
  for(int i = 0; i < n; i++) ans &= a[i];

  if(ans != 0){
    cout << 1 << endl;
    return;
  }

  int res = 0;
  int t;
  for(int i = 0; i < n; ){
    int j = i + 1;
    t = a[i];
    if(t == 0){
      res++;
      i = j;
      continue;
    }
    while(j < n && ((t & a[j]) <= t)){
      t &= a[j];
      j++;
      if(t == 0) break;
    }
      // cout << j << " " << t << endl;
    res++;
    i = j;
  }
  if(t != 0) res--;
  cout << res << endl;
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