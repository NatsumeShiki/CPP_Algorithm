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
int arr[M];
vector<int> alls;
int f[M];

void solve(){
  cin >> n >> m;
  deque<PII> dq;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    while(dq.size() && i - dq.front().y >= m) dq.pop_front();
    while(dq.size() && dq.back().x >= x) dq.pop_back();
    dq.push_back({x, i});
    if(i >= m) f[i] = max(f[i - 1], f[i - m] + dq.front().x);
  }
  cout << f[n] << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}