#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 3010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
char v[N][N];
int cnt[N][N];
int dist[N][N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> v[i];

  cin >> t;
  while(t--){
    int a, b, c;
    cin >> a >> b >> c;
    cnt[a - 1][b - 1] = c;
  }
  priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
  heap.push({0, {0, 0}});
  memset(dist, 0x3f, sizeof dist);
  dist[0][0] = 0;
  while(heap.size()){
    auto t = heap.top();
    heap.pop();

    int dis = t.x, x = t.y.x, y = t.y.y;
    // cout << x << " " << y << endl;
    if(x == n - 1 && y == m - 1) {
      cout << dis << endl;
      return;
    }
    if(v[x][y] == '*'){
      int k = cnt[x][y];
      int dx[4] = {-k, 0, k, 0}, dy[4] = {0, k, 0, -k};
      for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(v[a][b] == '#' || dist[a][b] <= dist[x][y]) continue;
        // cout << a << " " << b << endl;
        dist[a][b] = dist[x][y];
        heap.push({dis, {a, b}});
      }
    }else{
      for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(v[a][b] == '#' || dist[a][b] <= dist[x][y] + 1) continue;
        dist[a][b] = dist[x][y] + 1;
        heap.push({dis + 1, {a, b}});
      }
    }
  }
  puts("-1");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}