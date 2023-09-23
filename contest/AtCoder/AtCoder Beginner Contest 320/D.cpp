#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
bool st[N];
bool flag[N];
PII res[N];

void solve(){
  cin >> n >> m;
  res[1] = {0, 0};
  vector<vector<PIII>> ve(n + 1);
  while(m--){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    ve[a].push_back({b, {x, y}});
    ve[b].push_back({a, {-x, -y}});
  }

  queue<int> q;
  q.push(1);
  st[1] = true;

  while(q.size()){
    int t = q.front();
    q.pop();
    // cout <<t << ve[t].size() << endl;
    for(auto [a, b] : ve[t]){
      if(!st[a]){
        q.push(a);
        st[a] = true;
        res[a] = {res[t].first + b.first, res[t].second + b.second};
      }
      if(res[a].first != res[t].first + b.first || res[a].second != res[t].second + b.second) flag[a] = true;
    }
  }

  for(int i = 1; i <= n; i++){
    if(flag[i] || !st[i]) cout << "undecidable" << endl;
    else cout << res[i].first << " " << res[i].second << endl;
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