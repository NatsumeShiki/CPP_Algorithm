#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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
int last[N];
int cnt[N][2];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    last[i] = 0;
    cnt[i][0] = cnt[i][1] = 0;
  }
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    int len = i - last[x];
    last[x] = i;
    if(len > cnt[x][0]) cnt[x][1] = cnt[x][0], cnt[x][0] = len;
    else if(len > cnt[x][1]) cnt[x][1] = len;
  }
  for(int i = 1; i <= m; i++){
    int len = n + 1 - last[i];
    if(len > cnt[i][0]) cnt[i][1] = cnt[i][0], cnt[i][0] = len;
    else if(len > cnt[i][1]) cnt[i][1] = len;
    // cout << cnt[i][0] << " " << cnt[i][1] << endl;
  }

  int res = INF;
  for(int i = 1; i <= m; i++) {
    int ans = max((cnt[i][0] + 1) / 2, cnt[i][1]);
    res = min(res, ans);
  }
  cout << res - 1 << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}