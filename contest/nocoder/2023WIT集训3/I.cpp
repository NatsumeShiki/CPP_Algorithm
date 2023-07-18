#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int dist[510][510];
// int h[N], e[M], w[M],  ne[M], idx;
// vector<int> alls;
// int dist[N];

// void add(int a, int b, int c){
//   e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
// }

// void bfs(){
//   memset(dist, 0x3f, sizeof dist);
//   priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
//   for(auto item : alls)
//     heap.push({0, {1, item}});
//   dist[1] = 0;
//   while(heap.size()){
//     auto t = heap.top();
//     heap.pop();

//     int u = t.y.x, now = t.y.y, cnt = t.x;
//     if(u == n) return;
//     // cout << u << " " << now << " " << cnt << endl;
//     for(int i = h[u]; ~i; i = ne[i]){
//       int j = e[i];
//       if(w[i] == now){
//         if(dist[j] > cnt) {
//           dist[j] = cnt;
//           heap.push({cnt, {j, now}});
//         }
//       }else {
//         if(dist[j] > cnt + 1) {
//           dist[j] = cnt + 1;
//           heap.push({cnt + 1, {j, w[i]}});
//         }
//       }
//     }
//   }
// }

void solve(){
  cin >> m >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(i == j) dist[i][j] = 0;
      else dist[i][j] = INF;
  // memset(h, -1, sizeof h);
  string s;
  getline(cin, s);
  for(int i = 0; i < m; i++){
    getline(cin, s);
    istringstream iss;
    iss.str(s);
    int x;
    int k = 0;
    while(iss >> x) {
      arr[++k] =  x;
      // add(st, x, i + 1);
      // st = x;
    }
    for(int i = 1; i <  k; i++)
      for(int j = i + 1; j <= k; j++)
        dist[arr[i]][arr[j]] = 1;

  }

  // bfs();
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  if(dist[1][n] == INF) puts("NO");
  else cout << dist[1][n] - 1 << endl;
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