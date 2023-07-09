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

const int N = 15, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int g[N][N];
bool row[N][N], col[N][N], st[N][N][N];

void dfs(int x, int y){
  if(y == 10){
    x++, y = 1;
  }
  if(x == 10){
    for(int i = 1; i <= 9; i++){
      for(int j = 1; j <= 9; j++)
        cout << g[i][j] << " ";
      cout << endl;
    }
    exit(0);
  }

  if(g[x][y] != 0) dfs(x, y + 1);
  else{
    for(int i = 1;  i <= 9; i++){
      if(row[x][i] || col[y][i]) continue;
      int a = (x + 2) / 3, b = (y + 2) / 3;
      if(st[a][b][i]) continue;
      row[x][i] = col[y][i] = st[a][b][i] = true;
      g[x][y] = i;
      dfs(x, y + 1);
      row[x][i] = col[y][i] = st[a][b][i] = false;
      g[x][y] = 0;
    }
  }
}

void solve(){
  n = 9;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> g[i][j];
      row[i][g[i][j]] = true;
      col[j][g[i][j]] = true;
      int a = (i + 2) / 3, b = (j + 2) / 3;
      st[a][b][g[i][j]] = true;
    }
  }

  dfs(1, 1);
  
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