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

bool check(int mid){
  LL sum = 0;
  for(int i = 0; i < n; i++){
    int x = mid - a[i];
    if(x > 0) sum += x;
    // if(mid == 1) cout << x << " ";
  }
  // cout << sum << " " << mid << endl;
  return sum <= m && sum <= mid;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];

  int l = 0, r =  1e9;
  while(l < r){
    int mid = l + r + 1 >> 1;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
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