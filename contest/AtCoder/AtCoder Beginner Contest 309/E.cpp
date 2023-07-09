#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int h[M], e[M], ne[M], idx;
int cnt[M];
bool st[M];

void dfs(int u, int k){
  if(k) {
    st[u] = true;
    k--;
  }
  // cout << u << " " << k << endl;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    dfs(j, max(cnt[j], k));
  }
}

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve(){
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for(int i = 2; i <= n; i++){
    int a;
    cin >> a;
    add(a, i);
  }

  while(m--){
    int a, b;
    cin >> a >> b;
    cnt[a] = max(cnt[a], b + 1);
  }

  dfs(1, cnt[1]);
  int res = 0;
  for(int i = 1; i <= n; i++){
    if(st[i])
      res++;

    // cout << st[i] << " ";
  }

  // cout << endl;
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}