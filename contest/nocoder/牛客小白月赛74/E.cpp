#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int h[N], a[N];

void solve(){
  cin >> n >> m >> k >> t;
  m--;
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    int cnt = (k - h[i]) / a[i] + 1;
    // cout << cnt << endl;
    if(cnt >= m){
      h[i] += m * a[i];
      if(h[i] > k) h[i] = t;
      continue;
    }

    cnt = m - cnt;
    int x = (k - t) / a[i] + 1;
    cnt %= x;

    h[i] = t + cnt * a[i];
  }

  for(int i = 0; i < n; i++) cout << h[i] << " \n?"[i == n - 1];
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}