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
typedef pair<PIII, vector<int>> PIIIV;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
int h[M], e[M], ne[M], w1[N], w2[M], idx;
int start = -1, cnt = INF; 
bool st[M];
int dist[M], res[M];
vector<vector<int>> ve(N);

void add(int a, int b, int c, int d){
  e[idx] = b, w1[idx] = c, w2[idx] = d, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u){
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({u, 0});
  // memset(dist, 0x3f, sizeof dist);
  for(int i = 1; i <= n; i++) dist[i] = INF;
  dist[u] = 0;

  while(q.size()){
    auto t = q.top();
    q.pop();

    int u = t.x, dis = t.y;
    // cout << u << " " << dis << endl;
    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(dis + w1[i] < dist[j]){
        dist[j] = dis + w1[i];
        q.push({j, dist[j]});
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
  // cout << ans << endl;
  if(cnt > ans){
    cnt = ans;
    start = u;
  }
}

void bfs2(){
  // queue<PIIIV> q;
  priority_queue<PIIIV, vector<PIIIV>, greater<PIIIV>> q;
  vector<int> v;
  v.push_back(start);
  q.push({{{start, 0}, 0}, v});
  // memset(dist, 0x3f, sizeof dist);
  for(int i = 1; i <= n; i++) dist[i] = INF;
  dist[start] = 0;
  ve[start] = v;

  while(q.size()){
    auto t = q.top();
    q.pop();

    int u = t.x.x.x, dis = t.x.x.y;
    int cnt = t.x.y;
    vector<int> k = t.y;
    // vector<int> k;
    // for(auto a : k) k.push_back(a);
    // cout << u << " " << dis << endl;
    // cout << u << " " << dis << " " << cnt << " ";
    // for(auto a : k) cout << a << " ";
    // cout << endl;
    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(dis + w1[i] < dist[j]){
        dist[j] = dis + w1[i];
        res[j] = cnt + w2[i];
        k.push_back(j);
        ve[j] = k;
        q.push({{{j, dist[j]}, res[j]}, k});
        k.pop_back();
      }else if(dis + w1[i] == dist[j] && cnt + w2[i] > res[j]){
        res[j] = cnt + w2[i];
        k.push_back(j);
        ve[j] = k;
        q.push({{{j, dist[j]}, res[j]}, k});
        k.pop_back();
      }
    }
  }
}

void solve(){
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while(m--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    add(a, b, c, d), add(b, a, c, d);
  }

  for(int i = 1; i <= n; i++){
    bfs(i);
  }

  cout << start << endl;
  cin >> q;
  bfs2();
  while(q--){
    int x;
    cin >> x;
    t = ve[x].size();
    for(int i = 0; i < t; i++){
      if(i != t - 1) cout << ve[x][i] << "->";
      else cout << ve[x][i];
    }
    cout << endl;
    cout << dist[x] << " " << res[x] << endl;
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