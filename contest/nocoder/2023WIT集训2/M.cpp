#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

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
int dx[2] = {4, 7};

void dfs(int u, int sum, int cnt){
  if(u == cnt){
    a[n++] = sum;
    return;
  }

  for(int i = 0; i < 2; i++){
    dfs(u + 1, sum * 10 + dx[i], cnt);
  }
}

void solve(){
  for(int k = 1; k <= 11; k++){
    dfs(0, 0, k);
  }

  for(int i = 0; i < n; i++) cout << a[i] << endl;
  int x, y;
  cin >> x >> y;
  int l = 0, r = n - 1;
  while(l < r){
    int mid = l + r >> 1;
    if(a[mid] < x) l = mid + 1;
    else r = mid;
  }
  int L = l;

  l = 0, r = n - 1;
  while(l < r){
    int mid = l + r >> 1;
    if(a[mid] >= y) r = mid;
    else l = mid + 1;
  }
  int R = l;
  // cout << L << " " << R << endl;
  // cout << a[L] << " " << a[R] << endl;

  int res = 0;
  if(y > a[L]) res = (a[L] - x + 1) * a[L];
  else res = (y - x + 1) * a[L];
  // cout << (x < a[r]) << endl;
  // cout << res << endl;
  for(int i = L + 1; i < R; i++) {
    res += (a[i] - a[i - 1]) * a[i];
    // cout << res << endl;
  }
  if(L != R) res += a[R] * (y - a[R - 1]);
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
  while(T--){
    solve();
  }

  return 0;
}