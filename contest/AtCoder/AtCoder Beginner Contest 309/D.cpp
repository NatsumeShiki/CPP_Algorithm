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
int dist[M];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int u){
  dist[u] = 0;
  queue<int> q;
  q.push(u);
  int res = 0;
  while(q.size()){
    int t = q.front();
    q.pop();

    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      if(dist[j] > dist[t] + 1){
        dist[j] = dist[t] + 1;
        q.push(j);
        res = max(res, dist[j]);
      }
    }
  }

  return res;
}

void solve(){
  cin >> n >> m >> k;
  memset(h, -1, sizeof h);
  memset(dist, 0x3f, sizeof dist);
  while(k--){
    int a, b;
    cin >> a >> b;
    if(a == b) continue;
    add(a, b), add(b, a);
  }

  // cout << bfs(1) << endl;
  // cout << bfs(n + m ) << endl;
  cout << bfs(1) + bfs(n + m) + 1 << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}