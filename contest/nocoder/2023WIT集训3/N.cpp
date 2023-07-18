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
typedef pair<int, PIII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
char g[N][N];
int dist[N][N][2];

void dijkstra(){
  priority_queue<PIIII, vector<PIIII>, greater<PIIII>> heap;
  heap.push({0, {g[1][1] - '0', {1, 1}}});
  memset(dist, 0x3f, sizeof dist);
  dist[1][1][g[1][1] - '0'] = 0;

  while(heap.size()){
    auto t = heap.top();
    heap.pop();

    int x = t.y.y.x, y = t.y.y.y, dis = t.x, now = t.y.x;

    for(int i = 0; i < 4; i++){
      int a = x + dx[i], b = y + dy[i];
      if(a < 1 || a > n || b < 1 || b > m) continue;

      int td = dis + 1 + (now == g[a][b] - '0');
      if(dist[a][b][1 - now] > td){
        dist[a][b][1 - now] = td;
        heap.push({td, {1 - now, {a, b}}});
      }
    }
  }
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> g[i] + 1;

  dijkstra();

  cout << min(dist[n][m][0], dist[n][m][1]) << endl;
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