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
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 1e9 + 7;
int n, m, k, t, q;
int a[M], b[M], c[M];
string s, str;
int sz[M], fa[M];
bool st[M];

int find(int x){
  if(x != fa[x]) fa[x] = find(fa[x]);
  return fa[x]; 
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    st[i] = false;
    sz[i] = 0;
    fa[i] = i;
  }
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++){
    fa[find(a[i])] = find(b[i]);
  }
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
    st[find(c[i])] = true;
  }
  for(int i = 1; i <= n; i++) sz[find(i)]++;

  int res = 1;
  for(int i = 1; i <= n; i++){
    if(find(i) == i && (sz[i] >= 2 && !st[i]))
      res = res * 2 % mod;
  }
  cout << res << endl;
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