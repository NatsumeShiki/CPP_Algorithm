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
  int a1, b1, c1;
  int a2, b2, c2;
  bool operator < (const edge &t) const{
    if(a1 != t.a1) return a1 < t.a1;
    if(b1 != t.b1) return b1 < t.b1;
    if(c1 != t.c1) return c1 < t.c1;
    if(a2 != t.a2) return a2 < t.a2;
    if(b2 != t.b2) return b2 < t.b2;
    if(c2 != t.c2) return c2 < t.c2;
    return true;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
edge e[N];
map<edge, int> mp;
// map<PII, int> mp;

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    auto &[a1, b1, c1, a2, b2, c2] = e[i];
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    // cout << a1 << " " << b1 << " " << c1 << endl;
    // mp[{a1, a2}]++;
    // cout << mp[{a1, a2}] << endl;
    // cout << mp[{a1, b1, c1, a2, b1, c2}] << endl;
    mp[{a1, b1, c1, a2, b1, c2}]++;
    // cout << mp[{a1, b1, c1, a2, b1, c2}] << endl;
    mp[{a2, b1, c1, a2, b2, c2}]++;
    mp[{a1, b2, c1, a2, b2, c2}]++;
    mp[{a1, b1, c1, a1, b2, c2}]++;
    mp[{a1, b1, c1, a2, b2, c1}]++;
    mp[{a1, b1, c2, a2, b2, c2}]++;
  }

  for(int i = 0; i < n; i++){
    auto [a1, b1, c1, a2, b2, c2] = e[i];
    int res = 0;
    // res += mp[{a1, b1, c1, a2, b1, c2}];
    // res += mp[{a2, b1, c1, a2, b2, c2}];
    // res += mp[{a1, b2, c1, a2, b2, c2}];
    // res += mp[{a1, b1, c1, a1, b2, c2}];
    // res += mp[{a1, b1, c1, a2, b2, c1}];
    // res += mp[{a1, b1, c2, a2, b2, c2}];
    cout << res - 6 << endl;
  }
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
  while(T--){
    solve();
  }

  return 0;
}