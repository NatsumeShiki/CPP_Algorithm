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
map<int, int> a, b, c, d;

void solve(){
  cin >> n;
  a.clear();
  b.clear();
  c.clear();
  d.clear();
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    a[x]++, b[y]++;
    c[y - x]++, d[y + x]++;
  }

  int res = 0;
  for(auto item : a) res += item.second * (item.second - 1);
  for(auto item : b) res += item.second * (item.second - 1);
  for(auto item : c) res += item.second * (item.second - 1);
  for(auto item : d) res += item.second * (item.second - 1);
  cout << res << endl;
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