#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
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

const int N = 55, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N][N];
int l[N], r[N];
bool flag[N][N];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++) 
      cin >> a[i][j];
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++){
        int x = a[i][j - 1], y = a[i][j + 1], z = a[i][j];
        // printf("%d %d %d\n", z, x, y);
        flag[z][x] = flag[z][y] = true;
        flag[x][z] = flag[y][z] = true;
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(i != j && !flag[i][j]){
          res++;
          // cout << i << " " << j << endl;
        }
    cout << res / 2 << endl;
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