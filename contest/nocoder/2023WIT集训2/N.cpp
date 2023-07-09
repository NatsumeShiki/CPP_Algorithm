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
bool st[N][N];

bool bfs(){
  memset(st, 0, sizeof st);
  queue<PII> q;
  st[sx][sy] = true;
  q.push({sx, sy});

  while(q.size()){
    auto t = q.front();
    q.pop();
    // cout << t.x << " " << t.y << endl;
    if(t.x == ex && t.y == ey) return true;
    for(int i = 0; i < 4; i++){
      int a = t.x + dx[i], b = t.y + dy[i];
      if(a < 0 || a >= n || b < 0 || b >= m) continue;
      if(st[a][b] || g[a][b] == 'x') continue;
      // cout << g[a][b] << endl;
      st[a][b] = true;
      q.push({a, b});
    }
  }
  return false;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      if(g[i][j] == 's') sx = i, sy = j;
      else if(g[i][j] == 't') ex = i, ey = j;
  }

  if(bfs()) puts("YES");
  else puts("NO");
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