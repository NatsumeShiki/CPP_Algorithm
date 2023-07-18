#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 53000, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int d[N], dist[50][50], w[30];
int u[30], v[30];
int p[50], sz;

int get(int a, int b){
  if(a > b) swap(a, b);
  int res = d[b - 1] - d[a - 1];
  return min(res, d[n] - res);
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> d[i];
    d[i] += d[i - 1];
  }

  for(int i = 0; i < m; i++){
    cin >> u[i] >> v[i] >> w[i];
    p[sz++] = u[i];
    p[sz++] = v[i]; 
  }

  sort(p, p + sz);
  sz = unique(p, p + sz) - p;
  memset(dist, 0x3f, sizeof dist);
  for(int i = 0; i < m; i++){
    int a = lower_bound(p, p + sz, u[i]) - p;
    int b = lower_bound(p, p + sz, v[i]) - p;
    dist[a][b] = dist[b][a]  = min(dist[a][b], w[i]);
  }

  for(int i = 0; i < sz; i++)
    for(int j = 0; j < sz; j++)
      dist[i][j] = min(dist[i][j], get(p[i], p[j]));

  for(int k = 0; k < sz; k++)
    for(int i = 0; i < sz; i++)
      for(int j = 0; j < sz; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  cin >> k;
  while(k--){
    int a, b;
    cin >> a >> b;
    int res = get(a, b);
    for(int i = 0; i < sz; i++)
      for(int j = 0; j < sz; j++){
        res = min(res, dist[i][j] + get(p[i], a) + get(p[j], b));
        res = min(res, dist[i][j] + get(p[i], b) + get(p[j], a));
      }
    cout << res << endl;
  }
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