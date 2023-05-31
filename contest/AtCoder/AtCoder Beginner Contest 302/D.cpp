#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
LL n, m, k, t;
LL a[N], b[N];

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);

  LL res = 0;
  for(int i = n - 1; i >= 0; i--){
    LL x = a[i] + k;
    // cout << x << endl;
    int l = 0, r = m - 1;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(b[mid] > x) r = mid - 1;
      else l = mid;
    }
    if(b[l] <= x && abs(a[i] - b[l]) <= k){
      res = a[i] + b[l];
      // cout << a[i] << " " << b[l] << endl;
      break;
    }
  }
  if(!res) res = -1;
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}