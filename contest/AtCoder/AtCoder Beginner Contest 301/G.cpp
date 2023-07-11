#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int x, y, r;
  bool operator < (const edge &t) const{
    return r < t.r;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 3010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
edge Edge[M];
int sx, sy, ex, ey;
vector<int> alls;
int p[M];

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}

int get(int x, int y, int sx, int sy){
  x -= sx;
  y -= sy;
  return x * x + y * y;
}

void solve(){
  cin >> n;
  cin >> sx >> sy >> ex >> ey;
  int res1 = 0, res2 = 0;
  for(int i = 0; i < n; i++){
    int a, b, r;
    cin >> a >> b >> r;
    Edge[i] = {a, b, r};
    p[i] = i;

    if(get(a, b, sx, sy) == r * r) res1 = i;
    if(get(a, b, ex, ey) == r * r) res2 = i;
  }
  // cout << res1 << endl << res2 << endl;

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++){
      edge a = Edge[i], b = Edge[j];
      int dis = get(a.x, a.y, b.x, b.y);
      int r1 = a.r, r2 = b.r;
      if(dis < (r1 - r2) * (r1 - r2) || dis > (r1 + r2) * (r1 + r2)) continue;
      // if(dis <= (a.r + b.r) * (a.r + b.r) && dis >= (a.r - b.r) * (a.r - b.r)){
        int pa = find(i), pb = find(j);
        if(pa == pb) continue;
        p[pa] = pb;        
      // }
    }

  
  if(find(res1) == find(res2)) puts("Yes");
  else puts("No");
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