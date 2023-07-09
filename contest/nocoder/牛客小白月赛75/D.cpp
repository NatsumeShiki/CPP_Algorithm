// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #include<set>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char g[N][N];
int f[N][N][2];
// int cnt[N][N];
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
bool st[N][N][2];

void solve(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) scanf("%s", g[i] + 1);

  memset(f, 0x3f, sizeof f);
  f[1][1][g[1][1] - '0'] = 0;

  priority_queue<PIIII, vector<PIIII>, greater<PIIII>> heap;
  heap.push({0, {g[1][1] - '0', {1, 1}}});

  while(heap.size()){
    auto t = heap.top();
    heap.pop();

    int x = t.y.y.x, y = t.y.y.y, d = t.x, w = t.y.x;
    // printf("%d %d %d %d\n", x, y, d, f[x][y][w]);
    if(f[x][y][w] != d) continue;
    if(x == n && y == m){
      printf("%d\n", d);
      return;
    }

    for(int i = 0; i < 4; i++){
      int a = x + dx[i], b = y + dy[i];
      if(a <= 0 || a > n || b <= 0 || b > m) continue;
      
      int td = d + 1 + (w == g[a][b] - '0');
      if(f[a][b][1 - w] > td){
        f[a][b][1 - w] = td;
        heap.push({td, {1 - w, {a, b}}});
      }
    }
  }

  printf("%d\n", min(f[n][m][0], f[n][m][1]));

  // int start;
  // if(g[1][1] == '1') start = 1;
  // else start = 0;

  // memset(cnt, 0x3f, sizeof cnt);
  // cnt[1][0] = cnt[0][1] = 0;
  // // for(int i = 0; i <= m; i++) cnt[0][i] = 0;
  // // for(int i = 0; i <= n; i++) cnt[i][0] = 0;
  // // cout << cnt[1][0] << " " << cnt[0][1] << endl;
  // for(int i = 1; i <= n; i++){
  //   int k;
  //   if(i % 2 == 1) k = start;
  //   else k = !start;
  //   for(int j = 1; j <= m; j++, k = !k){
  //     // cout << k << " " << g[i][j] << endl;
  //     if(g[i][j] - '0' != k) cnt[i][j] = 1;
  //     else cnt[i][j] = 0;
  //     // cout << min(cnt[i - 1][j], cnt[i][j - 1]) << " ";
  //     // cout << cnt[i][j] << " ";
  //     cnt[i][j] += min(cnt[i - 1][j], cnt[i][j - 1]);
  //     // cout << cnt[i][j] << " ";
  //     // cout << k << " ";
  //   }
  //   // cout << endl;
  // }
  // // cout << cnt[n][m] << endl;
  // cout << cnt[n][m] + n + m - 2 << endl;

  // memset(f, 0x3f, sizeof f);
  // if(g[1][1] == '1'){
  //   f[1][1][1] = 0;
  //   // f[1][1][0] = 1;
  // }else{
  //   // f[1][1][1] = 1;
  //   f[1][1][0] = 0;
  // }
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= m; j++){
  //     char c = g[i][j];
  //     // cout << c << " ";
  //     if(c == '1'){
  //       f[i][j][1] = min(f[i][j][1], min(f[i][j - 1][0] + 1, f[i - 1][j][0] + 1));
  //       f[i][j][0] = min(f[i][j][0], min(f[i][j - 1][1] + 2, f[i - 1][j][1] + 2));
  //       // f[i][j][1] = min(f[i][j][1], min(min(f[i - 1][j][0] + 1, f[i - 1][j][1] + 2), min(f[i][j - 1][0] + 1, f[i][j - 1][1] + 2)));
  //       // f[i][j][0] = min(f[i][j][0], min(min(f[i - 1][j][0] + 3, f[i - 1][j][1] + 2), min(f[i][j - 1][0] + 3, f[i][j - 1][1] + 2)));
  //     }else{
  //       f[i][j][0] = min(f[i][j][0], min(f[i][j - 1][1] + 1, f[i - 1][j][1] + 1));
  //       f[i][j][1] = min(f[i][j][1], min(f[i][j - 1][0] + 2, f[i - 1][j][0] + 2));
  //       // f[i][j][0] = min(f[i][j][0], min(min(f[i - 1][j][0] + 2, f[i - 1][j][1] + 1), min(f[i][j - 1][0] + 2, f[i][j - 1][1] + 1)));
  //       // f[i][j][1] = min(f[i][j][1], min(min(f[i - 1][j][0] + 2, f[i - 1][j][1] + 3), min(f[i][j - 1][0] + 2, f[i][j - 1][1] + 3)));
  //     }
  //   }
  //   // cout << endl;
  // }
  // printf("%d %d\n", f[1][2][0], f[1][2][1]);
  // printf("%d %d\n", f[1][3][0], f[1][3][1]);
  // printf("%d\n", min(f[n][m][0], f[n][m][1]));
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}