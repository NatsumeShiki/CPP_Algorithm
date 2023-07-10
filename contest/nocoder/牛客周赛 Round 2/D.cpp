#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t, h;
int arr[N];
int a[N], b[N];
int res[N];

void solve(){
  cin >> n >> h >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];

    res[i] = a[i] / 4 * (b[i] * 3);
    int x = a[i] % 4;
    // cout << res[i] << " ";
    // if(x <= 2) res[i] += b[i];
    if(x >= 3) res[i] += b[i];
    if(x >= 1) res[i] += b[i];
    if(res[i]) res[i] -= b[i];

    // cout << x << " " << res[i] << endl;
  }

  sort(res, res + n);
  // for(int i = 0; i < n; i++) cout << res[i] << " ";
  // cout << endl;
  for(int i  = 1; i < n; i++) res[i] += res[i - 1];
  int q;
  cin >> q;
  // cout << k << endl;
  while(q--){
    cin >> t;
    int x = h + t * k;
    // cout << t << " " << h << endl;
    int l = 0, r = n - 1;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(res[mid] < x) l = mid;
      else r = mid - 1;
    }
    // cout << x << endl;
    // cout << l << " " << res[l] << " ";
    if(res[l] < x) cout << l + 1 << " ";
    else cout << 0 << " ";
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}