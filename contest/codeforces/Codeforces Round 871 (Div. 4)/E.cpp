#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010;
int g[N][N];
bool st[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(int x, int y){
  queue<PII> q;
  q.push({x, y});
  st[x][y] = true;
  int res = g[x][y];
  while(q.size()){
    PII t = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int a = t.x + dx[i], b = t.y + dy[i];
      if(a < 0 || a >= n || b < 0 || b >= m) continue;
      if(st[a][b] || !g[a][b]) continue;
      st[a][b] = true;
      q.push({a, b});
      res += g[a][b];
    }
  }
  return res;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> g[i][j];

    memset(st, 0, sizeof st);
    int res = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(g[i][j] && !st[i][j])
          res = max(res, bfs(i, j));
    cout << res << endl;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}