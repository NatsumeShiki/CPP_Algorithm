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
int n, m, k, t, len;
int a[N];

bool check(int x){
  int sum = 0, last = 0;
  int cnt = 0;
  for(int i = 1, j = 0; i <= n; i++){
    if(a[i] - a[j] < x){
      cnt++;
      // cout << a[i] - a[j] << " ";
    }else{
      j = i;
    }
  }
  // cout << endl;
  return cnt <= m;
}

void solve(){
  cin >> len >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  n++;
  a[n] = len;

  int l = 1, r = len;
  while(l < r){
    int mid = l + r + 1 >> 1;
    if(check(mid)) l = mid;
    else r = mid - 1;;
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