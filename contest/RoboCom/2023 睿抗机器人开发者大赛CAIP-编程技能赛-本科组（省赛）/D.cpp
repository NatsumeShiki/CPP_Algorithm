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
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
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
int n, m, k, t, q;
int arr[M];
vector<int> alls;
PSI psi[N];
map<PSI, int> mp1;
map<int, PSI> mp2;
int cnt;
int h[N], e[N], ne[N], idx;
vector<PSI> res;
bool st[N];
vector<PSI> ans(N);

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(string a, int c, string b, int d, int u){
  // cout << b << " " << d << endl;
  if(a == b && c != d) {
    if(res.size() < ans.size()) ans = res;
    return;
  }
  if(b != "") res.push_back({b, d});
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(st[j]) continue;
    st[j] = true;
    auto [x, y] = mp2[j];
    res.push_back({x, y});
    dfs(a, c, x, y, j);
    res.pop_back();
    st[j] = false;
  }
  if(b != "") res.pop_back();
}

void solve(){
  cin >> n;
  memset(h, -1, sizeof h);
  for(int i = 0; i < n; i++){
    string a, b;
    int c, d;
    cin >> a >> c >> b >> d;
    if(!mp1[{a, c}]) {
      mp1[{a, c}] = cnt;
      mp2[cnt] = {a, c};
      cnt++;
    }
    if(!mp1[{b, d}]) {
      mp1[{b, d}] = cnt;
      mp2[cnt++] = {b, d};
    }
    int x = mp1[{a, c}], y = mp1[{b, d}];
    // cout << a << " " << c << " " << b << " " << d << endl;
    // cout << x << " " << y << endl;
    add(x, y);
  }
  // cout << 123 << endl;
  // exit(0);

  for(auto [a, b] : mp1){
    // cout << a.first << " " << a.second << " " << b << endl;
    // if(a.second == 1) continue;
      // exit(0);
      res.push_back({a.first, a.second});
      st[b] = true;
      dfs(a.first, a.second, "", -1, b);
      res.pop_back();
      st[b] = false;
    // }
    // exit(0);
  }
  for(auto [a, b] : ans)
    cout << a << " " << b << " ";
  cout << "= " << ans[0].first << " " << ans[0].second << " " << ans[ans.size() - 1].first << " " << ans[ans.size() - 1].second;
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