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
int n, m, k, p;
int arr[N];
int h[N], e[M], w[N], ne[M], idx;
int dist[N], res[N];
int st, ed;
int ans = 0;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
  memset(dist, 0x3f, sizeof dist);
  dist[st] = 1;
  p %= k;
  queue<int> q;
  q.push(st);
  if(dist[st] % k == p) res[st] = w[st];
  
  // cout << p << " " << res[st] << endl;

  while(q.size()){
    int t = q.front();
    q.pop();
    // if(dist[st] % k == p) res[st] = w[st];

      // cout << t << " " << res[t] << endl;
    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      // cout << j << endl;
      if(dist[j] > dist[t] + 1){
        dist[j] = dist[t] + 1;
        res[j] = res[t];
        if(dist[j] % k == p) {
          res[j] += w[j];
        }
        q.push(j);
      }else if(dist[j] == dist[t] + 1){
        // if(dist[j] )
        if(res[t] > res[j]) res[j] = res[t];
        if(dist[j] % k == p && res[t] + w[j] > res[j]){
          res[j] = res[t] + w[j];
        } 
        q.push(j);
      }
    }
  }
}

void solve(){
  cin >> n >> m >> k >> p;
  for(int i = 1; i <= n; i++) cin >> w[i];
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  cin >> st >> ed;
  bfs();

  cout << res[ed] << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}