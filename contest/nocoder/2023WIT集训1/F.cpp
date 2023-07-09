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

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  cin >> m;
  while(m--){
    int x, y;
    cin >> x >> y;
    int l = 0, r = n - 1;
    while(l < r){
      int mid = l + r >> 1;
      if(a[mid] < x) l = mid + 1;
      else r = mid; 
    }
    if(a[l] < x || a[l] > y) {
      cout << 0 << endl;
      continue;
    }

    int L = l;
    r = n - 1;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(a[mid] > y) r = mid - 1;
      else l = mid;
    }
    // cout << L << " " << l << endl;
    cout << l - L + 1 << endl;
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