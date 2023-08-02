// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define x first
// #define y second
// #define endl "\n"
// #define FOR(n) for(int i = 0; i < n; i++) 
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<PII, int> PIII;
// typedef pair<PII, PII> PIIII;
// typedef pair<int, char> PIC;
// typedef pair<char, int> PCI;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 1e6 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
// int n, m, k, t;
// int arr[N];
// vector<int> alls;
// int h[N], e[M], ne[M], idx;
// int dist1[N], dist2[N];
// bool st[N];

// void add(int a, int b){
//   e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }

// void bfs(){
//   queue<int> q;
//   q.push(1);
//   dist1[1] = 0;
//   while(q.size()){
//     int t = q.front();
//     q.pop();
//     for(int i = h[t]; ~i; i = ne[i]){
//       int j = e[i];
//       if(dist1[j] > dist1[t] + 1){
//         dist1[j] = dist1[t] + 1;
//         q.push(j);
//       }
//     }
//   }
// }

// bool dfs(int u, int fa){
//   for(int i = h[u]; ~i; i = ne[i]){
//     int j = e[i];
//     if(st[j]) continue;
//     if(dist1[j] != dist1[u] + 1) return false;
//     st[j] = true;
//     if(!dfs(j, u)) return false;    
//     st[j] = false;
//   }
//   return true;
// }

// void solve(){
//   cin >> n >> m;
//   idx = 0;
//   for(int i = 1; i <= n; i++) h[i] = -1, dist1[i] = INF, st[i] = false;
//   while(m--){
//     int a, b;
//     cin >> a >> b;
//     add(a, b);
//   }

//   bfs();
//   dist2[1] = 0;
//   st[1] = true;
//   if(!dfs(1, -1)){
//     puts("No");
//   }else puts("Yes");
// } 

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   #endif
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int T = 1;
//   cin >> T;
//   while(T--){
//     solve();
//   }

//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 1e6 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int h[N], e[M], ne[M], idx;
int dist1[N], dist2[N];
bool st[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
  queue<int> q;
  q.push(1);
  dist1[1] = 0;
  while(q.size()){
    int t = q.front();
    q.pop();
    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      if(dist1[j] > dist1[t] + 1){
        dist1[j] = dist1[t] + 1;
        q.push(j);
      }
    }
  }
}

bool dfs(int u){
  if(dist1[u] != dist2[u]) return false;

  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(st[j]) continue;
    st[j] = true;
    dist2[j] = dist2[u] + 1;
    if(!dfs(j)) return false;    
    st[j] = false;
  }
  return true;
}

void solve(){
  cin >> n >> m;
  idx = 0;
  for(int i = 1; i <= n; i++) h[i] = -1, dist1[i] = INF, st[i] = false;
  while(m--){
    int a, b;
    cin >> a >> b;
    add(a, b);
  }

  bfs();
  dist2[1] = 0;
  st[1] = true;
  if(!dfs(1)){
    puts("No");
  }else puts("Yes");
} 

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}