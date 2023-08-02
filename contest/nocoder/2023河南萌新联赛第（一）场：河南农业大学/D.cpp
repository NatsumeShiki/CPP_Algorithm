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
typedef pair<int, PII> PIII;
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

const int N = 1e4 + 10, M = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int h[N], e[M], w[M], ne[M], idx;
int cnt[N];
int start, ed, hp;
int ans = INF;
bool st[N];
int dist[N];

void add(int a, int b, int c){
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool bfs(int mid){
  if(cnt[start] > mid) return false;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  memset(dist, 0x3f, sizeof dist);
  memset(st, 0, sizeof st);
  q.push({0, start});
  dist[start] = 0;
  while(q.size()){
    auto t = q.top();
    q.pop();
    int u = t.y, dis = t.x;
    if(st[u]) continue;
    st[u] = true; 
    if(u == ed) return true;
    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(cnt[j] > mid) continue;
      if(dis + w[i] > hp) continue;
      if(dist[j] > dis + w[i]){
        dist[j] = dis + w[i];
        q.push({dist[j], j});
      }
    }
  }
  return false;
}

void solve(){
  cin >> n >> m >> start >> ed >> hp;
  for(int i = 1; i <= n; i++) cin >> cnt[i];
  memset(h, -1, sizeof h);
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c), add(b, a, c);
  }

  int l = 1, r = 1e7;
  while(l < r){
    int mid = l + r >> 1;
    if(bfs(mid)) r = mid;
    else l = mid + 1; 
  }
  if(bfs(l)) cout << l << endl;
  else puts("-1");
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