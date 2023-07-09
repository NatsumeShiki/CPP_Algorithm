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
int a[M];
int l[M], r[M], day[M];
int d[M];

bool check(int mid){
  for(int i = 1; i <= n; i++) d[i] = 0;
  // memset(d, 0, sizeof d);
  for(int i = 1; i <= mid; i++){
    d[l[i]] += day[i], d[r[i] + 1] -= day[i];
  }
  // cout << mid << " 123" << " "; 
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    // d[i] += d[i - 1];
    // cout << d[i] << " ";
    sum += d[i];
    if(sum > a[i]) return false;
  }
  return true;
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> day[i] >> l[i] >> r[i];

  int l = 1, r = m;
  while(l < r){
    int mid = l + r >> 1;
    if(check(mid)) l = mid + 1;
    else r = mid;
  }

  if(l == m) cout << 0 << endl;
  else {
    cout << -1 << endl << l << endl;
  }
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