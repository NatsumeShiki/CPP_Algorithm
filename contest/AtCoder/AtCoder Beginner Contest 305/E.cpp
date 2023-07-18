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
bool st[N];
int cnt[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
  queue<PII> q;
  while(k--){
    int a, b;
    cin >> a >> b;
    q.push({a, -1});
    cnt[a] = max(cnt[a], b + 1);
    st[a] = true;
  }

  while(q.size()){
    auto t = q.front();
    q.pop();
    int u = t.x, fa = t.y;
    // cout <<  u<< endl;
    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(j == fa) continue;
      if(cnt[u] - 1 > cnt[j]){
        cnt[j] = cnt[u] - 1;
        st[j] = true;
        // if(!st2[j]) {
          q.push({j, u});
        // }  
      }
    }
  }
}

// void dfs(int u, int fa){
//   // cout << u << " " << cnt[u] << endl;
//   st[u] = true;
//   for(int i = h[u]; ~i; i = ne[i]){
//     int j = e[i];
//     if(j == fa) continue;

//     if(cnt[j] < cnt[u] - 1){
//       cnt[j] = cnt[u] - 1;
//       dfs(j, u);
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

  // while(k--){
  //   int a, b;
  //   cin >> a >> b;
  //   // cnt[a] = max(cnt[a], b + 1);
  //   st[a] = true;
  //   if(b + 1 > cnt[a]){
  //     cnt[a] = b + 1;
  //     dfs(a, -1);
  //   }
  // }

  int res = 0;
  for(int i = 1; i <= n; i++)
    if(st[i])
      res++;
  cout << res << endl;
  for(int i = 1; i <= n; i++)
    if(st[i]) 
      cout << i << " ";
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