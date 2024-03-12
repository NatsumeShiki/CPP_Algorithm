// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define x first
// #define y second
// #define endl "\n"
// #define all(a) a.begin(), a.end()
// #define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
// #define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
// #define pep(i,a,b) for(int i = int(a);i < int(b);++i)
// #define per(i,a,b) for(int i = int(b);i > int(b);--i);
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<PII, int> PIII;
// typedef pair<PII, PII> PIIII;
// typedef pair<string, int> PSI;
// typedef pair<int, string> PIS;
// typedef pair<int, char> PIC;
// typedef pair<char, int> PCI;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
// int n, m, k, t, q;
// int arr[M];
// string s, str;
// int a, b;
// int h[N], e[M], ne[M], idx;
// int cnt[N];

// void add(int a, int b){
//   e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }

// int dfs1(int u, int fa){
//   cnt[u]++;
//   if(cnt[u] > 1){
//     return u;
//   }

//   for(int i = h[u]; ~i; i = ne[i]){
//     int j = e[i];
//     if(j == fa) continue;
//     int t = dfs1(j, u);
//     if(t != -1) return t;
//   }
//   return -1;
// }

// int bfs2(int a, int b, int target, int &x, int &y){
//   if(a == target) x = 0;
//   else if(b == target) y = 0;
//   queue<PIII> q;
//   q.push({{a, -1}, 0});
//   q.push({{b, -1}, 0});
//   while(q.size()){
//     auto [a, b] = q.front();
//     q.pop();
//     // cout << a.first << endl;
//     for(int i = h[a.first]; ~i; i = ne[i]){
//       int j = e[i];
//       if(j == a.second) continue;
//       q.push({{j, a.second}, b + 1});
//       if(j == target) return b + 1;
//     }
//   }
// }

// void solve(){
//   cin >> n >> a >> b; 
//   idx = 0;
//   for(int i = 1; i <= n; i++) {
//     h[i] = -1;
//     cnt[i] = 0;
//   }
//   for(int i = 0; i < n; i++){
//     int a, b;
//     cin >> a >> b;
//     add(a, b), add(b, a);
//   }

//   if(a == b) {
//     cout << "No\n";
//     return;
//   }

//   int u = dfs1(b, -1);
//   // cout << u << endl;
//   int x = -1, y = -1;
//   bfs2(a, b, u, x, y);

//   if(x <= y) cout << "No\n";
//   else cout << "Yes\n";
  
// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   #endif
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

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
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int a, b;
int h[N], e[M], ne[M], idx;
int cnt[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs1(int u, int fa){
  cnt[u]++;
  if(cnt[u] > 1){
    return u;
  }

  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(j == fa) continue;
    int t = dfs1(j, u);
    if(t != -1) return t;
  }
  return -1;
}

int bfs2(int u, int target){
  if(u == target) return 0;
  queue<PIII> q;
  q.push({{u, -1}, 0});
  while(q.size()){
    auto [a, b] = q.front();
    q.pop();
    // cout << a.first << endl;
    for(int i = h[a.first]; ~i; i = ne[i]){
      int j = e[i];
      if(j == a.second) continue;
      q.push({{j, a.first}, b + 1});
      if(j == target) return b + 1;
    }
  }
}

void solve(){
  cin >> n >> a >> b; 
  for(int i = 1; i <= n; i++) {
    h[i] = -1;
    cnt[i] = 0;
  }
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  if(a == b) {
    cout << "No\n";
    return;
  }

  int u = dfs1(b, -1);
  // cout << u << endl;
  int x = bfs2(a, u), y = bfs2(b, u);

  if(x <= y) cout << "No\n";
  else cout << "Yes\n";
  
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}