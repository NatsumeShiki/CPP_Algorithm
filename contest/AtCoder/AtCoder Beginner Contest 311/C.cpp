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
int h[N], e[M], ne[M], idx;
bool st[N];
int cnt[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int fa){
  cnt[u]++;
  if(cnt[u] > 10){
    return true;
  }
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(dfs(j, u)){
      if(cnt[u] > 5 && !st[u]) {
        st[u] = true;
        arr[m++] = u;
      }
      return true;
    }
  }
  cnt[u]--;
  return false;
}

void solve(){
  cin >> n;
  memset(h, -1, sizeof h);
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    add(i, x);
  }

  for(int i = 1; i <= n; i++){
    if(!st[i] && dfs(i, -1)){
      cout << m << endl;
      for(int i = m - 1; i >= 0; i--) cout << arr[i] << " ";
      return;
    }
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}