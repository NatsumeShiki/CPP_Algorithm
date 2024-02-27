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
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    if(a != t.a) return a < t.a;
    return t.b < b;
  }

  bool operator > (const edge &t) const{
    if(a != t.a) return a > t.a;
    return t.b > b;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M], w[N], d[N];
bool st[N];
string s, str;
vector<int> res;

void dfs(int u){
  res.push_back(u);
  st[u] = true;
  if(--d[arr[u]] == 0){
    dfs(arr[u]);
  }
}

void solve(){
  cin >> n;
  res.clear();
  for(int i = 1; i <= n; i++) st[i] = false, d[i] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    d[arr[i]]++;
  }
  for(int i = 1; i <= n; i++) cin >> w[i];

  for(int i = 1; i <= n; i++){
    if(d[i] == 0 && !st[i]){
      dfs(i);
    }
  }

  for(int i = 1; i <= n; i++){
    if(st[i]) continue;

    vector<int> a, b;
    int j = i;
    while(true){
      if(st[j]) break;

      a.push_back(j);
      b.push_back(w[j]);
      st[j] = true;
      j = arr[j];
    }

    int p = min_element(b.begin(), b.end()) - b.begin();
    for(int j = 0; j < a.size(); j++){
      res.push_back(a[(j + 1 + p) % a.size()]);
      // res.push_back(12);
    }
  }

  for(int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
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