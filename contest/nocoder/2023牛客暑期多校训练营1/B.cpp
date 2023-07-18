#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
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
int h[N], e[M], ne[M], idx;
bool st1[N];
bool st2[M];
bool st3[M];
int dist[N];
int res = 0;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
  memset(dist, 0x3f, sizeof dist);
  queue<PII> q;
  q.push({1, -1});
  st1[1] = true;
  dist[1] = 0;
  while(q.size()){
    auto t = q.front();
    q.pop();

    int u = t.x, fa = t.y;
    if(dist[u] > k) break;
    st1[u] = true;
    int cnt = 0;
    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(j == fa) continue;
      cnt++;
      if(st1[j]){
        int a = k - dist[u], b = k - dist[j];
        if(a < 0) a = 0;
        if(b < 0) b = 0;
        res = res + a + b;
        st2[i] = true;
        st2[i ^ 1] = true;
      }else if(dist[u] + 1 <= k && dist[u] + 1 < dist[j]){
        st2[i] = true;
        st2[i ^ 1] = true;
        q.push({j, u});
        dist[j] = dist[u] + 1;
      }
    }
    if(!cnt && u != 1) res += k - dist[u];
  }
}

// void bfs2(){
//   queue<PII> q;
//   q.push({1, -1});
//   while(q.size()){
//     auto t = q.front();
//     q.pop();

//     int u = t.x, fa = t.y;
//     for(int i = h[u]; ~i; i = ne[i]){
//       int j = e[i];
//       if(j == fa) continue;

//       if(!st3[i]) {
//         q.push({j, u});
//         st3[i] = true;
//       }
//       if(dist[u] >= k && dist[j] >= k) return;
//       if(!st2[i]){
//         int a = k - dist[u], b = k - dist[j];
//         if(a < 0) a = 0;
//         if(b < 0) b = 0;
//         res = res + a + b;
//         st2[i] = true;
//         st2[i ^ 1] = true;
//       }
//     }
//   }
// }

void solve(){
  cin >> n >> m >> k;
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  bfs();
  for(int i = 1; i <= n; i++) 
    if(dist[i] <= k)
      res++;
  // bfs2();
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}