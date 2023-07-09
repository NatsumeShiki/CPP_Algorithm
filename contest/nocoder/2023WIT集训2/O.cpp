#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 510, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char g[N][N];
int sx, sy, ex, ey;
bool st[N][N][2];
int dist[N][N][2];

bool bfs(){
  memset(st, 0, sizeof st);
  memset(dist, 0, sizeof dist);
  queue<PIII> q;
  q.push({0, {sx, sy}});

  st[sx][sy][0] = true;
  dist[sx][sy][0] = 0;

  while(q.size()){
    auto t = q.front();
    q.pop();
    int k = t.x, x = t.y.x, y = t.y.y;

    // cout << x << " " << y << " " << k << " " << dist[x][y][k] << endl;

    for(int i = 0; i < 4; i++){
      int a = x + dx[i], b = y + dy[i];
      if(a < 0 || a >= n || b < 0 || b >= m) continue;
      if(st[a][b][k] || g[a][b] == '#') continue;
      if(g[a][b] == 'E' && k == 0) continue;
      // if(g[a][b] == 'K') k = 1;
      if(g[a][b] == 'K'){
        st[a][b][1] = true;
        dist[a][b][1] = dist[x][y][t.x] + 1;
        q.push({1, {a, b}});
      }else{
        st[a][b][k] = true;
        dist[a][b][k] = dist[x][y][t.x] + 1;
        q.push({k, {a, b}});
      }
      if(g[a][b] == 'E' && k == 1) {
        return true;
      }
    }
  }
  return false;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(g[i][j] == 'P') sx = i, sy = j;
      else if(g[i][j] == 'E') ex = i, ey = j;

  if(bfs()) cout << dist[ex][ey][1] << endl;
  else puts("No solution");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}